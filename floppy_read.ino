#define DENSEL   4  //   FDC  2
#define IDX      0  // DRIVE  8
#define DS1     13  //   FDC 14
#define MOT1     5  //   FDC 10
#define DIR      6  //   FDC 18
#define STEP     8  //   FDC 20
#define WDATA    9  //   FDC 22
#define WGATE   10  //   FDC 24
#define TRK0     1  // DRIVE 26
#define WPT      2  // DRIVE 28
#define RDATA    3  // DRIVE 30
#define SIDE1   11  //   FDC 32
#define DSKCHG   7  // DRIVE 34

#define PULSETIME 6

void setup() {
  //Set the input pins for input, turn on the pullup
  pinMode(IDX, INPUT_PULLUP);
  pinMode(TRK0, INPUT_PULLUP);
  pinMode(WPT, INPUT_PULLUP);
  pinMode(RDATA, INPUT_PULLUP);
  pinMode(DSKCHG, INPUT_PULLUP);
  
  //Set all the output pins as output
  pinMode(DENSEL, OUTPUT);
  pinMode(DS1, OUTPUT);
  pinMode(MOT1, OUTPUT);
  pinMode(DIR, OUTPUT);
  pinMode(STEP, OUTPUT);
  pinMode(WDATA, OUTPUT);
  pinMode(WGATE, OUTPUT);
  pinMode(SIDE1, OUTPUT);
  
  //All signals are inverse, set outputs high (inactive)
  digitalWrite(DENSEL, HIGH);
  digitalWrite(DS1, HIGH);
  digitalWrite(MOT1, HIGH);
  digitalWrite(DIR, HIGH);
  digitalWrite(STEP, HIGH);
  digitalWrite(WDATA, HIGH);
  digitalWrite(WGATE, HIGH);
  digitalWrite(SIDE1, HIGH);

  Serial.begin(115200);
  while(!Serial){
  // wait for serial
  }
  Serial.println("BEGIN\n");
  delay(1000);
  stepAllTheWayIn();
  stepAllTheWayOut();
  stepAllTheWayIn();
  test_fdd();
  Serial.println("\nEND");

}

//step the read/write head all the way to the outside
void stepAllTheWayOut() {
  for(int i=0;i<100;i++) {
//    printState("Stepping Out");
    stepOutALittle();
  }
}

//step the read/write head all the way to the center
void stepAllTheWayIn() {
  for(int i=0;i<100;i++) {
    //printState("Stepping In");
    stepInALittle();
  }
}

//move the head towards the outside a little
void stepOutALittle() {
  digitalWrite(DIR,HIGH);
  stepPulse();
}

//move the head towards the center a little
void stepInALittle() {
  digitalWrite(DIR,LOW);
  stepPulse();
}

//pulse the step pin
void stepPulse() {
  digitalWrite(STEP,LOW);
  delay(PULSETIME);
  digitalWrite(STEP,HIGH);
}

void test_fdd(){
  Serial.println("turning on DS1");
  digitalWrite(DS1, LOW);
  digitalWrite(MOT1, LOW);
  
  stepAllTheWayIn();
  stepAllTheWayOut();
  stepAllTheWayIn();
  
  delay(2000);
  digitalWrite(MOT1, HIGH);
  digitalWrite(DS1, HIGH);
  Serial.println("turning off DS1");
}


void loop(){
  
}

