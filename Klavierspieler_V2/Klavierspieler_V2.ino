#include "BluetoothSerial.h"

#define F1 13
#define F2 12
#define F3 14
#define F4 27
#define b F2
#define A F1
#define G F3


bool EMSon = true;

BluetoothSerial SerialBT;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  SerialBT.begin("Klavierspieler");
  pinMode(F1, OUTPUT);
  pinMode(F2, OUTPUT);
  pinMode(F3, OUTPUT);
  pinMode(F4, OUTPUT);
  digitalWrite(F1, HIGH);
  digitalWrite(F2, HIGH);
  digitalWrite(F3, HIGH);
  digitalWrite(F4, HIGH);
}

void loop() {

if(SerialBT.available()) {
  switch (SerialBT.read()) {
    case 0x02: digitalWrite(F1, LOW); break;
    case 0x03: digitalWrite(F2, LOW); break;
    case 0x04: digitalWrite(F3, LOW); break;
    case 0x05: digitalWrite(F4, LOW); break;
    case 0x06: digitalWrite(F1, HIGH); break;
    case 0x07: digitalWrite(F2, HIGH); break;
    case 0x08: digitalWrite(F3, HIGH); break;
    case 0x09: digitalWrite(F4, HIGH); break;
    case 0x0A: Lied1(); break;
    case 0x0B: Lied2(); break;
    case 0x0C: Lied3(); break;
    case 0x0D: Lied4(); break;
    default: break;
  }
}
  EMSon = true;
  delay(20);
}

void Lied1() {
      Ton(b, 2000, 0);
      Ton(A, 1000, 0);
      Ton(b, 1000, 0);
      Ton(G, 2000, 0);
}

void Lied2() {
      Ton(b, 1000, 0);
      Ton(A, 500, 0);
      Ton(b, 500, 0);
      Ton(G, 1000, 0);
}

void Lied3() {
      Ton(b, 500, 0);
      Ton(A, 250, 0);
      Ton(b, 250, 0);
      Ton(G, 500, 0);
}

void Lied4() {
      Ton(b, 250, 0);
      Ton(A, 125, 0);
      Ton(b, 125, 0);
      Ton(G, 250, 0);
}

void Ton(int pin, int AD, int WD) {
  if (SerialBT.read() == 0x01 || !EMSon) {
  EMSon = false;
  return;
  }
  digitalWrite(pin, LOW);
  delay(AD);
  digitalWrite(pin, HIGH);
  delay(WD);
}