import pandas as pd
import plotly.graph_objects as go
from plotly.subplots import make_subplots
import time

# Read your CSV data (initially empty or with existing data)
df = pd.read_csv("Team-Astropeep-Data.txt")

# Create a figure with subplots (adjust number of rows/cols based on your data)
fig = make_subplots(rows=4, cols=3, 
                    subplot_titles=("Altitude", "Pressure", "Temperature", "Voltage", "GPS Altitude", "GPS Latitude", "GPS Longitude", "Accelerometer X", "Accelerometer Y", "Accelerometer Z", "Gyro X", "Gyro Y"))

# Add initial traces (empty if starting with an empty CSV)
for col in df.columns[3:]:  # Start from the 4th column (assuming first 3 are metadata)
    fig.add_trace(go.Scatter(x=df['TimeStamp'], y=df[col], mode='lines', name=col),
                  row=(df.columns.get_loc(col) - 2) // 3 + 1,  # Calculate row based on column index
                  col=(df.columns.get_loc(col) - 2) % 3 + 1)   # Calculate column based on column index

# Update layout for better visualization
fig.update_layout(height=1000, width=1500, title_text="Real-time Sensor Data", showlegend=True)
fig.update_xaxes(title_text="Time")
fig.update_yaxes(title_text="Value")

# Show the plot
fig.show()

# Function to update the plot with new data
def update_plot(new_data):
    global df  # Use the global dataframe

    # Append new_data to your dataframe
    df = pd.concat([df, new_data], ignore_index=True)

    # Update the traces in the figure with the new data
    for i, col in enumerate(df.columns[3:]):
        fig.update_traces(x=df['TimeStamp'], y=df[col], selector=dict(name=col))

    fig.show()

# In your main loop, as you receive new CSV data:
while True: 
    # Simulate receiving new data (replace with your actual data acquisition)
    new_data = pd.DataFrame({
        'Team_Id': ['2022ASI-002'],
        'TimeStamp': [time.strftime('%Y-%m-%d %H:%M:%S')],
        'PacketCount': [PacketCount],  # Replace with your actual PacketCount
        'Altitude': [getAltitude()],
        'Pressure': [getPressure()],
        # ... Add other sensor data here
    })

    # Update the plot
    update_plot(new_data)

    time.sleep(1)  # Adjust the delay based on your data acquisition rate