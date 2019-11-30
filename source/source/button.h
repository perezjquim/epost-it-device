class ButtonHandler
{
  public:
    void setup() {
      setupBtn();
    }
    bool isPressed() {
      if (digitalRead(BUTTON_PIN) == HIGH) return true;
      return false;
    }

  private:
    void setupBtn()
    {
      pinMode(BUTTON_PIN, INPUT);
    }
};

ButtonHandler ButtonHandler;
