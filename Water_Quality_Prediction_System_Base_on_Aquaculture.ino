#include "ph.h"
#include "water_temperature.h"
#include "bt.h"
#include <Servo.h>
Servo myservo;

void setup() {
  Serial.begin(9600);
  water_temperature_setup();
  bt_setup();
  myservo.attach(9);
}

void loop() {
  water_temperature_start();
  ph_start();
  bt_send(water_temperature_raw_val, ph_raw_val);
  myservo.write(180);
}
