class LEDHandler
{
  public:
    void setup(){
      setupLED();
    }

  private:
    void setupLED()
    {
      pinMode(LED_BUILTIN, OUTPUT);
    }
};

LEDHandler LEDHandler;
