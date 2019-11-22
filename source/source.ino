#include <SoftwareSerial.h>   //Software Serial Port
#define RxD 0
#define TxD 1
#define SERIAL_BAUD 9600
#define BLE_BAUD 115200
#define DEBUG_ENABLED  0
int has_started_loop = false;
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
  Serial.println(" >> BLE");

  while (BLE.available())
  {
    char sData = BLE.read();
    Serial.print(sData);
  }

  Serial.println(" << BLE");
}

void onSerialAvailable()
{
  Serial.println(" >> SERIAL");

  while (Serial.available())
  {
    char sData = Serial.read();
    BLE.print(sData);
  }

  Serial.println(" << SERIAL");
}

