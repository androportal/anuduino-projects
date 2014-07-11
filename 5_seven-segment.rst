Seven segment display with anuduino
-----------------------------------


Overview of the experiment
~~~~~~~~~~~~~~~~~~~~~~~~~~

The seven segment display is a pretty simple device.
It is actually 8 LEDs (the decimal point is the 8th). 
It can be arranged so that different combinations can 
be used to make numerical digits. This tutorial will 
show you how to wire one up and drive it with Attiny85
 using 7447 as 4-bit BCD to 7-bit LED driver IC. Each 
IC output corresponds to a particular input of the seven
segment display. The Lamp Test input pin on the IC simply 
just turns all the LEDs on at the same time while the Blanking
pin forces all the LEDs to turn off. To get started, grab the 
parts listed below and assemble the circuit. Once the circuit is
assembled you will need to upload the program on Attiny85.
 To upload the program plug your Anuduino into your USB port. 
Then select the proper board in Tools>Board>anuduino, and
select the programmer in Tools>Programmer>Anuduino.Next 
upload the program by going to File>Upload*(ctrl+U). Finally, 
you will get the Seven Segment Display flashing all the 10
numerics(0-9) repeatedly.



Components required
~~~~~~~~~~~~~~~~~~~

- Seven Segment Display LT542.......X1
- Display Driver IC 7448(Decoder)...X1
- ATtiny85..........................X1
- 470 ohm Resistor..................X1
- Wires
- Battery(5V).......................X1


Circuit Diagram
~~~~~~~~~~~~~~~

.. image:: ../images/7seg.png



Code
~~~~


.. code-block::  c
	
	//@Author_Piyush Mahajan, Samridha Kumar, Nivedita Tigadi

	void setup()
	{
	pinMode(0,OUTPUT);
 	 pinMode(1,OUTPUT);
 	 pinMode(2,OUTPUT);
 	 pinMode(3,OUTPUT);
	}

	void loop()
	{  
 	 display_numbers(0,0,0,0);
	  display_numbers(1,0,0,0);
	  display_numbers(0,1,0,0);
	  display_numbers(1,1,0,0);
	  display_numbers(0,0,1,0);
	  display_numbers(1,0,1,0);
	  display_numbers(0,1,1,0);
	  display_numbers(1,1,1,0);
	  display_numbers(0,0,0,1);
	  display_numbers(1,0,0,1);
	}

	void display_numbers(int a, int b, int c, int d)
	{
	  delay(2000);
	  digitalWrite(0,a);
	  digitalWrite(1,b);
	  digitalWrite(2,c);
	  digitalWrite(3,d);
	}

	

