Blink LED
=========

Overview of the experiment
--------------------------

 LEDs (light emitting diodes) are used in all sorts of clever things which is why we have induced them in the kit. We will start off with something very simple, turning one on and off,repeatedly,producing a pleasant blinking effect. To get started, grab the parts listed below and assemble the circuit. Once the circuit is assembled you will need to upload the program on Attiny85. To upload the program plug your Anuduino into your USB port. Then select the proper board in Tools>Board>anuduino, and select the programmer in Tools>Programmer>Anuduino. Next upload the program by going to File>Upload*(ctrl+U). finally, ou will get the pleasant blinking effect.


Component required
-------------------

- Breadboard x 1
- Attiny85 x 1
- LED x 1
- Resistor(1K) x 1
- Wires
- Powesupply (5V)


Schematic
----------

.. image:: images/LEDBlink_1_bb.png
	:scale: 140 %

Circuit Diagram
----------------

.. image:: images/LEDblink_1_bb.png
	:scale: 60 %

Anuduino source
---------------

.. code-block:: c


	
	// the setup routine runs once when you press reset:
	void setup() {                
	// initialize the digital pin as an output.
	  pinMode(0, OUTPUT); //LED on Model 
	}

	// the loop routine runs over and over again forever:
	void loop() {
	  digitalWrite(0, HIGH);   // turn the LED on (HIGH is the voltage level)
	  delay(1000);             // wait for a second
	  digitalWrite(0, LOW);    // turn the LED off by making the voltage LOW
  	  delay(1000);             // wait for a second
	}




