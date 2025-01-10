void setup() {
  Serial.begin(115200);
}

int var1 = 10; 
int var2 = 20;  

void loop() {
  Serial.println(var1);
  Serial.println(var2);
  swap(&var1,&var2);
  delay(500); 
  Serial.println(var1);
  Serial.println(var2);
  delay(3000);
}

int tempA = 0; 

void swap(int *pointer_a, int *pointer_b) {

tempA = *pointer_a; 
*pointer_a = *pointer_b; 
*pointer_b = tempA;
  
}
