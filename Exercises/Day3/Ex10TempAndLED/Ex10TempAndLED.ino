#include <Keyboard.h>


#define RED_PIN 3
#define YELLOW_PIN 5
#define GREEN_PIN 6



void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(RED_PIN, OUTPUT);
  pinMode(YELLOW_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(A0, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int sensorValue = analogRead(A0);

  float voltage = sensorValue * (5000.0 / 1023.0);

  float temperature = (voltage / 10);

  Serial.print("Temperature: ");
  Serial.print(temperature);
  char x = 176;
  //Serial.print(x);
 // Serial.print(char(176));
  Serial.write(0xC2);
  Serial.write(0xB0);
  Serial.println("C");

  if (temperature > 27) {
    digitalWrite(RED_PIN, HIGH);
    digitalWrite(YELLOW_PIN, LOW);
    digitalWrite(GREEN_PIN, LOW);
  } else if (temperature > 25) {
    digitalWrite(RED_PIN, LOW);
    digitalWrite(YELLOW_PIN, HIGH);
    digitalWrite(GREEN_PIN, LOW);
  } else if (temperature > 20) {
    digitalWrite(RED_PIN, LOW);
    digitalWrite(YELLOW_PIN, LOW);
    digitalWrite(GREEN_PIN, HIGH);
  } else {
    digitalWrite(RED_PIN, LOW);
    digitalWrite(YELLOW_PIN, LOW);
    digitalWrite(GREEN_PIN, LOW);
  }
  delay(500);
}