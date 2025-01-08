#define R_LED 2 
#define G_LED 3 
#define B_LED 4 

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

digitalWrite(R_LED, r); 
digitalWrite(G_LED, g); 
digitalWrite(B_LED, b); 

}