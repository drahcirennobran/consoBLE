//#include <ArduinoBLE.h>

volatile unsigned long mwh[25] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
volatile unsigned short lastChange[25] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
volatile unsigned short ledStatus = 0;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(2, INPUT_PULLUP);
  Serial.begin(9600);    // initialize serial communication
  //while (!Serial);
  attachInterrupt(digitalPinToInterrupt(2), tickPin2, FALLING);
}

void loop() {
  digitalWrite(LED_BUILTIN, ledStatus);
  ledStatus = LOW;
  delay(100);
}

void tickPin2(void) {
  tick(2);
}

void tick(int interrupNo) {
  if (millis() - lastChange[interrupNo] > 100) {
    mwh[interrupNo] ++;
    lastChange[interrupNo] = millis();
    ledStatus = HIGH;
  }
}
