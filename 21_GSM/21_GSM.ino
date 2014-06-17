#include <SoftSerial.h>
#include <TinyPinChange.h>
	
SoftSerial gsm(0,1);
	
void setup()
{
  Serial.begin(9600);
  gsm.begin(9600);
  gsm.println("AT+CMGF=1");
  delay(30);
  gsm.println("AT+CMGS=\"+919943985414\"");
  delay(30);
  gsm.println("Hello world");
  delay(30);
  gsm.write((byte)0x1A); //Ctrl+Z
  delay(30);
  pinMode(2,INPUT);
}
void loop()
{
 if(digitalRead(2)== HIGH)
 {  gsm.println("Hello world");
  delay(1000);
  gsm.write((byte)0x1A); //Ctrl+Z
  delay(1000);
 }
 if(digitalRead(2)==LOW)
 {
   ;
  //delay(30);
 }
 }
