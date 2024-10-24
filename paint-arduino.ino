void setup() {
    pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
    digitalRead(LED_BUILTIN, HIGH);
    delay(1000);
    digitalRead(LED_BUILTIN, LOW);
    delay(1000);
}

