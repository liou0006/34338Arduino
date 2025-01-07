
#define SBLINK 500
#define LBLINK 1000
#define WAIT 1000

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  // Making the letter S in Morse
  for (int i = 0; i < 3; i++) {
    delay(SBLINK);                   
    digitalWrite(LED_BUILTIN, HIGH); 
    delay(SBLINK);                  
    digitalWrite(LED_BUILTIN, LOW);  
  }

  delay(WAIT);

//Making the letter O
  for (int i = 0; i < 3; i++) {
    delay(LBLINK);                   
    digitalWrite(LED_BUILTIN, HIGH); 
    delay(LBLINK);                  
    digitalWrite(LED_BUILTIN, LOW);  
  }

  delay(WAIT);

  // Making the letter S in Morse
  for (int i = 0; i < 3; i++) {
    delay(SBLINK);                   
    digitalWrite(LED_BUILTIN, HIGH); 
    delay(SBLINK);                  
    digitalWrite(LED_BUILTIN, LOW);  
  }
}
