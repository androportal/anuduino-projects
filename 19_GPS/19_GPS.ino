#include <SoftwareSerial.h>
#include <TinyGPS.h>
     
long lat,lon; // create variable for latitude and longitude object
SoftwareSerial gpsSerial(2, 3); // create gps sensor connection
TinyGPS gps; // create gps object
     
void setup()
{
  Serial.begin(9600); // connect serial
  gpsSerial.begin(4800); // connect gps sensor
}
     
void loop()
{
  while(gpsSerial.available())
  {  // check for gps data
     if(gps.encode(gpsSerial.read()))
     { // encode gps data
         gps.get_position(&lat,&lon); // get latitude and longitude
         // display position
         Serial.print("Position: ");
         Serial.print("lat: ");Serial.print(lat);Serial.print(" ");// print latitude
         Serial.print("lon: ");Serial.println(lon); // print longitude
     }
  }
}
