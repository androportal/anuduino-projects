#include <SoftSerial.h>
	#include <TinyPinChange.h>

	SoftSerial xbee(0, 1);

	void setup()
	{
 	 pinMode(2,INPUT);
  	Serial.begin(9600);
  	xbee.begin(9600);
	}

	void loop()
	{
  	if(digitalRead(2)==HIGH)
  	 set(0x5);    //turns on the LED
  	if(digitalRead(2)==LOW)
   	set(0x4);    //turns off the LED
	}
	void set(char value)
	{
 	 xbee.write(0x7E); // Sync up the start byte
  	 xbee.write((byte)0x0);
  	 xbee.write(0x10); // Length LSB
  	 xbee.write(0x17); // 0x17 is the frame ID for sending an AT command
 	 xbee.write((byte)0x0); // Frame ID (no reply needed)
 	 xbee.write((byte)00); // Send the 64 bit destination address
 	 xbee.write((byte)00); // (Sending 0x000000000000FFFF (broadcast))
 	 xbee.write((byte)00);
 	 xbee.write((byte)00);
  	 xbee.write((byte)00);
  	 xbee.write((byte)00);
  	 xbee.write(0xFF);
 	 xbee.write(0xFF);
 	 xbee.write(0xFF); // Destination Network
	 xbee.write(0xFE); // (Set to 0xFFE if unknown)
 	 xbee.write(0x02); // set to 0x)2 to apply these changes
 	 xbee.write('D');  //AT command:D1
 	 xbee.write('3');
 	 xbee.write(value); // Set D1 to be 5 (Digital Out HIGH)
 	 long chexsum = 0x17 + 0xFF + 0xFF + 0xFF + 0xFE + 0x02 + 'D' + '3' + value;
 	 xbee.write( 0xFF - (chexsum & 0xFF)); // Checksum
	}
