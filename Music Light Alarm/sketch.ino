int l = 7;      // LED
int buz = 2;    // Buzzer

// ترددات نغمات موسيقية (دو، ري، مي...)
int melody[] = {262, 294, 330, 349, 392, 440, 494};  
// 262Hz = C4, 294Hz = D4, 330Hz = E4, ...

int noteDurations[] = {4, 4, 4, 4, 4, 4, 4}; // طول كل نغمة (ربع)

void setup() {
  pinMode(l, OUTPUT);
  pinMode(buz, OUTPUT);
}

void loop() {
  for (int thisNote = 0; thisNote < 7; thisNote++) {
    // مدة النغمة
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(buz, melody[thisNote], noteDuration);

    // ضو الليد بنفس وقت النغمة
    digitalWrite(l, HIGH);
    delay(noteDuration);
    digitalWrite(l, LOW);

    // فاصل قصير بين النغمات
    delay(100);
  }

  // توقف بسيط بعد المقطع
  delay(1000);
}

