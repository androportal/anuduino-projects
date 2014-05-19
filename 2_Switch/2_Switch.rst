Switch button interfacing with Anuduino 
=======================================

Overview of the experiment
--------------------------


In this experiment we are going to make the Anuduino to listen and feel. We are starting with a simple push button. Wiring up the push button is simple. There is one component,the pull up resistor,that might seem out of place. This is included because Anuduino doesn't sense the same way we do (ie button pressed, button unpressed). Instead it looks at the voltage on the pin nd decides wheteher it's HIGH or LOW. The button is set up to pull the Anuduino's pin LOW when it is pressed, however,when the button is unpressed the voltage of the pin will float(causing occasional errors). To get the Anuduino to reliably read the pin as HIGH when the button is unpressed, we add the pull up resistor. 



Components reqiured
-------------------

- Breadbord        X1
- Pushbutton       X1
- Resistor (1K)    X1
- LED              X1
- Wires
- Powersupply(5V)


Schematic
---------

.. image:: ../images/2_SWITCH_schem.png


Circuit Diagram
---------------

.. image:: ../images/2_SWITCH_bb.png



Code
----

.. code-block::  c

   /*
   @Author_Nivedita Tigadi.
   
   Button
 
   Turns on and off a light emitting diode(LED) connected to digital  
   pin 1, when pressing a pushbutton attached to pin 0. 
 
 
   The circuit:
  * LED attached from pin 1 to ground 
  * pushbutton attached to pin 0 from +5V
  * push button is connected to ground through 1k resistor
 
  */
   // constants won't change. They're used here to 
  // set pin numbers:
  const int buttonPin = 0;     // the number of the pushbutton pin
  const int ledPin = 1 ;      // the number of the LED pin

  // variables will change:
  int buttonState = 0;         // variable for reading the pushbutton status

  void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);      
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);     
  }

  void loop(){
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH:
  if (buttonState == HIGH) {     
    // turn LED on:    
    digitalWrite(ledPin, HIGH);  
  } 
  else {
    // turn LED off:
    digitalWrite(ledPin, LOW); 
  }
  }
