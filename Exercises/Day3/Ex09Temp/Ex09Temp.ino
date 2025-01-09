
#define READPIN A0 


void setup() {
  // put your setup code here, to run once:
//pinMode(READPIN, INPUT); 
Serial.begin(115200);

}

void loop() {
  // put your main code here, to run repeatedly:
int a = analogRead(READPIN); 
a = map(a,0,1023,0,5000);
float b = (float)a;
b = (b/10);
Serial.print(b); 
Serial.print(u8"\u00b0");
//Serial.write(176);
Serial.write(67);
Serial.println();
delay(200);

}
