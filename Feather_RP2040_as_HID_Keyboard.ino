// these are libraries, dont worry about them
#include "Adafruit_NeoKey_1x4.h"
#include "seesaw_neopixel.h"
#include "Keyboard.h"

// this line defines what port the keybaord is connected to
Adafruit_NeoKey_1x4 neokey(NEOKEY_1X4_ADDR, &Wire1); 

// these lines start the keyboard as a human interface device
void setup() { 
  pinMode(LED_BUILTIN, OUTPUT);
  Keyboard.begin();
  neokey.begin(0x30);

}

void loop() { 
  digitalWrite(LED_BUILTIN, HIGH); 

// this line checks if a key has been pressed
  uint8_t buttons = neokey.read(); 

    if (buttons & (1<<0)) { // if the first button is pressed it will do the following
    neokey.pixels.setPixelColor(0, 0x00FFFF); // sets the light color to blue
//    neokey.pixels.show(); // displays light when key pressed -disabled-
    Keyboard.print("kdt"); // types the letters kdt, set to lower case so when the keyboard has caps lock it'll show as caps
    delay(10); // waits 10 miliseconds for debounce
    Keyboard.press(KEY_TAB); // presses special key TAB
    delay(10);
    Keyboard.releaseAll(); // this will release all keys, as through you took your finger off the keyboard, otherwise it'll be like you're holding TAB
    delay(10); 
    Keyboard.print("0505"); // types the charecters 0505
    delay(10);
    Keyboard.press(KEY_KP_ENTER); // presses special key ENTER
    delay(10);
    Keyboard.releaseAll(); 
    delay(100);
  } else { // this is where you would have the board do something when not pressing a button, in this case it does nothing. 
  }

    if (buttons & (1<<1)) {
    neokey.pixels.setPixelColor(1, 0x00FF00); // green
//    neokey.pixels.show();
    Keyboard.print("104ns");
    delay(10);
    Keyboard.press(KEY_TAB);
    delay(10);
    Keyboard.releaseAll();
    delay(100);
  } else {
  }

    if (buttons & (1<<2)) {
    neokey.pixels.setPixelColor(2, 0xFFFF00); // yellow
//    neokey.pixels.show();
    Keyboard.print("299k");
    delay(10);
    Keyboard.press(KEY_TAB);
    delay(10);
    Keyboard.releaseAll();
    delay(100);
  } else {
  }
  
  if (buttons & (1<<3)) {
    neokey.pixels.setPixelColor(3, 0xFF0000); // red
//    neokey.pixels.show();
    Keyboard.print("599k");
    delay(10);
    Keyboard.press(KEY_TAB);
    delay(10);
    Keyboard.releaseAll();
    delay(100);
  } else {
  }

    Keyboard.releaseAll();
    neokey.pixels.setPixelColor(0, 0); // sets key light to color off
    neokey.pixels.setPixelColor(1, 0); // sets key light to color off
    neokey.pixels.setPixelColor(2, 0); // sets key light to color off
    neokey.pixels.setPixelColor(3, 0); // sets key light to color off
    neokey.pixels.show(); // shows the light color off
    delay(50);

}
