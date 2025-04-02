// Já existe um LED Azul ligado ao pino 2
#define LED_ONBOARD 2


void setup() {
  // put your setup code here, to run once:
  // BAUD RATE ESP32 = 115200
  Serial.begin(115200);
  Serial.println("2TDSPK - 2025");
  pinMode(LED_ONBOARD, OUTPUT);

}

void loop() {
  // HIGH (ESP32): 3.3V ---> NO ARDUINO ERA 5V
  digitalWrite(LED_ONBOARD, HIGH);
  delay(2000);
  digitalWrite(LED_ONBOARD, LOW);
  delay(2000);
}
