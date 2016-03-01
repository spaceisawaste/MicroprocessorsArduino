void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
float voltage=analogRead(A0);
Serial.println((voltage/1024.0)*5.0);
  delay(100);
}
