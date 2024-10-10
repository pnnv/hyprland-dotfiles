import pandas as pd
import plotly.graph_objects as go
from plotly.subplots import make_subplots
import time
import os

# Read your initial CSV data
df = pd.read_csv("data.csv")

# Get the number of data columns (excluding the first 3 metadata columns)
num_data_columns = len(df.columns) - 3

# Calculate the required number of rows for the subplot grid
num_rows = (num_data_columns + 2) // 3  # Ceil division to ensure enough rows

# Create a figure with subplots, adjusted for the number of data columns
fig = make_subplots(rows=num_rows, cols=3,
                    subplot_titles=tuple(df.columns[3:]))  # Use column names as subplot titles

# Add initial traces
for i, col in enumerate(df.columns[3:]):  # Start from the 4th column
    fig.add_trace(go.Scatter(x=df['TimeStamp'], y=df[col], mode='lines', name=col),
                  row=i // 3 + 1,  # Calculate row based on column index
                  col=i % 3 + 1)  # Calculate column based on column index

# Update layout for better visualization
fig.update_layout(height=300 * num_rows, width=1500, title_text="Real-time Sensor Data", showlegend=True)
fig.update_xaxes(title_text="Time")
fig.update_yaxes(title_text="Value")

# Show the plot only once at the beginning
fig.show()

# Store the initial modification time of the file
last_modified_time = os.path.getmtime("data.csv")

# Function to update the plot with new data
def update_plot():
    global df, last_modified_time

    # Check if the file has been modified
    current_modified_time = os.path.getmtime("data.csv")
    if current_modified_time <= last_modified_time:
        return  # No changes, do nothing

    last_modified_time = current_modified_time

    # Read the updated CSV file
    updated_df = pd.read_csv("data.csv")

    # Get new rows (difference between updated_df and df)
    new_data = updated_df[len(df):]

    # Append new_data to your dataframe
    df = pd.concat([df, new_data], ignore_index=True)

    # Update the traces in the figure with the new data
    for i, col in enumerate(df.columns[3:]):
        fig.data[i].x = df['TimeStamp'].tolist()
        fig.data[i].y = df[col].tolist()

# In your main loop, periodically check for file changes
while True:
    update_plot()
    time.sleep(1)  # Adjust the delay as needed