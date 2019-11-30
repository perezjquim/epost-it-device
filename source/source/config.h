#include <SoftwareSerial.h>   //Software Serial Port
#define RxD 10
#define TxD 11
#define SERIAL_BAUD 9600
#define BLE_BAUD 115200
#define EPOSTIT_HEADER "EPOSTIT"
#define EPOSTIT_DELIMITER "#"
#define MAX_TAGS 10

SoftwareSerial bleSS(RxD, TxD);
bool debug;
