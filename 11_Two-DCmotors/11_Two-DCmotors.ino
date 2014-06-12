//@Author_Nivedita Tigadi


const int motorForward = 0;  //pin for running motor1 in forward direction
const int motorReverse = 1;   //pin for running motor2 in reverse direction

void setup()
{
  pinMode(motorForward, OUTPUT);  
  pinMode(motorReverse, OUTPUT);  
}

void loop() {
    digitalWrite(motorForward, HIGH);    //motor1 runs in forward direction
    delay(1000);							     //waits for a second
    digitalWrite(motorForward, LOW);   //motor1 stops
    delay(1000);							    //and waits for one second
 
    digitalWrite(motorReverse, HIGH);  //motor2 runs in reverse direction
    delay(1000);							  //waits for a second
    digitalWrite(motorReverse, LOW);  //motor2 stops
    delay(1000);							  //waits for a second
 
}
