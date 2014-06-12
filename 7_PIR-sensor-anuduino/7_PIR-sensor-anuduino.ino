//@Author_Nivedita Tigadi.

int pirPin = 1;    //the digital pin connected to the PIR sensor's output
int ledPin = 0;

void setup()
{
  pinMode(pirPin, INPUT);
  pinMode(ledPin, OUTPUT);
  digitalWrite(pirPin, LOW);
}
  
void loop(){

     if(digitalRead(pirPin) == HIGH)
     {
       digitalWrite(ledPin, HIGH); 
     }
     
     if(digitalRead(pirPin) == LOW)
     {
       digitalWrite(ledPin, LOW);
     }

 }
     

       
    

