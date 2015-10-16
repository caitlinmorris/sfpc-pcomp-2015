import processing.serial.*;

Serial myPort;
int sensorVal;
boolean firstContact = false;

void setup(){
  
  size(500,500);
   printArray( Serial.list() );
  //  initialize the serial port and set the baud rate to 9600 (to match Arduino)
  myPort = new Serial(this, Serial.list()[5], 9600);

}

void draw(){
  background(0);
  ellipse(width/2, height/2, sensorVal, sensorVal);
  
}

void serialEvent( Serial myPort ){
  int inByte = myPort.read();
  
  if(firstContact == false){
    if(inByte == 'A'){
      myPort.clear();
      firstContact = true;
      myPort.write('A');
    }
  }
  
  else {
    println(inByte);
    sensorVal = inByte;
    myPort.write('A');
  }
}
