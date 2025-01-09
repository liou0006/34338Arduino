
#include <LiquidCrystal_I2C.h>

#define LED1_PIN 3
#define LED2_PIN 5
#define LED3_PIN 6
#define LED4_PIN 9
#define LED5_PIN 11

// Creates an LCD object. Parameters: (rs, enable, d4, d5, d6, d7)
LiquidCrystal lcd(0x27, 16, 2);

void setup()
{
    lcd.initialize();
    lcd.backligt();
    lcd.clear();

    pinMode(LED1_PIN, OUTPUT);
    pinMode(LED2_PIN, OUTPUT);
    pinMode(LED3_PIN, OUTPUT);
    pinMode(LED4_PIN, OUTPUT);
    pinMode(LED5_PIN, OUTPUT);
}

void loop()
{
    digitalWrite(LED1_PIN, HIGH);
    delay(1000);
    digitalWrite(LED1_PIN, LOW);
    digitalWrite(LED2_PIN, HIGH);
    delay(1000);
    digitalWrite(LED2_PIN, LOW);
    digitalWrite(LED3_PIN, HIGH);
    delay(1000);
    digitalWrite(LED3_PIN, LOW);
    digitalWrite(LED4_PIN, HIGH);
    delay(1000);
    digitalWrite(LED4_PIN, LOW);
    digitalWrite(LED5_PIN, HIGH);
    delay(1000);
    digitalWrite(LED5_PIN, LOW);

}