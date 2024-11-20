#define A 9
#define B 7
#define C 6
#define D 8

#define ENNixie 4
#define Nixie0 digitalWrite(ENNixie, LOW)
#define Nixie1 digitalWrite(ENNixie, HIGH)


int digits [10][4] {
  {0,0,0,0},
  {0,0,0,1},
  {0,0,1,0},
  {0,0,1,1},
  {0,1,0,0},
  {0,1,0,1},
  {0,1,1,0},
  {0,1,1,1},
  {1,0,0,0},
  {1,0,0,1}};

void setup() {

  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  digitalWrite(A,HIGH);
  digitalWrite(B,HIGH);
  digitalWrite(C,HIGH);
  digitalWrite(D,HIGH);
  pinMode(ENNixie, OUTPUT);
  pinMode(2, INPUT);
}


void loop() {
  
  if(digitalRead(2) == LOW){
    Nixie1;
    for(int i=9;i>=0;i--) {
      digitalWrite(A,digits[i][3]);
      digitalWrite(B,digits[i][2]);
      digitalWrite(C,digits[i][1]);
      digitalWrite(D,digits[i][0]);
      delay(500);
    }
    digitalWrite(A,HIGH);
    digitalWrite(B,HIGH);
    digitalWrite(C,HIGH);
    digitalWrite(D,HIGH);
    Nixie0;
    delay(2000);
  }
  delay(50);
  
  
  //delay(1000);
  //Nixie0;
  //delay(1000);
}