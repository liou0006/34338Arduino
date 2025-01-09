
#include <LiquidCrystal_I2C.h>

#define LED1_PIN 3
#define LED2_PIN 5
#define LED3_PIN 6
#define LED4_PIN 9
#define LED5_PIN 11
#define BUTTON_PIN 2

// Creates an LCD object. Parameters: (rs, enable, d4, d5, d6, d7)
LiquidCrystal_I2C lcd(0x27, 16, 2);

int counter = 0;

void setup()
{
    Serial.begin(115200);
    lcd.init();
    lcd.backlight();
    lcd.clear();

    pinMode(BUTTON_PIN, OUTPUT);
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

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.setCursor(0, 1);
}