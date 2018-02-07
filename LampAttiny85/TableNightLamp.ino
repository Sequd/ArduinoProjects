// DigitalWrite
	// 0 is P0, 1 is P1, 2 is P2, etc. - unlike the analog inputs, for digital outputs the pin number matches.
// Digital Read
	// 0 is P0, 1 is P1, 2 is P2, etc. - unlike the analog inputs, for digital inputs the pin number matches.
// Analog Read
	//You need not set pin mode for analogRead - though if you have set the pin to
	// output and later want to read from it then you need to set pinMode(0,INPUT);
	// where 0 is the physical pin number not the analog input number.
    //
    // See below for the proper pinMode statement to go with each analog read.
    // The analog pins are referenced by their analog port number, not their pin
    // number and are as follows:

    // sensorValue = analogRead(1); //Read P2
    // To set to input: pinMode(2, INPUT);
    // THIS IS P2, P2 is analog input 1, so when you are using analog read, you refer to it as 1.

    // sensorValue = analogRead(2); //Read P4
    // To set to input: pinMode(4, INPUT);
    // THIS IS P4, P4 is analog input 2, so when you are using analog read, you refer to it as 2. 

    // sensorValue = analogRead(3); //Read P3
    // To set to input: pinMode(3, INPUT);
    // THIS IS P3, P3 is analog input 3, so when you are using analog read, you refer to it as 3.

    // sensorValue = analogRead(0); //Read P5
    // To set to input: pinMode(5, INPUT);
    // THIS IS P5, P5 is analog input 0, so when you are using analog read, you refer to it as 0.
// Analog Write
	//0 is P0, 1 is P1, 4 is P4 - unlike the analog inputs, 
	// for analog (PWM) outputs the pin number matches the port number.

#define POWERPIN 4 //
#define RESISTORPIN 2 // Read P2, pinMode(4, INPUT);
#define SMALLLED 1
#define FADESPEED 10  // чем больше число, тем медленнее будет fade-эффект

int lightPowerMax = 200;
int lightPowerCurrent = 0;

void setup() {
  pinMode(POWERPIN, OUTPUT);  // лента
  pinMode(4, INPUT); // переменный резистор //Read P2, pinMode(4, INPUT);
  pinMode(SMALLLED, OUTPUT);  // светодиод на плате

  // мигунть пару раз, увидеть что не завис
  digitalWrite(SMALLLED, HIGH);
  delay(200);
  digitalWrite(SMALLLED, LOW);
  delay(200);
  digitalWrite(SMALLLED, HIGH);
  delay(200);
  digitalWrite(SMALLLED, LOW);
  delay(200);
  digitalWrite(SMALLLED, LOW);
}

void loop() {
  int resistir_value = analogRead(RESISTORPIN);
  powerUpOrDown(resistir_value);
  analogWrite(POWERPIN, lightPowerCurrent);
  delay(FADESPEED);
}

void powerUpOrDown(int resistir_value) {
  if (resistir_value > 5) {
    if (resistir_value <= lightPowerMax) {
      powerUp();
    }
    else {
      powerDown();
    }
  }
}

void powerUp() {
  if (lightPowerCurrent < lightPowerMax) {
    lightPowerCurrent++;
  }
}

void powerDown() {
  if (lightPowerCurrent > 0) {
    lightPowerCurrent--;
  }
}