#include<SoftwareSerial.h>
String data;

int ledpin1=8;
int ledpin2=2;
int ledpin3=3;
int bttx=9;    //tx of bluetooth module is connected to pin 9 of arduino
int btrx=10;    //rx of bluetooth module is connected to pin 10 of arduino
SoftwareSerial bluetooth(bttx,btrx);
void setup()
{
  pinMode(8,OUTPUT);
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  Serial.begin(9600);
  bluetooth.begin(9600);
}
void loop()
{
  if(bluetooth.available())    //if bluetooth module is transmitting data
  {
    /*int pos=bluetooth.read(); // store the data in pos variable
    Serial.println(pos);
    x.write(pos);             //move servo head to the given position
  }*/
 
  
  //for(int j=0;j<2;j++)
  //{
  data=bluetooth.readString();
  
  //}
  if(data=="yellow on")
  {
    digitalWrite(ledpin2,HIGH);
  }
  else if(data=="red on")
  {
    digitalWrite(ledpin3,HIGH);
    }
    else if(data=="green on")
  {
    digitalWrite(ledpin1,HIGH);
    }
    if(data=="yellow off")
  {
    digitalWrite(ledpin2,LOW);
  }
  else if(data=="red off")
  {
    digitalWrite(ledpin3,LOW);
    }
    else if(data=="green off")
  {
    digitalWrite(ledpin1,LOW);
    }
    else if(data=="all on")
    {
      digitalWrite(ledpin1,HIGH);
      digitalWrite(ledpin2,HIGH);
      digitalWrite(ledpin3,HIGH);
    }
    else if(data=="all off")
    {
      digitalWrite(ledpin1,LOW);
      digitalWrite(ledpin2,LOW);
      digitalWrite(ledpin3,LOW);
    }
  
  
  }
  
}
