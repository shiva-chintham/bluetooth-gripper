#include <SoftwareSerial.h>
String value;
int TxD = 11; 
int RxD = 10;
SoftwareSerial bluetooth(TxD, RxD);
int expand=2;
int contract=3;
int up=4;
int down=5;
int left_front=6;
int left_back=7;
int right_front=8;
int right_back=9;

void setup() {
  
  pinMode(expand,OUTPUT);
  pinMode(contract,OUTPUT);
  pinMode(up,OUTPUT);
  pinMode(down,OUTPUT);
  
  pinMode(left_front,OUTPUT);
  pinMode(left_back,OUTPUT);
  pinMode(right_front,OUTPUT);
  pinMode(right_back,OUTPUT);
  
  
  Serial.begin(9600);       // start serial communication at 9600bps
  bluetooth.begin(9600);
  
}

void loop() {
  Serial.println(value);
 if (bluetooth.available())
   {
    value = bluetooth.readString();


    if(value=="expand")
    {
        Serial.println("Expanding ");
        digitalWrite(expand, HIGH);
          digitalWrite(contract, LOW); 
        delay(6000);
        digitalWrite(expand,LOW);
        digitalWrite(contract,LOW);
          
          
    }
    if (value == "contract")
      {
         Serial.println("contracting   ");
      digitalWrite(expand, LOW);
        digitalWrite(contract, HIGH);
         delay(6000);
        digitalWrite(expand,LOW);
        digitalWrite(contract,LOW);
        
      }

    if (value == "up")
      {

          Serial.println("UP   ");
      digitalWrite(up,HIGH);
        digitalWrite(down, LOW);
        delay(2000);
        digitalWrite(up,LOW);
        digitalWrite(down,LOW);
        
      }
if (value == "down")
      {
        Serial.println("down ");
      digitalWrite(up, LOW);
        digitalWrite(down,HIGH);
        delay(2000);
        digitalWrite(up,LOW);
        digitalWrite(down,LOW);
      
  
      delay(3000);
    
}


if (value=="front")

{
  digitalWrite(left_front,HIGH);
  digitalWrite(right_front,HIGH);
  digitalWrite(left_back,LOW);
  digitalWrite(right_back,LOW);
  

  
}


if (value=="back")

{
  digitalWrite(left_front,LOW);
  digitalWrite(right_front,LOW);
  digitalWrite(left_back,HIGH);
  digitalWrite(right_back,HIGH);
  

  
}

if (value=="left")

{
  digitalWrite(left_front,LOW);
  digitalWrite(right_front,HIGH);
  digitalWrite(left_back,LOW);
  digitalWrite(right_back,LOW);
  

  
}

if (value=="right")

{
  
  digitalWrite(left_front,HIGH);
  digitalWrite(right_front,LOW);
  digitalWrite(left_back,LOW);
  digitalWrite(right_back,LOW);
  

  
}
if(value=="all off")
{
  
  digitalWrite(left_front,LOW);
  digitalWrite(right_front,LOW);
  digitalWrite(left_back,LOW);
  digitalWrite(right_back,LOW);
  
  
}




}
}
