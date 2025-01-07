void setup() {
  // put your setup code here, to run once:
    Serial.begin(115200);
    pinMode(3, OUTPUT);
    pinMode(5, INPUT_PULLUP);
}

  void loop() {
    // put your main code here, to run repeatedly:
    if(digitalRead(5) == LOW){
      Serial.println("Button pressed");
      digitalWrite(3, HIGH);
      delay(1000);
      digitalWrite(3, LOW);
    }
  }