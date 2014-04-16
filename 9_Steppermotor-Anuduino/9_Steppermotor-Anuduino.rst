Steppermotor-Anuduino
=====================

Overview of the experiment
--------------------------

In this project, We are going to interface our anuduino with
steppermotor. We are controlling the direction of the motor 
with a potentiometer. The potentiometer regulates the direction
of steppermototr.


Components required
-------------------


- Breadboard          x1
- Attiny85            x1
- Potentiometer(10k)  x1
- Powersupply         x1
- Steppermotor        x1


Schematic
---------

.. image:: images/9_Steppermotor_schem.png


Circuit Diagram
---------------

.. image:: images/9_Steppermotor_bb.png


Code
----

.. code-block::  c


	int analogPin = 3;   // potentiometer connected to adc 3
	int val = 0;         // variable to store the read value
	int aref = 0;
	int servoPin = 0; //Steppermotor pin connected to pin 0

	void setup()
	{
	  pinMode(servoPin, OUTPUT);   // sets the pin as output
	}

	void loop()
	{
	  val = analogRead(analogPin);   // read the input pin
  
	  analogWrite(servoPin,val/4);
	}



