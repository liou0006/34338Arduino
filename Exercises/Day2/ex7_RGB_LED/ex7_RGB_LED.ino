#define R_LED 2 
#define G_LED 3 
#define B_LED 4 

int val[3];
int r_input = 0; 
int g_input = 0; 
int b_input = 0;

void setup() {
  pinMode(R_LED,OUTPUT);
  pinMode(G_LED,OUTPUT);
  pinMode(B_LED,OUTPUT);
  Serial.begin(115200);

}

void loop() {

  if (Serial.available() > 0) {
    for (int i = 0; i < 3; i++) {
      val[i] = Serial.parseInt(); 
    }

    
    r_input = val[0];
    g_input = val[1];
    b_input = val[2];

    //debug
    Serial.print("Red: ");
    Serial.print(r_input);
    Serial.print(", Green: ");
    Serial.print(g_input);
    Serial.print(", Blue: ");
    Serial.println(b_input);

    setColor(r_input, g_input, b_input);
  }
}

void setColor(int r, int g, int b) { 

digitalWrite(R_LED, r); 
digitalWrite(G_LED, g); 
digitalWrite(B_LED, b); 

}