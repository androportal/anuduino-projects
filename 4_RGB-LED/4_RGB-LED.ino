//@Author_Nivedita Tigadi.

/*     ---------------------------------------------------------
 *     |  Experimentation Kit for Anuduino Example Code         |
 *     |  CIRC-RGB .: Colourful Light :. (RGB LED)             |
 *     ---------------------------------------------------------
 * 
 * We've blinked an LED and controlled eight in sequence now it's time to 
 * control colour. Using an RGB LED (actual 3 LEDs in a single housing)  
 * we can generate any colour we wish to see.
 *
 * (we'll also use a few programming shortcuts to make the code 
 * more portable/readable)
 */


//RGB LED pins
int ledDigitalOne[] = {4, 1, 0}; //the three digital pins of the digital LED 
                                   //4 = redPin, 1 = greenPin, 0 = bluePin

const boolean ON = LOW;     //Define on as LOW (this is because we use a common 
                            //Anode RGB LED (common pin is connected to +5 volts)
const boolean OFF = HIGH;   //Define off as HIGH

//Predefined Colors
const boolean RED[] = {ON, OFF, OFF};    
const boolean GREEN[] = {OFF, ON, OFF}; 
const boolean BLUE[] = {OFF, OFF, ON}; 
const boolean YELLOW[] = {ON, ON, OFF}; 
const boolean CYAN[] = {OFF, ON, ON}; 
const boolean MAGENTA[] = {ON, OFF, ON}; 
const boolean WHITE[] = {ON, ON, ON}; 
const boolean BLACK[] = {OFF, OFF, OFF}; 

//An Array that stores the predefined colors (allows us to later randomly display a color)
const boolean* COLORS[] = {RED, GREEN, BLUE, YELLOW, CYAN, MAGENTA, WHITE, BLACK};

void setup(){
  for(int i = 0; i < 3; i++){
   pinMode(ledDigitalOne[i], OUTPUT);   //Set the three LED pins as outputs
  }
}

void loop(){

/* Example - 1 Set a color
   Set the three LEDs to any predefined color
*/
   setColor(ledDigitalOne, RED);    //Set the color of LED one

/* Example - 2 Go through Random Colors
  Set the LEDs to a random color
*/
   randomColor();

}

void randomColor(){
  int rand = random(0, sizeof(COLORS) / 2);  //get a random number within the range of colors
  setColor(ledDigitalOne, COLORS[rand]);  //Set the color of led one to a random color
  delay(1000);
}

/* Sets an led to any color
   led - a three element array defining the three color pins (led[0] = redPin, led[1] = greenPin, led[2] = bluePin)
   color - a three element boolean array (color[0] = red value (LOW = on, HIGH = off), color[1] = green value, color[2] =blue value)
*/
void setColor(int* led, boolean* color){
 for(int i = 0; i < 3; i++){
   digitalWrite(led[i], color[i]);
 }
}

/* A version of setColor that allows for using const boolean colors
*/
void setColor(int* led, const boolean* color){
  boolean tempColor[] = {color[0], color[1], color[2]};
  setColor(led, tempColor);
}
