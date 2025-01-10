struct Animal {
  char family[20];
  char name[20];
  float weight;
  bool alive;
  char PoC[20];
};


void setup() {
  Serial.begin(9600);
}

void loop() {


  //struct Animal unicorn = { "Horse", "Martha", 100.0, true, "Narnia" };
  //struct Animal hummingbird = { "Bird", "Helena", 0.1, true, "Africa" };


  char boobs[20] = "Chicken";

  struct Animal unicorn;

  strncpy(unicorn.name, boobs, sizeof(unicorn.name)-1);

  Serial.println("Unicorn name: ");
  Serial.println(unicorn.name);
  delay(10000);


  // printAnimal(&unicorn);
  // printAnimal(&hummingbird);

  // delay(2000);
  // swapWeight(&unicorn, &hummingbird);
  // Serial.println("Swapped weight");
  // Serial.println("Unicorn weight: ");
  // Serial.println(unicorn.weight);
  // Serial.println("Hummingbird weight: ");
  // Serial.println(hummingbird.weight);
  // delay(10000);
}

void printAnimal(struct Animal *a) {
  Serial.print("Family: ");
  Serial.println(a->family);
  Serial.print("Name: ");
  Serial.println(a->name);
  Serial.print("Weight: ");
  Serial.println(a->weight);
  Serial.print("Alive: ");
  Serial.println(a->alive);
  Serial.print("PoC: ");
  Serial.println(a->PoC);
}

void swapWeight(struct Animal *a, struct Animal *b) {
  float temp = a->weight;
  a->weight = b->weight;
  b->weight = temp;
}
