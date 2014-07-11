//pin 0- TSOP
// pin 1- IR LED
// pin 2 serial
//pin 3 -indicator LED
char addr[13]="110011001100";
int i=0,state=0;
unsigned long k;

#include<TinyPinChange.h>
#include<SoftSerial.h>
SoftSerial check(2,2,true);

char recd[17], addr_check[13];
void setup()
{
  check.begin(19200);
  check.txMode();
  check.println("Initialising...");
  pinMode(1,OUTPUT);
  pinMode(0,INPUT);  
  pinMode(3,OUTPUT);
  digitalWrite(3,1);
  state=1;
  delay(1000);
}
void loop()
{
 // check.println("Scanning...");
  receiver();
}

void receiver()
{
  //check.txMode();
  check.println("Scanning...");
  k=pulseIn(0,LOW);
  //check.println(k);
  if(k>4600)
  {
    check.print(F("Start bit! "));
    while(i<16)
    {
    k=pulseIn(0,LOW);
    if(k>2200)
     {
      check.print(F("1"));
      recd[i]='1';
     }
    else if(k>1000)
       {
      check.print(F("0"));
      recd[i]='0';
       } 
     i++;
    }
    i=0;
    compare();
  }
  
}
void compare()
{
      check.println("comparing...");
    check.println(recd);
    for(int h=0;h<=11;h++)
      addr_check[h]=recd[h];
    if((!strcmp(addr_check,addr))&&(recd[12]=='1'))
    {
      check.println("This is for me!");
      if(recd[13]=='0')
      process();
      ack_prep();
    }
    else
    check.println("This is not for me!");
}
void process()
{
   if(recd[14]=='0')
   {
    digitalWrite(3,1);
    state=1;
   }
    
   else
   { 
    digitalWrite(3,0);
    state=0;
   }
}
void ack_prep()
{
  if(recd[12]=='0')
    recd[12]='1';
  else
    recd[12]='0';
    

  if(state==1)
  recd[14]='1';
  else
  recd[14]='0';
    transmit(recd);
}
      

void burst(int pulses)
{
  for(int in=0;in<pulses;in++)
  {
    digitalWrite(1,1);
    delayMicroseconds(5);
    digitalWrite(1,0);
    delayMicroseconds(12);
  }
  delayMicroseconds(600);
}
void signal(char x)
{
  if(x=='1')
   burst(96);
   else
   burst(48);
  delay(1);
}
void transmit(char data[])
{
  check.println("Transmitting...");
    burst(192);
  delay(10);
  for(int in=0;in<16;in++)
  {
    signal(data[in]);
    delay(1);
  }
  check.println("Transmitted!");
}
