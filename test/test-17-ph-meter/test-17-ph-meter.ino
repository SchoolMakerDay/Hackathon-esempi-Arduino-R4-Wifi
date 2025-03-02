void setup() {
  Serial.begin(9600);

}

void loop() {
  int ar=analogRead(A0);
  Serial.print("lettura: ");
  Serial.println(ar);
  float ph=ar/47.0;
  Serial.print("ph: ");
  Serial.println(ph);
  delay(1000);
}
