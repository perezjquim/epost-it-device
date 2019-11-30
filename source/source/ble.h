class BLEHandler
{
  public:
    void setup() {
      setupPins();
      setupSerial();
      setupBLE();
    }
    String readFromBLE()
    {
      String str = "";
      char sData = bleSS.read();

      if (!isEmpty(sData))
      {
        str = String(str + sData);
        while (bleSS.available())
        {
          sData = bleSS.read();
          if (isEmpty(sData)) break;
          str = String(str + sData);
        }
      }
      if (debug) Serial.println("BLE: " + str);
      return str;
    }
    void sendToBLE(String str)
    {
      bleSS.println(str);
    }
    String readFromSerial()
    {
      String str = "";
      str = Serial.readString();
      if (debug == true) Serial.println("SS: " + str);
      return str;
    }

  private:
    void setupSerial()
    {
      Serial.begin(SERIAL_BAUD);
      pinMode(LED_BUILTIN, OUTPUT);
    }
    void setupBLE()
    {
      bleSS.begin(BLE_BAUD);
    }
    void setupPins()
    {
      pinMode(RxD, INPUT);
      pinMode(TxD, OUTPUT);
    }

    bool isEmpty(char aData)
    {
      return aData == '\0' || aData == (char) 0;
    }
};

BLEHandler BLEHandler;
