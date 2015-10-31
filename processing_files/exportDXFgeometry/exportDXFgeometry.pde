import processing.dxf.*;
boolean isRecording;

void setup() {
  size(800, 800, P3D);
  isRecording = false;

  // when using the P3D renderer:
  // filled graphics export as solid meshes
  // noFill graphics (stroke only) export as curves
  //noStroke();
  stroke(255);
  //noFill();
}

void draw() {
  
  background(0);

  if (isRecording == true) {
    //2 args: file type (DXF), file name
    // creates new file, starts recording everything following
    beginRaw(DXF, "myMesh_3.dxf");
  }

  for(int i = 0; i < 5; i++){
    for(int j = 0; j < 10; j++){
       ellipse(j*40, i*50, random(5,20), random(5,20));
    }
  }
  
  if (isRecording) {
    // saves and closes file
    endRaw();
    println("file saved");
    isRecording = false;
  }
}

void keyPressed() {
  if (key == 's' || key == 'S') {
    isRecording = true;
  }
}

