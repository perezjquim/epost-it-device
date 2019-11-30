class LEDHandler
{
  public:
    void setup(){
      setupLED();
    }
    bool handleLED(String param){
      //if (param.equals("")
      return true;
    }

  private:
    void setupLED()
    {
      pinMode(LED_BUILTIN, OUTPUT);
    }
};

LEDHandler LEDHandler;
