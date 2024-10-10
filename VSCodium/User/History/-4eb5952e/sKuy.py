import pandas as pd
import matplotlib.pyplot as plt
import matplotlib.animation as animation
from matplotlib.gridspec import GridSpec

# CSV file path
csv_file_path = 'data.csv'

# Initialize figure and subplots
fig = plt.figure(figsize=(12, 8))
gs = GridSpec(nrows=5, ncols=5, figure=fig)

# Create subplots for each parameter
ax1 = fig.add_subplot(gs[0, :])  # Altitude
ax2 = fig.add_subplot(gs[1, :])  # Pressure
ax3 = fig.add_subplot(gs[2, :])  # Temperature
ax4 = fig.add_subplot(gs[3, :])  # Voltage
ax5 = fig.add_subplot(gs[4, :2])  # GPS Altitude
ax6 = fig.add_subplot(gs[4, 2:])  # GPS Sats

# Set titles
ax1.set_title('Altitude vs Time')
ax2.set_title('Pressure vs Time')
ax3.set_title('Temperature vs Time')
ax4.set_title('Voltage vs Time')
ax5.set_title('GPS Altitude vs Time')
ax6.set_title('GPS Sats vs Time')

# Set labels
ax1.set_xlabel('Time')
ax1.set_ylabel('Altitude')
ax2.set_xlabel('Time')
ax2.set_ylabel('Pressure')
ax3.set_xlabel('Time')
ax3.set_ylabel('Temperature')
ax4.set_xlabel('Time')
ax4.set_ylabel('Voltage')
ax5.set_xlabel('Time')
ax5.set_ylabel('GPS Altitude')
ax6.set_xlabel('Time')
ax6.set_ylabel('GPS Sats')

# Initialize lines for plotting
line1, = ax1.plot([], [], 'b-', label='Altitude')
line2, = ax2.plot([], [], 'r-', label='Pressure')
line3, = ax3.plot([], [], 'g-', label='Temperature')
line4, = ax4.plot([], [], 'c-', label='Voltage')
line5, = ax5.plot([], [], 'm-', label='GPS Altitude')
line6, = ax6.plot([], [], 'y-', label='GPS Sats')

# Function to update the plots
def animate(i):
    # Read the CSV file
    df = pd.read_csv(csv_file_path)

    # Extract time and parameter values
    time_values = pd.to_datetime(df['TimeStamp'], errors='coerce').dropna()
    altitude_values = df['Altitude'].astype(float).dropna()
    pressure_values = df['Pressure'].astype(float).dropna()
    temperature_values = df['Temperature'].astype(float).dropna()
    voltage_values = df['Voltage'].astype(float).dropna()
    gps_altitude_values = df['GpsAltitude'].astype(float).dropna()
    gps_sats_values = df['GpsSats'].astype(float).dropna()

    # Update the line data
    line1.set_data(time_values, altitude_values)
    line2.set_data(time_values, pressure_values)
    line3.set_data(time_values, temperature_values)
    line4.set_data(time_values, voltage_values)
    line5.set_data(time_values, gps_altitude_values)
    line6.set_data(time_values, gps_sats_values)

    # Rescale axes if necessary
    ax1.relim()
    ax1.autoscale_view()
    ax2.relim()
    ax2.autoscale_view()
    ax3.relim()
    ax3.autoscale_view()
    ax4.relim()
    ax4.autoscale_view()
    ax5.relim()
    ax5.autoscale_view()
    ax6.relim()
    ax6.autoscale_view()

    return line1, line2, line3, line4, line5, line6

# Create the animation
ani = animation.FuncAnimation(fig, animate, interval=1000)  # Update every 1 second

# Add legends
ax1.legend()
ax2.legend()
ax3.legend()
ax4.legend()
ax5.legend()
ax6.legend()

# Adjust layout for better visual appeal
plt.tight_layout()

# Show the plot
plt.show()