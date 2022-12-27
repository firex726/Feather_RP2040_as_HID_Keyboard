#include "Adafruit_NeoKey_1x4.h"
#include "seesaw_neopixel.h"
#include "Keyboard.h"

Adafruit_NeoKey_1x4 neokey(NEOKEY_1X4_ADDR, &Wire1); 

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  Keyboard.begin();

  if (! neokey.begin(0x30)) {     // begin with I2C address, default is 0x30
  }

}

void loop() {

  digitalWrite(LED_BUILTIN, HIGH);

  uint8_t buttons = neokey.read();

    if (buttons & (1<<0)) {
    neokey.pixels.setPixelColor(0, 0x00FFFF); // blue
//    neokey.pixels.show();
    Keyboard.print("abc");
    delay(10);
    Keyboard.press(KEY_TAB);
    delay(10);
    Keyboard.releaseAll();
    delay(10);
    Keyboard.print("1234");
    delay(10);
    Keyboard.press(KEY_KP_ENTER);
    delay(10);
    Keyboard.releaseAll();
    delay(100);
  } else {
  }

    if (buttons & (1<<1)) {
    neokey.pixels.setPixelColor(1, 0x00FF00); // green
//    neokey.pixels.show();
    Keyboard.print("123");
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
    Keyboard.print("123ab");
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
    Keyboard.print("123a");
    delay(10);
    Keyboard.press(KEY_TAB);
    delay(10);
    Keyboard.releaseAll();
    delay(100);
  } else {
  }

    Keyboard.releaseAll();
    neokey.pixels.setPixelColor(0, 0);
    neokey.pixels.setPixelColor(1, 0);
    neokey.pixels.setPixelColor(2, 0);
    neokey.pixels.setPixelColor(3, 0);
    neokey.pixels.show();
    delay(50);

}
