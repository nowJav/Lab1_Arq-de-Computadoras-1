//Laboratorio 1 Arquitectura de Computadoras 1
// Oscar Morales  Carné: 0901-20-19624
const int encederLed = 2;
const int ledPin = 9;
const int button = 10;


int buttonState = 0;
bool intermitente = false;

void setup() {
  
  for (int i = encederLed; i <= ledPin; i++) {
    pinMode(i, OUTPUT);
    digitalWrite(i, HIGH);
  }


  pinMode(button, INPUT);


  Serial.begin(9600);
}

void loop() {

  buttonState = digitalRead(button);

  if (buttonState == HIGH) {
   
    intermitente = false;
    for (int i = encederLed; i <= ledPin; i++) {
      digitalWrite(i, LOW);
      delay(100);
      digitalWrite(i, HIGH);
    }
  } else if (intermitente) {
   
    for (int i = encederLed; i <= ledPin; i++) {
      digitalWrite(i, LOW);
    }
    delay(2000);
    for (int i = encederLed; i <= ledPin; i++) {
      digitalWrite(i, HIGH);
    }
    delay(2000);
  }

  if (Serial.available() > 0) {
   
    int message = Serial.parseInt();

    if (message == 2) {
      
      intermitente = true;
    }
  }
}
