void setup() {
  // put your setup code here, to run once:
    Serial.begin(115200);
    pinMode(5, OUTPUT);
    pinMode(3, INPUT_PULLUP);
}

  void loop() {
    // put your main code here, to run repeatedly:
      digitalWrite(5, HIGH);
      delay(1000);
      digitalWrite(5, LOW);
      


    if(digitalRead(3) == LOW){
      Serial.println("Button pressed");
    }
  }