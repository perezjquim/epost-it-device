class TagHandler
{
  public:
    void setup() {
      setupTag();
    }
    void handleTags(String param) {
      int delimiter = 0;
      int delimiter_2 = 0;
      do {
        delimiter_2 = param.indexOf(CSV_DELIMITER, delimiter);
        String tag = param.substring(delimiter, delimiter_2);
        delimiter = delimiter_2 + 1;

        if (!isTag(tag)) {
          LEDHandler.setLED(false);
          return;
        }
      } while (delimiter > 0);

      LEDHandler.setLED(true);

    }

    bool isTag(String param)
    {
      if (!param.equals(""))
      {
        for (int i = 0; i < MAX_TAGS; i++)
          if (tags[i].equals(param)) return true;

      }
      return false;
    }

  private:
    String tags[MAX_TAGS] = {"arduino", "led", "bt", "button", "wire", "pin", "shield", "interaction", "embodied", ""};
    void setupTag()
    {
      pinMode(LED_BUILTIN, OUTPUT);
    }
};

TagHandler TagHandler;
