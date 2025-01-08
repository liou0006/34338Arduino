int incomingByte = 0;
int iB2 = 0;

void setup() {
  Serial.begin(9600);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
}

void loop() {

  incomingByte = Serial.read();
  Serial.print("I have received: ");
  Serial.println((char)incomingByte);
  delay(1000);

  if (incomingByte != -1) {
    if(incomingByte == 'a' || incomingByte == 'b' || incomingByte == 'c' || incomingByte == 'd' || incomingByte == 'e'){
      incomingByte = incomingByte;
    } else {
      incomingByte = 'Invalid';
    }
  } else {
    incomingByte = iB2;
  }
//hi
  switch (incomingByte) {
    case 'a':
      digitalWrite(2, HIGH);
      digitalWrite(3, LOW);
      digitalWrite(4, LOW);
      digitalWrite(5, LOW);
      digitalWrite(6, LOW);
      Serial.println("I have received a");
      delay(1000);
      break;
    case 'b':
      digitalWrite(2, LOW);
      digitalWrite(3, HIGH);
      digitalWrite(4, LOW);
      digitalWrite(5, LOW);
      digitalWrite(6, LOW);
      Serial.println("I have received b");
      delay(1000);
      break;
    case 'c':
      digitalWrite(2, LOW);
      digitalWrite(3, LOW);
      digitalWrite(4, HIGH);
      digitalWrite(5, LOW);
      digitalWrite(6, LOW);
      Serial.println("I have received c");
      delay(1000);
      break;
    case 'd':
      digitalWrite(2, LOW);
      digitalWrite(3, LOW);
      digitalWrite(4, LOW);
      digitalWrite(5, HIGH);
      digitalWrite(6, LOW);
      Serial.println("I have received d");
      break;
    case 'e':
      digitalWrite(2, LOW);
      digitalWrite(3, LOW);
      digitalWrite(4, LOW);
      digitalWrite(5, LOW);
      digitalWrite(6, HIGH);
      Serial.println("I have received: e");
      delay(1000);
      break;
    case 'Invalid':
      digitalWrite(2, LOW);
      digitalWrite(3, LOW);
      digitalWrite(4, LOW);
      digitalWrite(5, LOW);
      digitalWrite(6, LOW);
      Serial.println("I have received an invalid character");
      delay(1000);
      break;
  }
  iB2 = incomingByte;
}