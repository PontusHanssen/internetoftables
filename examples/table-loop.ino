
const int UP = D1;
const int DOWN = D2;

void setup() {
  Serial.begin(9600);
  Serial.println("Setup");
 pinMode(UP, OUTPUT);
  pinMode(DOWN, OUTPUT);

  digitalWrite(UP, LOW);
  digitalWrite(DOWN, LOW);
}

void loop() {
  Serial.println("Up!");
  digitalWrite(UP, HIGH);
  delay(5000);
  Serial.println("Sleep");

  digitalWrite(UP, LOW);
  delay(5000);

  Serial.println("Down!");
  digitalWrite(DOWN, HIGH);
  delay(5000);

  Serial.println("Sleep!");
  digitalWrite(DOWN, LOW);
  delay(5000);

}
