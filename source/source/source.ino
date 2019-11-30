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

    onMessageReceived(str);
  }

  if (Serial.available())
  { //check if there's any data sent from the local serial terminal, you can add the other applications here
    String str = BLEHandler.readFromSerial();
    BLEHandler.sendToBLE(str);
  }

}

bool onMessageReceived(String str)
{
  int delimiter, delimiter_1, delimiter_2, delimiter_3;

  delimiter = str.indexOf(EPOSTIT_DELIMITER);
  delimiter_1 = str.indexOf(EPOSTIT_DELIMITER, delimiter + 1);
  String ePostit = str.substring(delimiter + 1, delimiter_1);
  if (!ePostit.equals(EPOSTIT_HEADER)) return false;

  delimiter_2 = str.indexOf(EPOSTIT_DELIMITER, delimiter_1 + 1);
  String action = str.substring(delimiter_1 + 1, delimiter_2);

  delimiter_3 = str.indexOf(EPOSTIT_DELIMITER, delimiter_2 + 1);
  String param = str.substring(delimiter_2 + 1, delimiter_3);
}
