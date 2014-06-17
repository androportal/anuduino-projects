#include <SoftSerial.h>
#include <TinyPinChange.h>

#define rxPin 0
#define txPin 1

SoftSerial myserial(2,3);
SoftSerial bluetooth(0,1);

void setup()  {

  pinMode(rxPin, INPUT);
  pinMode(txPin, OUTPUT);
	
  bluetooth.begin(9600);
  myserial.begin(9600);
}
	
void loop() {
	
   if(myserial.available())
   bluetooth.write(myserial.read());
  }
