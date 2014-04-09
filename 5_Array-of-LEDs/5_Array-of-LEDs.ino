

void setup() {   
  
  // initialize the following pins as output.
  
  pinMode(0, OUTPUT); //LED on pin 0
  pinMode(1, OUTPUT); //LED on pin 1
  pinMode(3, OUTPUT); //LED on pin 3
  pinMode(4, OUTPUT); //LED on pin 4
    
}

// the loop routine runs over and over again forever:
void loop() {
  digitalWrite(0, HIGH); // turn the 1st LED on (HIGH is the voltage level)
  delay(500);   
  digitalWrite(1, HIGH); // turn the 2nd LED on (HIGH is the voltage level)
  delay(500); 
  digitalWrite(3, HIGH); // turn the 3rd LED on (HIGH is the voltage level)
  delay(500);   
  digitalWrite(4, HIGH); // turn the 4th LED on (HIGH is the voltage level)
  delay(500);               
  digitalWrite(0, LOW);  // turn the 1st LED off by making the voltage LOW
delay(500);  
  digitalWrite(1, LOW); // turn the 2nd LED off by making the voltage LOW
  delay(500); 
  digitalWrite(3, LOW);  // turn the 3rd LED off by making the voltage LOW
delay(500);   
  digitalWrite(4, LOW);  // turn the 4th LED off by making the voltage LOW
  delay(500);            
}
