#include "BluetoothSerial.h"

const int Touchpin = 13;
const int TouchSchwelle = 25;
const int LEDpin = 12;
const int Relaispin = 14;

int st = 0;

BluetoothSerial SerialBT;

void ohneEMS() {
  int i = millis() - st;
  touchDetachInterrupt(Touchpin);
  digitalWrite(LEDpin, LOW);
  String s = "";
  s += i;
  s += "ms";
  SerialBT.println(s);
  Serial.println(i);
}

void mitEMS() {
  int i = millis() - st;
  touchDetachInterrupt(Touchpin);
  digitalWrite(LEDpin, LOW);
  digitalWrite(Relaispin, LOW);
  
  String s = "";
  s += i;
  s += "ms";
  SerialBT.println(s);
  Serial.println(i);
}

void FingerSteuern() {
  SerialBT.println("FS Aktiv");
  while (true) {
        if (touchRead(Touchpin) < TouchSchwelle) {
          digitalWrite(Relaispin, HIGH);
          digitalWrite(LEDpin, HIGH);
        } else {
          digitalWrite(Relaispin, LOW);
          digitalWrite(LEDpin, LOW);
                  }
        if (SerialBT.available()) {
          int i = SerialBT.readString().toInt();
          //Serial.println(txt);
          if (i == 40) {
            Serial.println("--ms");
            break;
          }
        }
      }
}



void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  SerialBT.begin("Reaktionszeitmesser");
  pinMode(LEDpin, OUTPUT);
  pinMode(Relaispin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (SerialBT.available()) {
    int i = SerialBT.readString().toInt();
    //Serial.println(i);
    switch(i) {
      case 1 :  SerialBT.println("...");
      delay(random(500, 2500));
                touchAttachInterrupt(Touchpin, ohneEMS, TouchSchwelle); 
                digitalWrite(LEDpin, HIGH);
                st = millis(); 
                break;

      case 2:   SerialBT.println("....");
      delay(random(500, 2500));
                touchAttachInterrupt(Touchpin, mitEMS, TouchSchwelle); 
                digitalWrite(LEDpin, HIGH);
                digitalWrite(Relaispin, HIGH);
                st = millis(); 
                break;
      case 31: digitalWrite(Relaispin, HIGH); break;
      case 30: digitalWrite(Relaispin, LOW); break;
      case 41: FingerSteuern(); break;
      case 66: touchDetachInterrupt(Touchpin);
                digitalWrite(LEDpin, LOW);
                digitalWrite(Relaispin, LOW);
                SerialBT.println("STOP");
                break;
    }
  }
}

