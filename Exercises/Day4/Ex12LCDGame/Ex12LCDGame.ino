
#include <LiquidCrystal_I2C.h>

#define LED1_PIN 3
#define LED2_PIN 5
#define LED3_PIN 6
#define LED4_PIN 9
#define LED5_PIN 11
#define BUTTON_PIN 2

// Creates an LCD object. Parameters: (rs, enable, d4, d5, d6, d7)
LiquidCrystal_I2C lcd(0x27, 16, 2);

int flag = 0;
int counterFlag = 1;

int32_t timer = 0;
//float timerLevel = 1.0;
int timerLED = 5000;
int LED = 1;

int buttonState;
int lastButtonState = 0;
int lastDebounceTime = 0;
unsigned long debounceDelay = 50;

int hitCounter = 0;
int missCounter = 0;
int currentCounter = 0;

void setup() {
  Serial.begin(115200);
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Hits: ");
  lcd.print(hitCounter);
  lcd.setCursor(0, 1);
  lcd.print(("Miss: "));
  lcd.print(missCounter);

  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(LED1_PIN, OUTPUT);
  pinMode(LED2_PIN, OUTPUT);
  pinMode(LED3_PIN, OUTPUT);
  pinMode(LED4_PIN, OUTPUT);
  pinMode(LED5_PIN, OUTPUT);
}

void loop() {
  int currentButtonState = digitalRead(BUTTON_PIN);

  if (currentButtonState != lastButtonState) {
    lastDebounceTime = timer;
  }

  if ((timer - lastDebounceTime) > debounceDelay) {
    if (currentButtonState != buttonState) {
      buttonState = currentButtonState;

      if (buttonState == LOW && flag == 1) {
        if (counterFlag == 1) {
          hitCounter++;
          counterFlag = 0;
          timerLED -= 500;
        }
        timer += 100;
        lcd.setCursor(6, 0);
        lcd.print(hitCounter);
      } else if (buttonState == LOW && flag == 0) {
        digitalWrite(LED1_PIN, LOW);
        digitalWrite(LED2_PIN, LOW);
        digitalWrite(LED3_PIN, LOW);
        digitalWrite(LED4_PIN, LOW);
        digitalWrite(LED5_PIN, LOW);
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("You missed");
        missCounter++;
        delay(1000);
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Hits: ");
        lcd.print(hitCounter);
        lcd.setCursor(0, 1);
        lcd.print(("Miss: "));
        lcd.print(missCounter);

        //reset
        if (missCounter == 3) {
          timerLED = 5000;
          missCounter = 0;
          hitCounter = 0;
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("Hits: ");
          lcd.print(hitCounter);
          lcd.setCursor(0, 1);
          lcd.print(("Miss: "));
          lcd.print(missCounter);
        }
      }
    }
  }

  if (timer % timerLED == 0) {
    if (hitCounter < 8) {
      LED += 1;
      if (LED == 6) {
        LED = 1;
      }
    } else if (hitCounter == 10) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("You Won!!!");
      LED = 10;
    } else if (hitCounter == 9) {
      timerLED = 1500;
      LED = random(1, 6);
      counterFlag = 1;
    } else if (hitCounter == 8) {
      timerLED = 2500;
      LED = random(1, 6);
      counterFlag = 1;
    }
  }

  switch (LED) {
    case 1:
      digitalWrite(LED1_PIN, HIGH);
      digitalWrite(LED2_PIN, LOW);
      digitalWrite(LED3_PIN, LOW);
      digitalWrite(LED4_PIN, LOW);
      digitalWrite(LED5_PIN, LOW);
      counterFlag = 1;
      break;

    case 2:
      digitalWrite(LED1_PIN, LOW);
      digitalWrite(LED2_PIN, HIGH);
      digitalWrite(LED3_PIN, LOW);
      digitalWrite(LED4_PIN, LOW);
      digitalWrite(LED5_PIN, LOW);
      break;
    case 3:
      digitalWrite(LED1_PIN, LOW);
      digitalWrite(LED2_PIN, LOW);
      digitalWrite(LED3_PIN, HIGH);
      digitalWrite(LED4_PIN, LOW);
      digitalWrite(LED5_PIN, LOW);
      flag = 1;
      break;

    case 4:
      flag = 0;
      digitalWrite(LED1_PIN, LOW);
      digitalWrite(LED2_PIN, LOW);
      digitalWrite(LED3_PIN, LOW);
      digitalWrite(LED4_PIN, HIGH);
      digitalWrite(LED5_PIN, LOW);
      break;

    case 5:
      digitalWrite(LED1_PIN, LOW);
      digitalWrite(LED2_PIN, LOW);
      digitalWrite(LED3_PIN, LOW);
      digitalWrite(LED4_PIN, LOW);
      digitalWrite(LED5_PIN, HIGH);
      break;
    case 10:
      won();
      break;
  }

  timer++;
}


void won() {
  digitalWrite(LED1_PIN, HIGH);
  digitalWrite(LED2_PIN, HIGH);
  digitalWrite(LED3_PIN, HIGH);
  digitalWrite(LED4_PIN, HIGH);
  digitalWrite(LED5_PIN, HIGH);
  delay(1000);
  digitalWrite(LED1_PIN, LOW);
  digitalWrite(LED2_PIN, LOW);
  digitalWrite(LED3_PIN, LOW);
  digitalWrite(LED4_PIN, LOW);
  digitalWrite(LED5_PIN, LOW);
  delay(1000);
}