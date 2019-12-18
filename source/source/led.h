class LEDHandler
{
  public:
    void setup() {
      setupLED();
    }
    void setLED(bool param) {
      if (param) digitalWrite(LED_PIN, HIGH);
      else if (!param) digitalWrite(LED_PIN, LOW);
    }
    bool getLED(){
      return digitalRead(LED_PIN);
    }

  private:
    void setupLED()
    {
      pinMode(LED_PIN, OUTPUT);
    }
};

LEDHandler LEDHandler;
