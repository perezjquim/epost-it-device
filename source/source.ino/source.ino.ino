#include <SoftwareSerial.h>   //Software Serial Port
#define RxD 10
#define TxD 11
#define SERIAL_BAUD 9600
#define BLE_BAUD 115200
#define DEBUG_ENABLED  0
bool has_started_loop = false;

SoftwareSerial BLE(RxD, TxD);

void setup()
{
  Serial.println("-- SETUP --");
  setupPins();
  setupSerial();
  setupBLE();
}

void loop()
{
  if (!has_started_loop)
  {
    has_started_loop = true;
    Serial.println("-- LOOP BEGIN --");
  }

  if (BLE.available())
  { //check if there's any data sent from the remote BLE shield
    onBLEAvailable();
  }

  if (Serial.available())
  { //check if there's any data sent from the local serial terminal, you can add the other applications here
    onSerialAvailable();
  }
}

void setupPins()
{
  pinMode(RxD, INPUT);
  pinMode(TxD, OUTPUT);
}

void setupSerial()
{
  Serial.begin(SERIAL_BAUD);
}

void setupBLE()
{
  BLE.begin(BLE_BAUD); //Set BLE BaudRate to default baud rate 9600
  BLE.print("AT+CLEAR"); //clear all previous setting
  BLE.print("AT+ROLE1"); //set the bluetooth name as a master
  BLE.print("AT+SAVE1");  //don't save the connect information
}

void onBLEAvailable()
{
  char sData = BLE.read();

  if (!isEmpty(sData))
  {
    Serial.println(" >> BLE");

    Serial.print(sData);

    while (BLE.available())
    {
      sData = BLE.read();

      if(isEmpty(sData)) break;
            
      Serial.print(sData);
    }

    Serial.println(" << BLE");
  }
}

void onSerialAvailable()
{
  char sData = Serial.read();

  if (!isEmpty(sData))
  {
    BLE.print(sData);

    while (Serial.available())
    {
      char sData = Serial.read();

      if(isEmpty(sData)) break;
      
      BLE.print(sData);
    }
  }
}

bool isEmpty(char aData)
{
  return aData == '\0' || aData == (char) 0;
}

