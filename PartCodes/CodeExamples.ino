int led_pin = 1;
int sensor_pin = 0;
int value_pin_1 = 0;
int max_value = 255;
int min_value = 0;

void For(){
      for (int i = 0; i <= 255; i++) {
      analogWrite(led_pin, i);
      delay(10);
    }
}

void FadeUpDown(){
   if(value_pin_1  > 0){
         analogWrite(led_pin, value_pin_1);
   }
  
   if (digitalRead(sensor_pin) == HIGH) {
     if (value_pin_1 < max_value) {
       value_pin_1++;
     }
   }
   else {
     if (value_pin_1 > min_value) {
       value_pin_1--;
     }
   }
}