#include<Servo.h>
#include <LiquidCrystal.h> 
const int rs  = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int trigPin = 6;   
int echoPin = 7 ;   
long duration, cm ;
Servo m ;


 
void setup() {
lcd.begin(16, 2);
m.attach(9);
Serial.begin (9600);
pinMode(13,INPUT);
pinMode(8,OUTPUT);
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
}
 
void loop() {
 int a=digitalRead(13);
 Serial.println(a);
  delay(100);
  if(a==0) { 
  
    digitalWrite(8,HIGH);
   
    lcd.print("dustbin ");
    lcd.setCursor(0,2);
    lcd.print("full");
   
    delay(1000);
    lcd.clear();
    
  }
  else{
  Serial.print("dustbin");
  digitalWrite(8,LOW);
   }
  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  cm = (duration/2) / 29.1;     
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
  if(cm<=100){
   m.write(0);
  delay(4000);
  m.write(90);
  delay(4000);
  }
  


}
