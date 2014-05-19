/*

@Author_Nivedita Tigadi.

  Button
 
 Turns on and off a light emitting diode(LED) connected to  
 pin 1, when pressing a pushbutton attached to pin 0. 
 
 
 The circuit:
 * LED attached from pin 1 to ground 
 * pushbutton attached to pin o from +5V
 * 10K resistor attached to pin 0 from ground
 
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
