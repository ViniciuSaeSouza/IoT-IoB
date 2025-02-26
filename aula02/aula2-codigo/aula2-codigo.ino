// Atribuir nomes aos pinos
// Botões 1 e 2
#define BT1 8
#define BT2 9

// LEDs
#define ledR 4 // Led Red
#define ledW 3// Led Green
#define ledB 2// Led Blue



void setup() {
  // Habilitar porta serial
  // Baud rate (9600 bits/s) padrão UNO
  Serial.begin(9600);
  // Configurar o sentido dos pinos de I/O
  pinMode(BT1, INPUT);
  pinMode(BT2, INPUT);

  pinMode(ledR, OUTPUT);
  pinMode(ledW, OUTPUT);
  pinMode(ledB, OUTPUT);
  

}

void piscaRB(){
  digitalWrite(ledR, HIGH);
  digitalWrite(ledB, LOW);
  
  delay(250);
  digitalWrite(ledR, LOW);
  digitalWrite(ledB, HIGH);
  
  delay(250);

  digitalWrite(ledR, LOW);
  digitalWrite(ledB, LOW);
}

void piscaW(){
  digitalWrite(ledW, HIGH);

  delay(250);
  digitalWrite(ledW, LOW);
  
  delay(250);
}


void loop() {
  // put your main code here, to run repeatedly:

  bool statusBT1 = digitalRead(BT1);
  bool statusBT2 = digitalRead(BT2);
  //if (digitalRead(BT1) == HIGH) piscaRG();
  
  if (statusBT1 == HIGH) {
    piscaRB();
    Serial.println("BT1 LIGADO!");
  }
  else if (statusBT2 == HIGH) {
    piscaW();
    Serial.println("BT2 LIGADO!");
  }
  
  // bool statusBT1 = digitalRead(BT1);
  // bool statusBT2 = digitalRead(BT2);


}
