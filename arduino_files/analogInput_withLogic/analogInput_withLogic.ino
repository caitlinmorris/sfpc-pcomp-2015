int ledPin = 3;
int potentiometer = A0;
int threshold = 500; // set threshold value for logic operations

void setup() {
  
  pinMode(potentiometer, INPUT);
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
  
  Serial.begin(9600); //set baud rate to 9600 bits per second

}

void loop() { 
  
  int val = analogRead(potentiometer);
  
  // convert incoming 10-bit range to PWM-friendly range
  // use minimum sensor value (learned from serial monitor) as min argument
  // maximum serial monitor value as max argument
  int mappedVal = map(val,0,1023,0,255);
  
  if(val > threshold){
    analogWrite(ledPin, mappedVal);
  }
  else {
    analogWrite(ledPin, 0);
  }
  
  Serial.print(val);
  Serial.print(" | ");
  Serial.println(mappedVal); //convert bytes to ASCII for readability
  
  //Serial.write(val); 
  // write raw bytes to the serial port
  
  delay(3); // delay 3 millis to allow ADC to reset

}
