import processing.serial.*;

Serial myPort;  //the Serial port object
int[] serialInputs = new int[3]; // store the incoming data in an array
int inputCount = 0;  // count how many bytes we've received
boolean firstContact = false; // have we heard from the arduino?
int ellipseSize = 0; // this variable will inherit from one of the inputs

void setup() {
  size(500, 500);

  printArray( Serial.list() );

  //  initialize the serial port and set the baud rate to 9600 (to match Arduino)
  myPort = new Serial(this, Serial.list()[5], 9600);
}

void draw() {

  background(0);
  ellipse(width/2, height/2, ellipseSize, ellipseSize);
  // we can use the incoming data here to draw things
}

void serialEvent( Serial myPort) {
  
  try {

  int inByte = myPort.read();

  //look for our 'A' string to start the handshake
  //if it's there, clear the buffer, 
  // note that you've made first contact, 
  // and send a request back for data
  if (firstContact == false) {
    if (inByte == 'A') {
      myPort.clear();
      firstContact = true;
      myPort.write('A');
    }
  } 
  
  else { //if we've already established contact, keep getting and returning data
    
    // add the most recent byte from serial into the array
    serialInputs[inputCount] = inByte;
    // increment the index of bytes received
    inputCount++;
    
    if (mousePressed == true) 
    {                           //if we clicked in the window
      myPort.write('1');        //send a 1
      println("1");
    }
    
    //once we have 3 bytes, the array is full and we can work with that data
    if(inputCount > 2){
      ellipseSize = serialInputs[0]; // now you can access each sensor individually
     
      println(ellipseSize);
    
      // when you've parsed the data you have, ask for more:
      myPort.write("A");
    }
  }
  
  }
  catch(Exception e){
    println("Init exception");
  }
}

