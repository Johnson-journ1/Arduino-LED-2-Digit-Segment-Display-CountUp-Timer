 int segments[7] = {2,3,4,5,6,7,8};
 int digit_pin[2] = {10,11};
 byte numbers[10] ={
  B1111110,
  B0110000,
  B1101101,
  B1111001,
  B0110011,
  B1011011,
  B1011111,
  B1110000,
  B1111111,
  B1111011
 };
void setup() {
  // put your setup code here, to run once:
  for (int i = 0 ; i < 7 ; i++) {
    pinMode(segments[i], OUTPUT);
  }
  for (int i = 0 ; i < 2; i++){
    pinMode(digit_pin[i], OUTPUT);
  }

}

void loop() {
  // put your main code here, to run repeatedly:
  int count = 0;
  while (count <100){
    for (int i = 0; i < 100; i++){
      display(count);
      delay(10);
    }
    count++;
  }
  

}
void display(int num){
  int tens = num/10;
  int units = num%10;

  digitalWrite(digit_pin[0], LOW);
  digitalWrite(digit_pin[1],HIGH);
  set_segment(numbers[tens]);
  delay(5);

  digitalWrite(digit_pin[0], HIGH);
  digitalWrite(digit_pin[1], LOW);
  set_segment(numbers[units]);
  delay(5);
}

void set_segment(byte pattern){
  for (int i = 0; i < 7; i++){
    digitalWrite(segments[i], bitRead(pattern, 6-i));
  }
} 
