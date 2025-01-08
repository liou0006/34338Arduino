int incomingByte = 0;

void setup()
{
    Serial.begin(115200);
    pinMode(2, OUTPUT);
    pinMode(3, OUTPUT);
    pinMode(4, OUTPUT);
    pinMode(5, OUTPUT);
    pinMode(6, OUTPUT);
}

void loop()
{

    incomingByte = Serial.read();

    switch ((char)incomingByte)
    {
    case 'a':
        digitalWrite(2, HIGH);
        Serial.print("I have received: ");
        Serial.println((char)incomingByte);
        break;
    case 'b':
        digitalWrite(3, HIGH);
        Serial.print("I have received: ");
        Serial.println((char)incomingByte);
        break;
    case 'c':
        digitalWrite(4, HIGH);
        Serial.print("I have received: ");
        Serial.println((char)incomingByte);
        break;
    case 'd':
        digitalWrite(5, HIGH);
        Serial.print("I have received: ");
        Serial.println((char)incomingByte);
        break;
    case 'e':
        digitalWrite(6, HIGH);
        Serial.print("I have received: ");
        Serial.println((char)incomingByte);
        break;
    default:
        digitalWrite(2, LOW);
        digitalWrite(3, LOW);
        digitalWrite(4, LOW);
        digitalWrite(5, LOW);
        digitalWrite(6, LOW);
        Serial.println("I have received an invalid character");
        break;
    }
}