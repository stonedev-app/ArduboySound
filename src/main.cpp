#include <Arduboy2.h>
#include <ArduboyTones.h>

// arduboy
Arduboy2 arduboy;
// sound
ArduboyTones sound(arduboy.audio.enabled);

// sound data (Do Re Mi Fa Sol La Ti Do)
const uint16_t scale[] PROGMEM = {
  NOTE_C3,500, NOTE_D3,500, NOTE_E3,500, NOTE_F3,500,
  NOTE_G3,500, NOTE_A4,500, NOTE_B4,500, NOTE_C4,500,
  TONES_END
};

void setup() {
  // initialize Arduboy
  arduboy.begin();
  // set frame rate to 15FPS
  arduboy.setFrameRate(15);
}

void loop() {
  // if it is not time for the next frame, go back to the start of the loop 
  if (!arduboy.nextFrame()) return;

  // use justPressed() as necessary to determine if a button was pressed
  arduboy.pollButtons();

  // A_BUTTON pressed
  if(arduboy.justPressed(A_BUTTON)) {
    if (!sound.playing()) {
      // start sound
      sound.tones(scale);
    }
  }
}
