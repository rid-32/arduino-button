#include <Arduino.h>
#include <Ctrl.h>

#define INCREASE_BUTTON 2
#define DECREASE_BUTTON 3

void handle_click(ctrl::Button_Event const *);
void handle_long_click(ctrl::Button_Event const *);

ctrl::Button button(HIGH, INCREASE_BUTTON);
ctrl::Button button2(HIGH, DECREASE_BUTTON);

void setup() {
  Serial.begin(115200);

  pinMode(INCREASE_BUTTON, INPUT_PULLUP);
  pinMode(DECREASE_BUTTON, INPUT_PULLUP);

  button.on("click", handle_click);
  button2.on("click", handle_click);
  button.on("longclick", handle_long_click);
  button2.on("longclick", handle_long_click);
}

void loop() {
  button.listen();
  button2.listen();
}

void handle_click(ctrl::Button_Event const *event) {
  static uint8_t counter = 0;

  if (event->target == INCREASE_BUTTON) {
    counter++;
  }

  if (event->target == DECREASE_BUTTON) {
    counter--;
  }

  Serial.println("Counter: " + String(counter));
}

void handle_long_click(ctrl::Button_Event const *event) {
  static uint8_t long_counter = 0;

  if (event->target == INCREASE_BUTTON) {
    long_counter++;
  }

  if (event->target == DECREASE_BUTTON) {
    long_counter--;
  }

  Serial.println("Long Counter: " + String(long_counter));
}
