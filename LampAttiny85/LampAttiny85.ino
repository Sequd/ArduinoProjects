// Attiny 85

int led_pin = 1;
int sensor_pin = 0;

void setup() {
  pinMode(led_pin, OUTPUT);
  pinMode(sensor_pin, INPUT);
}

void loop() {
  if (digitalRead(sensor_pin) == HIGH) {
    digitalWrite(led_pin, HIGH);
  }
  else {
    digitalWrite(led_pin, LOW);
  }
 
  delay(50);
}