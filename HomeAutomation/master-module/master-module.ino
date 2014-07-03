// Harish_Govindan_Master_trial5
// pin 0= TSOP
// pin 1= IR LED
// pin 2= Serial 
// pin 3= LED
char final[17];
int r,i=0,in=0,q=3,bin[16],j;
unsigned long k;
#include<TinyPinChange.h>
#include<SoftSerial.h>
SoftSerial check(2,2,true);
char txd[5]="1100", txd_rec[5]="1100",recd[17],addr_check[13],addr_sent[13];
int txd_con[4];
void setup()
{
  pinMode(1,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(0,INPUT);
  check.begin(19200);
//  check.txMode();
  for(i=0;i<16;i++)
  bin[i]=0;
 // check.println("readY!");
  i=0;
}
void loop()
{
  //check.println(i);
  //check.println("Initialising...");
  check.rxMode();
  while(!check.available())
  {
  receiver();
  }
  txd_rec[i++]=check.read();
  //check.txMode();
  if(i==4)
  {
//    check.txMode();
   for(i=0;i<16;i++)
  bin[i]=0;
  //check.println("Printing...");
    for(int ii=0;ii<4;ii++)
  {
  if(txd_rec[ii]>='0'&& txd_rec[ii]<='9')
   txd_con[ii]=(int)(txd_rec[ii]-'0');
  else
   txd_con[ii]=(int)(txd_rec[ii]-'A'+10);
  dec_hex(txd_con[ii]);
  }
  i=0;
  q=3;
   for(j=0;j<16;j++)
   {
    //check.print(bin[j]);
    final[j]=(char)(bin[j]+48);
   }
   //check.println();
   //check.println(final);
   transmit(final);
   //check.println("Waiting for ack...");
 }
 
}
void dec_hex(int x)
{
  r=q;
    
     while(x>0)
     {
     bin[q--]=x%2;
     x/= 2;
     }
  q=r;
  q+=4;  
}
void burst(int pulses)
{
  for(int i=0;i<pulses;i++)
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
void transmit(char txd[])
{
    burst(192);
  delay(10);
  for(int i=0;i<16;i++)
  {
    signal(txd[i]);
    delay(1);
  }
}








void receiver()
{
    
  // check.txMode();
   //check.println("Scanning..");
   k=pulseIn(0,LOW);
  //check.println(k);
  if(k>4600)
  {
  //  check.print(F("Start bit! "));
    while(in<16)
    {
    k=pulseIn(0,LOW);
    if(k>2200)
     {
      //check.print(F("1"));
      recd[in]='1';
     }
    else if(k>1000)
       {
     // check.print(F("0"));
      recd[in]='0';
       } 
     in++;
    }
    in=0;
    compare();
  }
 // check.println("Receive mode!");
  //check.rxMode();
  
}
void compare()
{
   check.txMode();
    //  check.println("comparing...");
    //check.println(recd);
//    if (!strcmp(recd,"1100110011001100"))
//    {
//     digitalWrite(3,0);
//     check.println("Turned off!");
//    }
//        if (!strcmp(recd,"1101110111011101"))
//    {
//     digitalWrite(3,1);
//     check.println("Turned on!");
//    }
//    check.println("compared!");
  //  check.rxMode();
  
  for(int h=0;h<12;h++)
    {
    addr_check[h]=recd[h];
    addr_sent[h]=final[h];
    }
   if((!strcmp(addr_check,addr_sent))&&(recd[12]=='0'))
    {
      //check.println("Module matched!");
      ack_check();
    }
    else
    {
      //check.println("Ack mismatch!");
      //check.println(recd);
    }
 check.rxMode(); 
}
void ack_check()
{
//   if(recd[13]=='0')
//     check.println("Acknowledgement!");
//   else
//     check.println("Status Response!");
   check.println();
   for(int g=0;g<3;g++)
   check.print(txd_rec[g]);
   if(recd[13]=='0')
   {
   if(recd[14]=='0')
   {
     //  check.println("The LED is off");
   check.println("1");
   }
    else 
    {
    // check.println("The LED is on");
    check.println("3");
    }
   }
   else
   {
        if(recd[14]=='0')
   {
     //  check.println("The LED is off");
   check.println("5");
   }
    else 
    {
    // check.println("The LED is on");
    check.println("7");
    }
   }
}
