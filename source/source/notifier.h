class Notifier
{
  public:
    void setup() {
      setupNotifier();
    }

    bool hasNotification() {
      return notification;
    }

    bool hasScheduled(){
      return scheduled;
    }

    void handleNotifications() {
      if (ButtonHandler.isPressed()) {
        notification = false;
        LEDHandler.setLED(false);
      }
      else
      {
        blinkCurrent = millis();  //get the current "time" (actually the number of milliseconds since the program started)
        if (blinkCurrent - blinkStart >= period)  //test whether the period has elapsed
        {
          LEDHandler.setLED(!LEDHandler.getLED());
          blinkStart = blinkCurrent;
        }
      }
    }
    void handleScheduale(){
      unsigned long notifCurrent = millis();

      if(notifCurrent == notifGoal){
        notification = true;
        scheduled = false;
        Serial.println(String("schedualeNotification - " + millis()));
      }
      
    }

    void schedualeNotification(unsigned long timer){
      scheduled = true;
      notifGoal = millis() + timer;
      Serial.println(String("schedualeNotification - " + millis()));
    }
    

  private:
    bool notification;
    bool scheduled;
    unsigned long blinkStart;
    unsigned long blinkCurrent;
    const unsigned long period = 1000;
    
    unsigned long notifGoal;

    void setupNotifier()
    {
      notification = false;
      scheduled = false;
      blinkStart = millis();
    }

};

Notifier notifier;
