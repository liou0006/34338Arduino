#define R_LED 3 
#define G_LED 5 
#define B_LED 6 

void setup() {
  pinMode(R_LED,OUTPUT);
  pinMode(G_LED,OUTPUT);
  pinMode(B_LED,OUTPUT);
  Serial.begin(115200);

}

void loop() {

  setColor(255,0,0);
  delay(2000);
 
  for (int i=0;i<=255;i++) { 
    setColor(255,0,i); 
    Serial.println(i);
    delay(10); 
  }
  Serial.println("now it is full blue and full red");

  for (int i=255; i>=0;i--) { 
    setColor(255,0,i); 
    Serial.println(i);
    delay(10); 
  }

  Serial.println("now it is full red and no blue");
    
}

void setColor(int r, int g, int b) { 

analogWrite(R_LED, r); 
analogWrite(G_LED, g); 
analogWrite(B_LED, b); 

}