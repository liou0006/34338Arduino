void setup(){
  Serial.begin(9600);
  char mychar = '4';
  int val = mychar - '0';
  mychar = (char) (val + 'A' - 1);
    Serial.println(mychar);
}

void loop(){
  
}