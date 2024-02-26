#define F1 13
#define F2 12
#define F3 14
#define F4 33
#define b F2
#define A F1
#define G F3




void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(F1, OUTPUT);
  pinMode(F2, OUTPUT);
  pinMode(F3, OUTPUT);
  pinMode(F4, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available()) {
    String txt = Serial.readString();
    if (txt.startsWith("F1 on")) {
      digitalWrite(F1, HIGH);
    }
    if (txt.startsWith("F2 on")) {
      digitalWrite(F2, HIGH);
    }
    if (txt.startsWith("F3 on")) {
      digitalWrite(F3, HIGH);
    }
    if (txt.startsWith("F4 on")) {
      digitalWrite(F4, HIGH);
    }
    if (txt.startsWith("F1 off")) {
      digitalWrite(F1, LOW);
    }
    if (txt.startsWith("F2 off")) {
      digitalWrite(F2, LOW);
    }
    if (txt.startsWith("F3 off")) {
      digitalWrite(F3, LOW);
    }
    if (txt.startsWith("F4 off")) {
      digitalWrite(F4, LOW);
    }
    if (txt.startsWith("Lied")) {
      Ton(b, 100, 60);
      Ton(A, 50, 30);
      Ton(b, 50, 30);
      Ton(G, 100, 60);
    }
    if (txt.startsWith("LangsamLied")) {
      Ton(b, 2000, 0);
      Ton(A, 1000, 0);
      Ton(b, 1000, 0);
      Ton(G, 2000, 0);
    }
    if (txt.startsWith("ViertelLangsamLied")) {
      Ton(b, 200, 120);
      Ton(A, 200, 120);
      Ton(b, 200, 120);
      Ton(G, 200, 120);
    }

    if (txt.startsWith("LoopLied")) {
      for (int i = 0; i < 10; i++) {
        Ton(b, 100, 60);
        Ton(A, 50, 30);
        Ton(b, 50, 30);
        Ton(G, 100, 60);
      }
    }
    if (txt.startsWith("LoopLangsamLied")) {
      for (int i = 0; i < 10; i++) {
        Ton(b, 200, 0);
        Ton(A, 100, 0);
        Ton(b, 100, 0);
        Ton(G, 200, 0);
      }
    }
    if (txt.startsWith("LoopViertelLangsamLied")) {
      for (int i = 0; i < 10; i++) {
        Ton(b, 200, 120);
        Ton(A, 200, 120);
        Ton(b, 200, 120);
        Ton(G, 200, 120);
      }

      
    }
    if (txt.startsWith("Testb")) {
        for (int i = 0; i < 10; i++) {
          Ton(b, 500, 200);
        }
      }

      if (txt.startsWith("TestA")) {
        for (int i = 0; i < 10; i++) {
          Ton(A, 500, 200);
        }
      }

      if (txt.startsWith("TestG")) {
        for (int i = 0; i < 10; i++) {
          Ton(G, 500, 200);
        }
      }
  }
}

void Ton(int pin, int AD, int WD) {
  digitalWrite(pin, HIGH);
  delay(AD);
  digitalWrite(pin, LOW);
  delay(WD);
}
