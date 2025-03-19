/*
Sinal analógico: de 0.00 a 5.00V

Conversor Analógico Digital (Analog to digital Converter - ADC)
(módulo dentro do chip ATMEGA328P)
Converte o valor de tensão dos ponos de a0 a a5 em um valor decimal de 0 a 1023,
por meio da função analogRead()
*/

// Variável que armazenará o valor convertido pelo ADC*
int valor;
#define LED1_Vermelho 2
#define LED_Amarelo 3
#define LED1_Verde 4
#define LED2_Vermelho 5
#define LED2_Verde 6
#define BT1 8
#define BT2 9
#define BT3 10
const int leds[] = {
  2, 3, 4, 5, 6
} ;
const int botoes[] = {
  8, 9, 10
};
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); // Habilita a comunicação serial do Arduino
  // Baud Rate 9600 bits/s
  int valor = analogRead(A2);

  for(int i = 0; i <= sizeof(leds) /sizeof(leds[0]); i++) {
    pinMode(leds[i], OUTPUT);
  }
  for (int i = 8; i <= sizeof(leds) / sizeof(leds[0]); i++) {
    pinMode(i, INPUT_PULLUP);
  }

  Serial.println("Vinicius Saes minerais - rm 554456");
  ligaLeds();
  delay(3000);
  desligaLeds();
}

void loop() {
  // put your main code here, to run repeatedly:
  
}

void questao2() {
//fase01
  digitalWrite(LED1_Verde, HIGH);
  digitalWrite(LED2_Vermelho, HIGH);
  delay(5000);
//fase02
  digitalWrite(LED_Amarelo, HIGH);
  digitalWrite(LED1_Verde, LOW);
}




void ligaLeds() {
  for (int i = 0; i <= sizeof(leds) / sizeof(leds[0]); i++) {
    digitalWrite(leds[i], HIGH);
  }
}

void desligaLeds() {
  for (int i = 0; i <= sizeof(leds) / sizeof(leds[0]); i++) {
    digitalWrite(leds[i], LOW);
  }
}