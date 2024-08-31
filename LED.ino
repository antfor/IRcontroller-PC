#define LED_PIN 12

void setupLED(){
  pinMode(LED_PIN, OUTPUT);
}

void blink(){
    digitalWrite(LED_PIN, HIGH);
    delay(50);
    digitalWrite(LED_PIN, LOW);
}