#define GREEN 2 
#define YELLOW 3 
#define RED 4
#define TIME 750
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(GREEN,OUTPUT); //grøn
  pinMode(YELLOW,OUTPUT); //gul
  pinMode(RED,OUTPUT); //rød

  Serial.begin(115200);
}  

void loop() {
 
 Serial.println("Stop!");
 red();
 Serial.println("Get Ready!");
 yellowRed();
 Serial.println("Drive!");
 green();
 Serial.println("Slow down!");
 yellow();
 Serial.println("Stop!");
 red();
 
  
}


void red() { 
  digitalWrite(RED, HIGH); 
  delay(4000);
  digitalWrite(RED,LOW);
}

void yellowRed() {
  digitalWrite(RED, HIGH); 
  digitalWrite(YELLOW, HIGH); 
  delay(3000);
  digitalWrite(RED, LOW); 
  digitalWrite(YELLOW, LOW); 
}

void green(){
  digitalWrite(GREEN,HIGH); 
  delay(3000); 
  digitalWrite(GREEN,LOW);
}

void yellow(){
  digitalWrite(YELLOW,HIGH); 
  delay(3000); 
  digitalWrite(YELLOW,LOW);
}

void binCount(){

for (int i=0;i<8;i++) {

switch(i){
  case 1: 
  digitalWrite(RED,HIGH);
  delay(TIME);
  digitalWrite(RED,LOW);
  break;

 case 2: 
  digitalWrite(YELLOW,HIGH);
  delay(TIME);
  digitalWrite(YELLOW,LOW);
  break;

 case 3: 
  digitalWrite(RED,HIGH);
  digitalWrite(YELLOW,HIGH);
  delay(TIME);
  digitalWrite(RED,LOW);
  digitalWrite(YELLOW,LOW);
  break;

   case 4: 
  digitalWrite(GREEN,HIGH);
  delay(TIME);
  digitalWrite(GREEN,LOW);
  break;

   case 5: 
  digitalWrite(RED,HIGH);
  digitalWrite(GREEN,HIGH);
  delay(TIME);
  digitalWrite(RED,LOW);
  digitalWrite(GREEN,LOW);
  
  break;

   case 6: 
  digitalWrite(YELLOW,HIGH);
  digitalWrite(GREEN,HIGH);
  delay(TIME);
  digitalWrite(YELLOW,LOW);
  digitalWrite(GREEN,LOW);
  
  break;

   case 7: 
  digitalWrite(RED,HIGH);
  digitalWrite(YELLOW,HIGH);
  digitalWrite(GREEN,HIGH);
  delay(TIME);
  digitalWrite(RED,LOW);
  digitalWrite(GREEN,LOW);
  digitalWrite(YELLOW,LOW);
  break;

}


}


}
