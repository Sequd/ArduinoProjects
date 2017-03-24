// Attiny 85

enum State_Led {
  On,
  Off
};

int led_pin = 0;
int resistor_pin = 1; // Analog input pin = P2 - A1
int pir_pin = 2; // Digital input pin = P4 - A2
int current_power = 0;
int max_power  = 250;
int min_power = 0;
int fade = 15;
State_Led state_led;

void setup() {
  pinMode(led_pin, OUTPUT);
  pinMode(resistor_pin, INPUT);
  pinMode(pir_pin, INPUT);
}

void loop() {
  if (analogRead(pir_pin) > 120) {
    if (analogRead(resistor_pin) < 50 && state_led == Off) {
      state_led = On;
    }
  }
  else {
    state_led = Off;
  }

  if (state_led == On) {
    if (current_power != max_power) {
      current_power++;
    }
  }
  else {
    if (current_power != min_power) {
      current_power--;
    }
  }

  analogWrite(led_pin, current_power);
  delay(fade);
}