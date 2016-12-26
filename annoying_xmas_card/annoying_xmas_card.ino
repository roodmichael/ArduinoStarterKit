int speakerPin = 8;
int ledPin2 = 2;
int ledPin3 = 3;
int ledPin4 = 4;

int length = 54;
char notes[] = "gfedcdecdefdedcbc gfedcdecdefdedcbc defdefgd efgaBCBag";
int beats[] = { 2,1,2,2,2,2,2,2,1,1,1,1,2,2,2,2,2,2,2,1,2,2,2,2,2,2,1,1,1,1,2,2,2,2,2,2,2,1,1,1,2,1,1,2,2,1,1,2,1,1,2,2,2,2 };
int tempo = 300;

void lightSwitch(bool led1, bool led2, bool led3) {
  digitalWrite(ledPin2, led1);
  digitalWrite(ledPin3, led2);
  digitalWrite(ledPin4, led3);
}

void lightPattern(int tone) {
  lightSwitch(LOW, LOW, HIGH);
  
  if (tone <= 1700) {
    lightSwitch(LOW, HIGH, HIGH); 
  }
  
  if (tone <= 1432) {
    lightSwitch(HIGH, HIGH, HIGH);
  }
}
void playTone(int tone, int duration) {
  for (long i = 0; i < duration * 1000L; i += tone * 2) {
    digitalWrite(speakerPin, HIGH);
    lightPattern(tone);
    delayMicroseconds(tone);
    digitalWrite(speakerPin, LOW);
    lightSwitch(LOW, LOW, LOW);
    delayMicroseconds(tone);
  }
}

void playNote(char note, int duration) {
  char names[] = { 'b', 'c', 'd', 'e', 'f', 'g', 'a', 'B', 'C' };
  int tones[] = { 2015, 1915, 1700, 1519, 1432, 1275, 1136, 1014, 1000 };

  // play the tone corresponding to the note name
  for (int i = 0; i < 8; i++) {
    if (names[i] == note) {
      playTone(tones[i], duration);
    }
  }
}

void setup() {
  pinMode(speakerPin, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
}

void loop() {
  for (int i = 0; i < length; i++) {
    if (notes[i] == ' ') {
      lightSwitch(LOW, LOW, LOW);
      delay(beats[i] * tempo); // rest
    } else {
      playNote(notes[i], beats[i] * tempo);
    }

    // pause between notes
    delay(tempo / 2); 
  }
}
