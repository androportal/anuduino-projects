
void setup()
{
  pinMode(0,OUTPUT);
  pinMode(1,OUTPUT);
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);  
}

void loop()
{
  movefront();
  delay(2000);
  circular();
  delay(2000);
  moveback();
  delay(2000);
}

void movefront()
{
  digitalWrite(0,LOW);
  digitalWrite(1,LOW);
  digitalWrite(2,HIGH);
  digitalWrite(3,LOW);
  digitalWrite(5,HIGH);
  digitalWrite(4,LOW);
  digitalWrite(0,HIGH);
  digitalWrite(1,HIGH);
  delay(8000);
  digitalWrite(0,LOW);
  digitalWrite(1,LOW);
}

void moveback()
{
  digitalWrite(0,LOW);
  digitalWrite(1,LOW);
  digitalWrite(2,HIGH);
  digitalWrite(3,LOW);
  digitalWrite(4,HIGH);
  digitalWrite(5,LOW);
  digitalWrite(0,HIGH);
  digitalWrite(1,HIGH);
  delay(8000);
  digitalWrite(0,LOW);
  digitalWrite(1,LOW);
}

void circular()
{
  digitalWrite(0,LOW);
  digitalWrite(1,LOW);
  digitalWrite(3,HIGH);
  digitalWrite(2,LOW);
  digitalWrite(4,HIGH);
  digitalWrite(5,LOW);
  digitalWrite(0,HIGH);
  digitalWrite(1,HIGH);
  delay(8000);
  digitalWrite(0,LOW);
  digitalWrite(1,LOW);
}


