//
@Author_Nivedita Tigadi.
//
int ledPin = 1;      // LED connected to port 1
int analogPin = 2;   // potentiometer connected to adc 2
int val = 0;         // variable to store the read value
int aref = 0;

void setup()
{
  pinMode(ledPin, OUTPUT);   // sets the pin as output
}

void loop()
{
  val = analogRead(analogPin);   // read the input pin
  
  analogWrite(ledPin,val/4);
}
