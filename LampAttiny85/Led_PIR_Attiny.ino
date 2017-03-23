// Attiny 85

int led_pin = 0; 
int resistor_pin = 1; 
int pir_pin = 2; 
State_Led state_led;

enum State_Led {
  On,
  Off
};

void setup() {
  pinMode(led_pin, OUTPUT); 
  pinMode(resistor_pin, INPUT); 
}

void loop() {
  // if pir HIGH
  if (digitalRead(resistor_pin) == HIGH) {
    // if Res HIGH && State LED_OFF 
    if(analogRead(resistor_pin) > 50 && state_led == Off){
      // then led On -> State LED_ON
      state_led = On;
    }        
  }
  else {
    // then led Off -> State LED_OFF
    state_led = Off;
  }
       
  // if (digitalRead(resistor_pin) == HIGH) {
  //   digitalWrite(led_pin, HIGH); 
  // }
  // else {
  //   digitalWrite(led_pin, LOW); 
  // }
 
  // delay(50); 
}