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

void setup() {
  Serial.begin(115200);
  while(!Serial){
  }
  
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

  Serial.println("BEGIN\n");
  test_fdd();
  Serial.println("\nEND");

}

void test_fdd(){
  Serial.println("turning on DS1");
  digitalWrite(DS1, LOW);
  delay(2000);
  digitalWrite(DS1, HIGH);
  Serial.println("turning off DS1");
}


void loop(){
}

