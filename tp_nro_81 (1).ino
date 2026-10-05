// Definiciones de notas musicales
#define NOTE_C4  262
#define NOTE_D4  294
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_G4  392
#define NOTE_A4  440
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_D5  587
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_G5  784
#define NOTE_A5  880
#define NOTE_B5  988

const int buzzerPin = 8;
const int tempo = 100; // BPM

// Canal 1: 30 notas + silencios
int notes[] = {
  NOTE_C4, NOTE_D4, NOTE_E4, NOTE_F4, NOTE_G4, NOTE_A4, NOTE_B4, NOTE_C5,
  NOTE_B4, NOTE_A4, NOTE_G4, NOTE_F4, NOTE_E4, NOTE_D4, NOTE_C4, 0,
  NOTE_E4, NOTE_G4, NOTE_C5, NOTE_D5, NOTE_E5, NOTE_F5, NOTE_G5, NOTE_A5,
  NOTE_G5, NOTE_F5, NOTE_E5, NOTE_D5, NOTE_C5, NOTE_B4
};

int figures[] = {
  8, 8, 8, 8, 8, 8, 8, 8,
  8, 8, 8, 8, 8, 8, 8, -8,
  4, 4, 4, 4, 8, 8, 8, 8,
  16, 16, 16, 16, 8, 8
};

// Funciones
void playNote(int note, int duration) {
  if (note > 0) {
    tone(buzzerPin, note, duration);
  }
  delay(duration);
}

int cuadritosToDuration(int cuadritos) {
  int duracionRedonda = (60000 * 4) / tempo;
  return duracionRedonda / cuadritos;
}

void playMelody(const int notes[], const int figures[], int length) {
  for (int i = 0; i < length; i++) {
    int duracion = cuadritosToDuration(abs(figures[i]));
    playNote(notes[i], duracion);
  }
}

void pauseBetweenLoops(int seconds) {
  delay(seconds * 1000);
}

void setup() {}

void loop() {
  playMelody(notes, figures, sizeof(notes)/sizeof(notes[0]));
  pauseBetweenLoops(2); // espera 2 segundos antes de repetir
}
