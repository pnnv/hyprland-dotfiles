import pandas as pd
import random
import plotly.graph_objects as go
from plotly.subplots import make_subplots
import time

# Read your CSV data 
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
                  col=i % 3 + 1)   # Calculate column based on column index

# Update layout for better visualization
fig.update_layout(height=300 * num_rows, width=1500, title_text="Real-time Sensor Data", showlegend=True)
fig.update_xaxes(title_text="Time")
fig.update_yaxes(title_text="Value")

# Show the plot
fig.show()

# Function to update the plot with new data
def update_plot(new_data):
    global df 

    # Append new_data to your dataframe
    df = pd.concat([df, new_data], ignore_index=True)

    # Update the traces in the figure with the new data
    for i, col in enumerate(df.columns[3:]):
        fig.update_traces(x=df['TimeStamp'], y=df[col], selector=dict(name=col))

    fig.show()

# Initialize PacketCount
PacketCount = 0

# In your main loop, as you receive new CSV data:
while True: 
    # Simulate receiving new data (replace with your actual data acquisition)
    new_data = pd.DataFrame({
        'Team_Id': ['2022ASI-002'],
        'TimeStamp': [time.strftime('%Y-%m-%d %H:%M:%S')],
        'PacketCount': [PacketCount], 
        'Altitude': [random.uniform(0, 1000)],  # Replace with actual data
        'Pressure': [random.uniform(950, 1013.25)],  # Replace with actual data
        # ... Add other sensor data here, matching the column names in your CSV
    })

    # Update the plot
    update_plot(new_data)

    # Increment PacketCount
    PacketCount += 1

    time.sleep(1)