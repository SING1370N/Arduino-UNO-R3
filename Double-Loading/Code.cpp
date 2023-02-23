int latchPin = 5; // 74HC595 підключений до 5 піна (перемикач)
int clockPin = 6; // 74HC595 підключений до 6 піна
int dataPin = 4;	// Данні для 74HC595 підключений до 4 пина
bool revers = false; // Реверс
int pos = 4; // Позиція в масиві
int time_pause = 150; // Час зупинки
byte numbers[6] = { B10000000, B00100000, B00010000, B00001000, B00000010, B00000100};


void setup() {
   // Встановлюємо режим роботи пінів OUTPUT
   pinMode(latchPin, OUTPUT);
   pinMode(clockPin, OUTPUT);
   pinMode(dataPin, OUTPUT);
   // Ставимо HIGH на "перемикач", щоб регістр не приймав сигнал
   digitalWrite(latchPin, HIGH);
}


void loop() {   
  if (pos == 6) pos = 0;
  else if (pos  < 0) pos = 5;
  digitalWrite(latchPin, LOW);
  // Перемикаємо вогники:
  shiftOut(dataPin, clockPin, LSBFIRST, numbers[pos]);  
  shiftOut(dataPin, clockPin, LSBFIRST, numbers[5-pos]);  
  // Щоб світлодіоди загорілися:
  digitalWrite(latchPin, HIGH);
  // Логіка реверсу + пауза:
  if (revers) pos++;
  else pos--;
  delay(time_pause);
}
