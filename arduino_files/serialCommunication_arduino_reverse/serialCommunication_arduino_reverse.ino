int sensorPin = A0;
int sensorVal;

int ledPin = 13;
char val; // Store data received from the serial port
boolean ledState = LOW; //to toggle our LED

void setup() {
  
  pinMode(sensorPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  establishContact();
}

void loop() {
  // put your main code here, to run repeatedly:
  
  if (Serial.available() > 0){
    val = Serial.read();
    
    if(val == '1') //if we get a 1 from Processing
    {
      ledState = !ledState; //flip the ledState
      digitalWrite(ledPin, ledState); 
      delay(100);
    }

    else{
      sensorVal = analogRead(sensorPin);
      Serial.write(sensorVal);
      delay(10);
    }
  }
}

void establishContact(){
  while( Serial.available() <= 0 ){
    Serial.println("A");
    delay(300);
  }
}
