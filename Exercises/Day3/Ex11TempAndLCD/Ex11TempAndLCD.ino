#include <Wire.h>


//#include <LiquidCrystal_I2C.h>
#include <LiquidCrystal_I2C.h>


LiquidCrystal_I2C lcd(0x27,  16, 2);

#define READPIN A0 


void setup() {
  // put your setup code here, to run once:
//pinMode(READPIN, INPUT); 
Serial.begin(115200);
lcd.init();
lcd.backlight();

}

void loop() {
  // put your main code here, to run repeatedly:
int a = analogRead(READPIN); 
a = map(a,0,1023,0,5000);
float b = (float)a;
b = (b/10);
Serial.print(b); 
Serial.print(u8"\u00b0"); //to make deg sign with 7bit ascii 
//Serial.write(176);
Serial.write(67);
Serial.println();
delay(200);


if(b > 26) {
lcd.clear();
lcd.setCursor(0,0);
lcd.print("!!!!!!!!!");
lcd.setCursor(0,1);
lcd.print("!!!!!!!!!"); 
} else {
lcd.clear();
lcd.setCursor(0,0);
lcd.print("Temperature is: ");
lcd.setCursor(0,1);
lcd.print(b); 

}

delay(200);



}


