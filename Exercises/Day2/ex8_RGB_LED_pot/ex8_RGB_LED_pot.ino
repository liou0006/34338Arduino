#define R_LED 3 
#define G_LED 5 
#define B_LED 6 

int val[3];
int r_input = 0; 
int g_input = 0; 
int b_input = 0;

void setup() {
  pinMode(R_LED,OUTPUT);
  pinMode(G_LED,OUTPUT);
  pinMode(B_LED,OUTPUT);
  Serial.begin(115200);
  pinMode(0,INPUT);

}

void loop() {

 int a = analogRead(A0);
 int val = round(a/2.6)-2;
 if (val < 0) {
  val = 0;
 }
 Serial.println(val);
 delay(20);
 setColor(255,0,val);

}

void setColor(int r, int g, int b) { 

analogWrite(R_LED, r); 
analogWrite(G_LED, g); 
analogWrite(B_LED, b); 

}