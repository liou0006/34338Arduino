char incomingByte = 0;

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

    switch (incomingByte)
    {
    case 'a':
         digitalWrite(2, HIGH); 
        break;
    case 'b':
         digitalWrite(3, HIGH); 
        break;
    case 'c':
         digitalWrite(4, HIGH); 
        break;
    case 'd':
         digitalWrite(5, HIGH); 
        break;
    case 'e':
         digitalWrite(6, HIGH); 
        break;
    default:
         digitalWrite(2, LOW); 
         digitalWrite(3, LOW); 
         digitalWrite(4, LOW); 
         digitalWrite(5, LOW); 
         digitalWrite(6, LOW); 
        break;
    }
}