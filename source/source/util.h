class Util
{
  public:
    String readFromBLE() {
      String str = "";
      if (Serial.available())
      { //check if there's any data sent from the local serial terminal, you can add the other applications here
        String str = BLEHandler.readFromSerial();
        BLEHandler.sendToBLE(str);
      }
      return str;
    }

  private:

};

Util util;
