#include <Arduboy2.h>
#include <ArduboyPlaytune.h>

// arduboy
Arduboy2 arduboy;
// audio
ArduboyPlaytune tunes(arduboy.audio.enabled);

// sound data
const byte score[] PROGMEM = {
  0x90,48, 0x01,0xf4, 0x80, // Do  500ms
  0x90,50, 0x01,0xf4, 0x80, // Re  500ms
  0x90,52, 0x01,0xf4, 0x80, // Mi  500ms
  0x90,53, 0x01,0xf4, 0x80, // Fa  500ms
  0x90,55, 0x01,0xf4, 0x80, // Sol 500ms
  0x90,57, 0x01,0xf4, 0x80, // La  500ms
  0x90,59, 0x01,0xf4, 0x80, // Ti  500ms
  0x90,60, 0x01,0xf4, 0x80, // Do  500ms
  0xf0                      // End of score
};

void setup() {
  // initialize Arduboy
  arduboy.begin();
  // set frame rate to 15FPS
  arduboy.setFrameRate(15);
  
  // audio setup
  tunes.initChannel(PIN_SPEAKER_1);
#ifndef AB_DEVKIT
  // if not a Devkit
  tunes.initChannel(PIN_SPEAKER_2);
#else
  // if it's a Devkit
  tunes.initChannel(PIN_SPEAKER_1); // use the same pin for both channels
  tunes.toneMuteScore(true);        // mute the score when a tone is sounding
#endif
}

void loop() {
  // if it is not time for the next frame, go back to the start of the loop 
  if (!arduboy.nextFrame()) return;

  // use justPressed() as necessary to determine if a button was pressed
  arduboy.pollButtons();

  // A_BUTTON pressed
  if(arduboy.justPressed(A_BUTTON)) {
    // if a score is not currently playing
    if (!tunes.playing()) {
      // play score
      tunes.playScore(score);
    }
  }

  // B_BUTTON pressed
  if (arduboy.justPressed(B_BUTTON)) {
    // A4 100ms
    tunes.tone(440, 100);
  }
}
