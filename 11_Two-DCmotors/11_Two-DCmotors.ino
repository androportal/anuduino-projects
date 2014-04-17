const int motorForward = 0;
const int motorReverse = 1;

void setup()
{
  pinMode(motorForward, OUTPUT);
  pinMode(motorReverse, OUTPUT);  
}

void loop() {
    digitalWrite(motorForward, HIGH);
    delay(1000);
    digitalWrite(motorForward, LOW);
    delay(1000);
 
    digitalWrite(motorReverse, HIGH);
    delay(1000);
    digitalWrite(motorReverse, LOW);
    delay(1000);
 
}
