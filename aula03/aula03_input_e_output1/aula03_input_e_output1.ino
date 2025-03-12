// Atribuir nomes aos pinos
// Botões 1 e 2
#define BT1 8
#define BT2 9
#define BT3 10

// LEDs
#define ledR 4 // Led Red
#define ledW 3// Led Green
#define ledB 2// Led Blue


int contador = 0;


void setup() {
  // Habilitar porta serial
  // Baud rate (9600 bits/s) padrão UNO
  Serial.begin(9600);
  // Configurar o sentido dos pinos de I/O
  pinMode(BT1, INPUT);
  pinMode(BT2, INPUT);
  pinMode(BT3, INPUT);

  pinMode(ledR, OUTPUT);
  pinMode(ledW, OUTPUT);
  pinMode(ledB, OUTPUT);
  
  // pisca o branco 10 vezes 
  while (contador < 10){
    Serial.print(contador);
    piscaW();
    contador ++;  
  }

  Serial.print("Fim da inicialização");
  delay(2000);
}

// Rotina principal 
void loop() {
  
  piscaRB();

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