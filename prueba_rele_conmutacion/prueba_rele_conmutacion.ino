const int control=9;
void setup() {
  // put your setup code here, to run once:
      pinMode(control, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
    digitalWrite(control, HIGH);
    delay(4000);
    digitalWrite(control, LOW);
    delay(2000);
}
