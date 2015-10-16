int sensorPin = A0;
int sensorVal;

void setup() {
  
  pinMode(sensorPin, INPUT);
  Serial.begin(9600);
  establishContact();
}

void loop() {
  // put your main code here, to run repeatedly:
  
  if (Serial.available() > 0){
    sensorVal = analogRead(sensorPin);
    Serial.write(sensorVal);
    delay(10);
  }
}

void establishContact(){
  while( Serial.available() <= 0 ){
    Serial.println("A");
    delay(300);
  }
}
