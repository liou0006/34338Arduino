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
  int sensorValue2 = analogRead(A0);
  Serial.print("Analog value: ");
  Serial.println(sensorValue);

  float voltage = sensorValue * (5.0 / 1023.0);
  sensorValue2 = map(sensorValue2, 0, 1023, 0, 5000);
  float voltage2 = (float)sensorValue2;


  Serial.print("Voltage value 1: ");
  Serial.println(voltage);
  Serial.print("Sensor value 2: ");
  Serial.println(voltage2);

  float temperature = (voltage / 10);
  float temperature2 = (voltage2 / 10);
  Serial.print("Temperature: ");
  Serial.println(temperature);
  Serial.print("Temperature2: ");
  Serial.print(temperature2);
  Serial.println("°C");

  if (temperature > 25) {
    digitalWrite(RED_PIN, HIGH);
    digitalWrite(YELLOW_PIN, LOW);
    digitalWrite(GREEN_PIN, LOW);
  } else if (temperature > 15) {
    digitalWrite(RED_PIN, LOW);
    digitalWrite(YELLOW_PIN, HIGH);
    digitalWrite(GREEN_PIN, LOW);
  } else if (temperature > 5) {
    digitalWrite(RED_PIN, LOW);
    digitalWrite(YELLOW_PIN, LOW);
    digitalWrite(GREEN_PIN, HIGH);
  } else {
    digitalWrite(RED_PIN, LOW);
    digitalWrite(YELLOW_PIN, LOW);
    digitalWrite(GREEN_PIN, LOW);
  }
  delay(2000);
}