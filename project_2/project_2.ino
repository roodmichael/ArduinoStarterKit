int switchState = 0;

void setup() {
  pinMode(2, INPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
}

void loop() {
  switchState = digitalRead(2);

  if (switchState == LOW) {
    // button is not pressed
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW); 
  } else {
    // toggle red leds when pressed
    digitalWrite(3, LOW);
    digitalWrite(4, !digitalRead(4));
    digitalWrite(5, !digitalRead(5));
    delay(250);
  }
}
