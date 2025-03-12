// Botões
#define BT1 8
#define BT2 9
#define BT3 10

// LED's
#define ledB 2 // Led Azul 
#define ledW 3 // Led Branco
#define ledR 4 // Led Vermelho

void setup() {
  // put your setup code here, to run once:
  pinMode(BT1, INPUT);
  pinMode(BT2, INPUT);
  pinMode(BT3, INPUT);

  pinMode(ledB, OUTPUT);
  pinMode(ledW, OUTPUT);
  pinMode(ledR, OUTPUT);

  acendeLeds();
  delay(3000);
  apagaLeds();
}


void loop() {
  // put your main code here, to run repeatedly:

}

void acendeLeds() {
  digitalWrite(ledB, HIGH);
  digitalWrite(ledW, HIGH);
  digitalWrite(ledR, HIGH);
}

void apagaLeds() {
  digitalWrite(ledB, LOW);  
  digitalWrite(ledW, LOW);
  digitalWrite(ledR, LOW);
}



