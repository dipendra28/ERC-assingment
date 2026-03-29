#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_LEDBackpack.h>

Adafruit_7segment display = Adafruit_7segment();

#define LED_PIN    13
#define BUZZER_PIN  8
#define BUTTON_PIN  2

void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  randomSeed(analogRead(0));

  display.begin(0x70);
  display.setBrightness(15);

  // Show dashes at start
  display.writeDigitRaw(0, 0x40);
  display.writeDigitRaw(1, 0x40);
  display.writeDigitRaw(3, 0x40);
  display.writeDigitRaw(4, 0x40);
  display.writeDisplay();
  delay(2000);
}

void loop() {
  digitalWrite(LED_PIN, LOW);

  // Show "----"
  display.writeDigitRaw(0, 0x40);
  display.writeDigitRaw(1, 0x40);
  display.writeDigitRaw(3, 0x40);
  display.writeDigitRaw(4, 0x40);
  display.writeDisplay();

  delay(random(2000, 5000));

  // LED ON
  digitalWrite(LED_PIN, HIGH);
  long startTime = millis();

  // Wait for button
  while (digitalRead(BUTTON_PIN) == HIGH) {}

  long reactionTime = millis() - startTime;

  // Beep
  digitalWrite(BUZZER_PIN, HIGH);
  delay(200);
  digitalWrite(BUZZER_PIN, LOW);
  digitalWrite(LED_PIN, LOW);

  // Show reaction time
  display.print((int)reactionTime);
  display.writeDisplay();

  delay(3000);
}
