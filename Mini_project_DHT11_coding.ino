#include <LiquidCrystal.h>
#include <dht.h>
#define dht_dpin 13           ///DHT 11 is connected to digital pin 13
dht DHT;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);  /// where the LCD display is connected to 

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
Serial.begin(9600);
delay(100);
lcd.begin(16, 2);     /// indicate how many roll and columns
delay(100); 
}
void loop() {
  delay(100);
  Serial.println(buttonstate);
  Serial.println(prebuttonstate);
  DHT.read11(dht_dpin);                    ///get the value 
  Serial.println(DHT.temperature);
  lcd.setCursor(0, 0);
  lcd.print("Temperature now:");      /// print Temperature now: on LCD
  lcd.setCursor(5, 1);
  lcd.print(DHT.temperature);                   /// print the actual temperature
  lcd.setCursor(9, 1);
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
if(DHT.temperature<22){ ////BLUE with buzzer
  if(buttoncounter %2 ==0){            //if button count is even buzzer is HIGH
    digitalWrite(ledR,HIGH);
    digitalWrite(ledG,HIGH);
    digitalWrite(ledB,LOW);
    digitalWrite(Buzzer,HIGH);
    delay(100);
    }
  
  else{
    digitalWrite(ledR,HIGH);
    digitalWrite(ledG,HIGH);
    digitalWrite(ledB,LOW);
    digitalWrite(Buzzer,LOW);
    delay(100);
  }
}
else if(DHT.temperature>=22 && DHT.temperature<=29){///GREEN
  digitalWrite(ledR,HIGH);
  digitalWrite(ledG,LOW);
  digitalWrite(ledB,HIGH);
  digitalWrite(Buzzer,LOW);
}
if(DHT.temperature>29){ ///red with buzzer
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