const int numVals = 5;

int sensorVals [numVals];
int index;
int total;
int avg;

int sensorPin = A0;

void setup() {
  
  Serial.begin(9600);

  pinMode(sensorPin, INPUT);
  index = total = 0;
  for(int i = 0; i < numVals; i++){
    sensorVals[i] = 0;
  }
}

void loop() {
  
  total = total - sensorVals[index];
  
  sensorVals[index] = analogRead(sensorPin);
  
  total = total + sensorVals[index];
  
  index+=1;
  if(index >= numVals) index=0;
  
  avg = total / numVals;
  
  Serial.println(avg);
  
  delay(1);
  

}
