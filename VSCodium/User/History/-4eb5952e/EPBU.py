import pandas as pd
import plotly.graph_objects as go
from plotly.subplots import make_subplots
import time

# Read your CSV data 
df = pd.read_csv("data.csv")

# Create a figure with subplots, adjusted for the provided data
fig = make_subplots(rows=5, cols=3, 
                    subplot_titles=("Altitude", "Pressure", "Temperature", 
                                    "Voltage", "GpsTime", "GpsLatitude", 
                                    "GpsLongitude", "GpsAltitude", "GpsSats",
                                    "a_x", "a_y", "a_z", 
                                    "gyro_x", "gyro_y", "gyro_z",
                                    "FSW_State", "AngleX", "AngleY", "AngleZ"))

# Add initial traces 
for col in df.columns[3:]:  # Start from the 4th column
    fig.add_trace(go.Scatter(x=df['TimeStamp'], y=df[col], mode='lines', name=col),
                  row=(df.columns.get_loc(col) - 2) // 3 + 1, 
                  col=(df.columns.get_loc(col) - 2) % 3 + 1)

# Update layout for better visualization
fig.update_layout(height=1200, width=1500, title_text="Real-time Sensor Data", showlegend=True)
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

# In your main loop, as you receive new CSV data:
while True: 
    # Simulate receiving new data (replace with your actual data acquisition)
    new_data = pd.DataFrame({
        'Team_Id': ['2022ASI-002'],
        'TimeStamp': [time.strftime('%Y-%m-%d %H:%M:%S')],
        'PacketCount': [PacketCount], 
        'Altitude': [getAltitude()],
        'Pressure': [getPressure()],
        # ... Add other sensor data here, matching the column names in your CSV
    })

    # Update the plot
    update_plot(new_data)

    time.sleep(1)