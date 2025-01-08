void setup() {
  // put your setup code here, to run once:
    Serial.begin(115200);
    pinMode(3, OUTPUT);
    pinMode(5, INPUT_PULLUP);
}

  void loop() {
    // put your main code here, to run repeatedly:
    if(digitalRead(5) == LOW){
      digitalWrite(3, HIGH);
      Serial.println("LED ON");
      delay(1000);
      digitalWrite(3, LOW);
      Serial.println("LED OFF");
    }
  }