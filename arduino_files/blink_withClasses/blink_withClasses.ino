class Blinky{
  unsigned long curTime;
  int ledPin;
  int delayTime;
  int ledState;
  
  public:
  Blinky(int pin, int delayAmount){
    ledPin = pin;
    delayTime = delayAmount;
    ledState = LOW;
    pinMode(ledPin, OUTPUT);
  }
  
  void upd8(){
    unsigned long totalTime = millis();
    if(totalTime - curTime >= delayTime){
      if(ledState == LOW){
        curTime = totalTime;
        ledState = HIGH;
        digitalWrite(ledPin, HIGH);
      }
      else if(ledState == HIGH){
        curTime = totalTime;
        ledState = LOW;
        digitalWrite(ledPin, LOW);
      }
    }
  }
};


Blinky led1(13, 1000);
Blinky led2(12, 300);
Blinky led3(9, 4000);

void setup() {
}

void loop() {
  led1.upd8();
  led2.upd8();
  led3.upd8();
}
