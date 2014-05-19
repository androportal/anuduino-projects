//@Author_Nivedita Tigadi.
//

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

