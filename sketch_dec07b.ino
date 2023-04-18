#include<dht.h>
#include <SoftwareSerial.h>
#define datapin 8
char userinput;
char data;
int msensor = A1;
int msvalue = 0;
SoftwareSerial SIM900A(9,10);
dht DHT;
void setup() {
  // put your setup code here, to run once:
  SIM900A.begin(9600);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()>0){
    userinput = Serial.read();
    if(userinput == 'g'){
      int readData = DHT.read22(datapin);
      float t = DHT.temperature;
      float h = DHT.humidity;
  //Serial.print("Temperature:");
      Serial.print(t);
      Serial.print('-');
  //Serial.print(" c ");
  //Serial.print("Humidity:");
      Serial.print(h);
  //Serial.print(" % ");
      delay(2000);
        //Serial.println ("Sending Message");
        SIM900A.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
        delay(1000);
        //Serial.println ("Sending to 9597265965");
        SIM900A.println("AT+CMGS=\"+919597265965\"\r"); //Mobile phone number to send message
        //delay(1000);
        //Serial.println ("Set SMS Content");
        SIM900A.println((String)"Temprature="+t+(String)"Humidity="+h);// Messsage content
        delay(100);
        //Serial.println ("Finish");
        SIM900A.println((char)26);// ASCII code of CTRL+Z
        delay(1000);
        //Serial.println ("Message has been sent ->");
   
  }
        int readData = DHT.read22(datapin);
      float t = DHT.temperature;
      float h = DHT.humidity;
  //Serial.print("Temperature:");
      Serial.print(t);
      Serial.print('-');
  //Serial.print(" c ");
  //Serial.print("Humidity:");
      Serial.print(h);
  //Serial.print(" % ");
      delay(2000);
        //Serial.println ("Sending Message");
        SIM900A.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
        delay(1000);
        //Serial.println ("Sending to 9597265965");
        SIM900A.println("AT+CMGS=\"+919597265965\"\r"); //Mobile phone number to send message
        //delay(1000);
        //Serial.println ("Set SMS Content");
        SIM900A.println((String)"Temprature="+t+(String)"Humidity="+h);// Messsage content
        delay(100);
        //Serial.println ("Finish");
        SIM900A.println((char)26);// ASCII code of CTRL+Z
        delay(1000);
        //Serial.println ("Message has been sent ->");
  }
}
