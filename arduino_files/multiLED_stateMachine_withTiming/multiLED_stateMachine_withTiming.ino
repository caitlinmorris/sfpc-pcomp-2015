/// code for using a state machine and millis() 
/// to control LEDs blinking at different rates

int ledPin1 = 13;
int ledPin2 = 12;


// unsigned long stores greater range than int
unsigned long totalTime;
unsigned long currentTime1;
unsigned long currentTime2;

// each LED has its own timing
int delayAmount1 = 2000;
int delayAmount2 = 500;

// state machine stores current state of each LED as HIGH or LOW
int led1State = LOW;
int led2State = LOW;

void setup() {
  
  Serial.begin(9600);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  
  totalTime = currentTime1 = currentTime2 = 0;

}

void loop() {
  
  totalTime = millis();
  
  // check timing and state logic for first LED
  if(led1State == LOW && totalTime - currentTime1 >= delayAmount1){
    currentTime1 = totalTime; // reset timing interval
    led1State = HIGH; // change state
    digitalWrite(ledPin1, HIGH); // write to the LED pin
  }
  if (led1State == HIGH && totalTime - currentTime1 >= delayAmount1){
    currentTime1 = totalTime;
    led1State = LOW;
    digitalWrite(ledPin1, LOW);
  }
  
  // check timing and state logic for second LED
  if(led2State == HIGH && totalTime - currentTime2 >= delayAmount2){
    currentTime2 = totalTime;
    led2State = LOW;
    digitalWrite(ledPin2, LOW);
  }
  if(led2State == LOW && totalTime - currentTime2 >= delayAmount2){
    currentTime2 = totalTime;
    led2State = LOW;
    digitalWrite(ledPin2, HIGH);
  }
}
