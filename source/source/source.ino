#include "config.h"
#include "ble.h"
#include "led.h"

bool has_started_loop = false;
void setup()
{
  Serial.println("-- SETUP --");
  BLEHandler.setup();
  LEDHandler.setup();

  debug = true;
}

void loop()
{ 
  if (!has_started_loop)
  {
    has_started_loop = true;
    Serial.println("-- LOOP BEGIN --");
  }

  if (bleSS.available())
  { //check if there's any data sent from the remote BLE shield
    String str = BLEHandler.readFromBLE();
  }

  if (Serial.available())
  { //check if there's any data sent from the local serial terminal, you can add the other applications here
    String str = BLEHandler.readFromSerial();
    BLEHandler.sendToBLE(str);
  }
}
