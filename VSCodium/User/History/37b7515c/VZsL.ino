#include <Adafruit_BMP280.h>
#include <Adafruit_Sensor.h>
#include <Arduino.h>
#include <FS.h>
#include <MPU6050_tockn.h>
#include <SD.h>
#include <SPI.h>
#include <TinyGPS++.h>
#include <Wire.h>

Adafruit_BMP280 bmp;
MPU6050 mpu(Wire);
TinyGPSPlus gps;

#define MPU_ADDR 0x68s
#define BMP_SCK 13
#define BMP_MISO 12
#define BMP_MOSI 11
#define BMP_CS 10

#define SD_SPI_CS 5
#define FILE_NAME "Team-Astropeep-Data.txt"

#define GPS_RX_PIN 16
#define GPS_TX_PIN 17

HardwareSerial xbeeSerial(1);
HardwareSerial gpsSerial(2);

String TelemetryPackage;
int PacketCount;
int Count;
const String Team_Id = "2022ASI-002";
String FSW_State = "";
String TimeStamp;
String GpsTime;
float Pressure, Temperature, Altitude, Voltage, GpsLatitude, GpsLongitude,
    GpsAltitude, GpsSats;
float a_x, a_y, a_z, gyro_x, gyro_y, gyro_z, AngleX, AngleY, AngleZ;
File myFile;

// CSV Header (Define the column names once)
const String csvHeader = "Team_Id,TimeStamp,PacketCount,Altitude,Pressure,Temperature,Voltage,GpsTime,GpsLatitude,GpsLongitude,GpsAltitude,GpsSats,a_x,a_y,a_z,gyro_x,gyro_y,gyro_z,FSW_State,AngleX,AngleY,AngleZ";

void setup() {
  Serial.begin(9600);
  gpsSerial.begin(9600, SERIAL_8N1, 1, 3);
  xbeeSerial.begin(9600, SERIAL_8N1, 16, 17);
  Wire.begin();
  mpu.begin();
  mpu.calcOffsets(true, true);
  Wire.write(0);
  Wire.endTransmission(true);
  if (!bmp.begin(0x76)) {
    Serial.println(F("Could not find a valid BMP280 sensor, check wiring!"));
  }

  if (!SD.begin(SD_SPI_CS)) {
    Serial.println(F("SD Card: Initialization failed!"));
    while (1)
      ;
  }

  // Write the CSV header to the file once at the beginning
  myFile = SD.open(FILE_NAME, FILE_WRITE);
  if (myFile) {
    myFile.println(csvHeader);
    myFile.close();
  } else {
    Serial.print(F("SD Card: Issue encountered while attempting to open the file "));
    Serial.println(FILE_NAME);
  }
}

void loop() {
  Pressure = getPressure();
  Temperature = getTemperature();
  Altitude = getAltitude();
  Temperature = mpu.getTemp();
  gyro_x = mpu.getGyroX();
  gyro_y = mpu.getGyroY();
  gyro_z = mpu.getGyroZ();
  a_x = mpu.getAccX();
  a_y = mpu.getAccY();
  a_z = mpu.getAccZ();
  AngleX = mpu.getAngleX();
  AngleY = mpu.getAngleY();
  AngleZ = mpu.getAngleZ();
  Voltage = getVolt();
  GpsLatitude = getGPSlat();
  GpsLongitude = getGPSlon();
  GpsAltitude = getGPSalti();
  GpsSats = getGPSsats();
  Voltage = getVolt();
  TimeStamp = GpsTime;

  mpu.update();

  while (gpsSerial.available() > 0) {
    gps.encode(gpsSerial.read());
  }

  if (gps.date.isValid() && gps.time.isValid()) {
    GpsTime = String(gps.time.hour()) + ":" + String(gps.time.minute()) + ":" +
              String(gps.time.second());
  }

  float ref_height = 213.46;
  float ref_alt = GpsAltitude - ref_height;

  if (Altitude == ref_alt && Count == 0) {
    FSW_State = "Ground";
  }

  else if (Altitude > 100 && Count == 0) {
    Count++;
  }

  else if (Altitude < 500 && Altitude > 100 && Count == 1) {
    FSW_State = "Descent";
  }

  else if (Altitude < 100 && Count == 1) {
    FSW_State = "Landing";
  }

  else {
    FSW_State = "Ascent";
  }

  // Construct the CSV data row
  String csvData = Team_Id + "," + TimeStamp + "," + PacketCount + "," + 
                   Altitude + "," + Pressure + "," + Temperature + "," + 
                   Voltage + "," + GpsTime + "," + GpsLatitude + "," + 
                   GpsLongitude + "," + GpsAltitude + "," + GpsSats + "," + 
                   a_x + "," + a_y + "," + a_z + "," + gyro_x + "," + 
                   gyro_y + "," + gyro_z + "," + FSW_State + "," + AngleX + "," + 
                   AngleY + "," + AngleZ;

  // Send the CSV data packet
  const char *dataPacket = csvData.c_str();
  sendPacket(dataPacket); 

  // Append the CSV data row to the file
  myFile = SD.open(FILE_NAME, FILE_APPEND); // Use FILE_APPEND mode
  if (myFile) {
    myFile.println(csvData); // Print with a newline for each row
    myFile.close();
  } else {
    Serial.print(F("SD Card: Issue encountered while attempting to open the file "));
    Serial.println(FILE_NAME);
  }

  // Serial.println(dataPacket);

  delay(10);

  PacketCount++;
}

float getPressure() {
  float pressure = bmp.readPressure();
  return pressure;
}

float getTemperature() {
  float temp = bmp.readTemperature();
  return temp;
}

float getAltitude() {
  float alti = bmp.readAltitude(1005);
  return alti;
}

float getVolt() {
  int offset = 20;
  int volt = analogRead(12);
  double voltage = map(volt, 0, 1023, 0, 2500) + offset;
  voltage /= 100;
  return voltage;
}

float getGPSlat() {
  float lat = 0;
  if (gps.location.isValid()) {
    lat = gps.location.lat();
  }
  return lat;
}

float getGPSlon() {
  float lon = 0;
  if (gps.location.isValid()) {
    lon = gps.location.lng();
  }
  return lon;
}

float getGPSalti() {
  float alti = 0;
  if (gps.location.isValid()) {
    alti = gps.altitude.meters();
  }
  return alti;
}

int getGPSsats() {
  int sats = 0;
  if (gps.satellites.isValid()) {
    sats = gps.satellites.value();
  }
  return sats;
}

void sendPacket(const char *data) {

  byte startDelimiter = 0x7E;
  byte frameType = 0x10;
  byte frameID = 0x01;

  byte destAddr[] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF};
  byte destAddr16[] = {0xFF, 0xFE};

  byte options = 0x00;

  byte radius = 0x00;

  char dataCopy[strlen(data) + 1];
  strcpy(dataCopy, data);

  char *token = strtok(dataCopy, ",");
  while (token != NULL) {