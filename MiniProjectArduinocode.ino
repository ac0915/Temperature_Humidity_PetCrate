#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);  /// where the LCD display is connected to 

int tempsen= A1;       /// LM35 as analog input pin 1 
int val;
int ledR=8;
int ledG=7;         //where is RGB LEDS is connected to
int ledB=6;

int valR;
int valG;            
int valB;

int Buzzer=9;         // Buzzer is connected to digital pin9 

int button=10;           // button is connedted to digital pin 10
int buttonstate=0;
int prebuttonstate=0;
int buttoncounter=0;
 
void setup() {
pinMode(ledR, OUTPUT);
pinMode(ledG, OUTPUT);
pinMode(ledB, OUTPUT);           /// list RGB LEDS and buzzer as output, and button as input 
pinMode(Buzzer,OUTPUT); 
pinMode(button,INPUT);
pinMode(tempsen,INPUT);
Serial.begin(9600);
delay(100);
lcd.begin(16, 2);     /// indicate how many roll and columns
delay(100); 
}
void loop() {
  delay(100);
  Serial.println(buttonstate);
  Serial.println(prebuttonstate);
  val = analogRead(tempsen);           /// read the value get by the LM35
  val = (val*500)/1023;               /// calculate the actual temperature
  Serial.println(val);
  lcd.setCursor(0, 0);
  lcd.print("Temperature now:");      /// print Temperature now: on LCD
  lcd.setCursor(6, 1);
  lcd.print(val);                   /// print the actual temperature
  lcd.setCursor(8, 1);
  lcd.print("C");
  delay(100);
 buttonstate = digitalRead(button);  // see if the button is on or off

if (buttonstate != prebuttonstate){    
    if(buttonstate == LOW){
      buttoncounter ++;               // remember the button state and set the condition : 
    }                                 
    delay(10);
  prebuttonstate = buttonstate;
}
if(val<20){ ////BLUE with buzzer
  if(buttoncounter %2 ==0){            //if button count is even buzzer is HIGH
    digitalWrite(ledR,HIGH);
    digitalWrite(ledG,HIGH);
    digitalWrite(ledB,LOW);
    digitalWrite(Buzzer,HIGH);
    delay(100);
    }
  
  else{
Search

    digitalWrite(ledR,HIGH);
    digitalWrite(ledG,HIGH);
    digitalWrite(ledB,LOW);
    digitalWrite(Buzzer,LOW);
    delay(100);
  }
}
else if(val>=20 && val<=29){///GREEN
  digitalWrite(ledR,HIGH);
  digitalWrite(ledG,LOW);
  digitalWrite(ledB,HIGH);
  digitalWrite(Buzzer,LOW);
}
if(val>29){ ///red with buzzer
  if(buttoncounter %2 ==0){
    digitalWrite(ledR,LOW);
    digitalWrite(ledG,HIGH);
    digitalWrite(ledB,HIGH);
    digitalWrite(Buzzer,HIGH);
    delay(100);
    }
  else{
    digitalWrite(ledR,LOW);
    digitalWrite(ledG,HIGH);
    digitalWrite(ledB,HIGH);
    digitalWrite(Buzzer,LOW);
    delay(100);
  }
}
}