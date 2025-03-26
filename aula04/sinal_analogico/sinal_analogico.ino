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
};
const int botoes[] = {
  8, 9, 10
};
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);  // Habilita a comunicação serial do Arduino
  // Baud Rate 9600 bits/s


  for (int i = 0; i < sizeof(leds) / sizeof(leds[0]); i++) {
    pinMode(leds[i], OUTPUT);
  }
  for (int i = 0; i < sizeof(botoes) / sizeof(botoes[0]); i++) {
    pinMode(i, INPUT_PULLUP);
  }

  Serial.println("Vinicius Saes minerais - rm 554456");
}

void loop() {
  // put your main code here, to run repeatedly:
  valor = analogRead(A2);
  //questao2();
  questao3();
}

void questao2() {
  //fase01
  digitalWrite(LED1_Verde, HIGH);
  digitalWrite(LED2_Vermelho, HIGH);
  delay(5000);
  //fase02
  digitalWrite(LED_Amarelo, HIGH);
  digitalWrite(LED1_Verde, LOW);
  delay(2000);
  //fase03
  digitalWrite(LED_Amarelo, LOW);
  digitalWrite(LED2_Vermelho, LOW);
  digitalWrite(LED1_Vermelho, HIGH);
  digitalWrite(LED2_Verde, HIGH);
  delay(5000);
  //fase04
  digitalWrite(LED2_Verde, LOW);
  digitalWrite(LED2_Vermelho, HIGH);
  delay(500);
  digitalWrite(LED2_Vermelho, LOW);
  delay(500);
  digitalWrite(LED2_Vermelho, HIGH);
  delay(500);
  digitalWrite(LED2_Vermelho, LOW);
  delay(500);
  digitalWrite(LED1_Vermelho, LOW);
}

void questao3() {
  desligaLeds();
  if (valor < 300) {
    digitalWrite(LED2_Verde, HIGH);
  } else if (valor >= 300 && valor < 600) {
    digitalWrite(LED_Amarelo, HIGH);
  } else if (valor >= 600 && valor < 900) {
    digitalWrite(LED2_Vermelho, HIGH);
  } else if (valor >= 900 && valor < 1000) {
    for (int i = 0; i < 3; i++) {
      pisca_q3();
    }
  } else if (valor >= 1000) {
    Serial.println("Alarme!");
    for (int i = 0; i < 3; i++) {
      digitalWrite(LED1_Vermelho, HIGH);
      digitalWrite(LED2_Vermelho, HIGH);
      delay(1000);
      digitalWrite(LED1_Vermelho, LOW);
      digitalWrite(LED2_Vermelho, LOW);
      delay(1000);
    }
    digitalWrite(LED1_Vermelho, HIGH);
    digitalWrite(LED2_Vermelho, HIGH);
  }
  Serial.print("Valor: ");
  Serial.println(valor);
}

void pisca_q3() {
  ligaLeds();
  delay(1000);
  desligaLeds();
  delay(1000);
}

void ligaLeds() {
  for (int i = 0; i < sizeof(leds) / sizeof(leds[0]); i++) {
    digitalWrite(leds[i], HIGH);
  }
}

void desligaLeds() {
  for (int i = 0; i < sizeof(leds) / sizeof(leds[0]); i++) {
    digitalWrite(leds[i], LOW);
  }
}