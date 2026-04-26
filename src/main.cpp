#include <Arduino.h>      // ← ADD THIS
#include <BleKeyboard.h>

BleKeyboard bleKeyboard("ESP32 Macropad", "DIY", 100);

const int buttons[] = {12, 14, 27, 25};
const int NUM_BUTTONS = 4;

void setup() {
  Serial.begin(115200);
  bleKeyboard.begin();

  for (int i = 0; i < NUM_BUTTONS; i++) {
    pinMode(buttons[i], INPUT_PULLUP);
  }
}

void loop() {
  if (!bleKeyboard.isConnected()) return;

  if (digitalRead(buttons[0]) == LOW) {
    bleKeyboard.press(KEY_LEFT_CTRL);
    bleKeyboard.press('c');
    delay(100);
    bleKeyboard.releaseAll();
    delay(300);
  }

  if (digitalRead(buttons[1]) == LOW) {
    bleKeyboard.press(KEY_LEFT_CTRL);
    bleKeyboard.press('v');
    delay(100);
    bleKeyboard.releaseAll();
    delay(300);
  }

  if (digitalRead(buttons[2]) == LOW) {
    bleKeyboard.press(KEY_LEFT_CTRL);
    bleKeyboard.press('z');
    delay(100);
    bleKeyboard.releaseAll();
    delay(300);
  }

  if (digitalRead(buttons[3]) == LOW) {
  bleKeyboard.press(KEY_LEFT_CTRL);
  bleKeyboard.press('y');
  delay(100);
  bleKeyboard.releaseAll();
  delay(300);
  }
}