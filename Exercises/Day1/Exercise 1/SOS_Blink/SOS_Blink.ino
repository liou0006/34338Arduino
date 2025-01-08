
#define SBLINK 200
#define LBLINK 600
#define OWAIT 200
#define TWAIT 600

// the setup function runs once when you press reset or power the board
void setup()
{
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
};

// the loop function runs over and over again forever
void loop()
{
  // Making the letter S in Morse
  for (int i = 0; i < 3; i++)
  {
    dot();
  }

  delay(TWAIT);

  // Making the letter O
  for (int i = 0; i < 3; i++)
  {
    dash();
  }

  delay(TWAIT);

  // Making the letter S in Morse
  for (int i = 0; i < 3; i++)
  {
    dot();
  }

};

void dot()
{
  digitalWrite(LED_BUILTIN, HIGH);
  delay(SBLINK);
  digitalWrite(LED_BUILTIN, LOW);
  delay(OWAIT);
}

void dash()
{
  digitalWrite(LED_BUILTIN, HIGH);
  delay(LBLINK);
  digitalWrite(LED_BUILTIN, LOW);
  delay(OWAIT);
}