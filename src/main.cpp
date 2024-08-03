#include <Arduboy2.h>
#include <ArduboyTones.h>

Arduboy2 arduboy;
ArduboyTones sound(arduboy.audio.enabled);

const uint16_t scale[] PROGMEM = {
  NOTE_C3,500, NOTE_D3,500, NOTE_E3,500, NOTE_F3,500,
  NOTE_G3,500, NOTE_A4,500, NOTE_B4,500, NOTE_C4,500,
  TONES_END
};

void setup() {
  arduboy.begin();
  sound.tones(scale);
}

void loop() {
}

