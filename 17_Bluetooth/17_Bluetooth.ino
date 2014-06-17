        #include <SoftSerial.h>
	#include <TinyPinChange.h>

	SoftSerial mySerial(0,1);

	char receivedChar;
	int  LED = 3; // LED on pin 3
	

	//RX on Bluetooth to TX on ATtiny85 through a voltage divider 50ohm from ATtiny85 and 100ohm to ground. This is so we can drop the the voltage down to 3.3v (roughly)
	// Use blueterm on android to get messages

	void setup()
	{
	  // Open serial communications and wait for port to open:
	  pinMode(LED, OUTPUT);
	  mySerial.begin(9600);
	  mySerial.println("Welcome to the wonderful world of bluetooth communication");
	  delay(1000);
	  mySerial.println("Sending a '1' will turn on the LED, Sending a '2' will turn off the LED");
	  delay(1000);
	  mySerial.println("a '3' will flash the LED");
	}

	void loop() // run over and over
	{
	
	  while (!mySerial.available());   // stay here so long as COM port is empty
	  receivedChar = mySerial.read();
	  if (receivedChar == '1') {
	    digitalWrite(LED, HIGH);
	  }// if it's a 1 turn LED on
	  if (receivedChar == '2') {
	    digitalWrite(LED, LOW);
	  } // if it's a 2 turn LED off
	  if (receivedChar == '3') {
	    for (int i = 0; i < 30; i++) {
	      digitalWrite(LED, HIGH);
	      delay(20);
	      digitalWrite(LED, LOW);
	      delay(20);
	    }
	  } // if it is a 3 flash the LED
	}



   
