     // @Author_Nivedita Tigadi.

     // the setup routine runs once when you press reset:
     
    void setup()
     {   
      pinMode(1, OUTPUT); // initialize the digital pin as an output.
     }

       // the loop routine runs over and over again forever:

    void loop()
    
    {
    
    digitalWrite(1, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(1000);               // wait for a second
    digitalWrite(1, LOW);    // turn the LED off by making the voltage LOW
    delay(1000);               // wait for a second
    
    }