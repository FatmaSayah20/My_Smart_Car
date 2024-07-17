const int trigPin1=4; //Left Sensor
const int echoPin1=5;
const int trigPin2=7;//Front Sensor
const int echoPin2=6;
const int trigPin3=2;
const int echoPin3=3;
const int lm1=8;
const int lm2=9;
const int en1=10;
const int en2=11;
const int rm1=12;
const int rm2=13;

int rangeFront = 0;
int rangeLeft = 0;
int rangeRight = 0;




/////////////////////////////////////////////////////////////
// Function turn right
void turn_right(){
    digitalWrite(lm1,HIGH);
    digitalWrite(lm2,LOW);
    digitalWrite(rm1,LOW);
    digitalWrite(rm2,HIGH);
    analogWrite(en1,130); // 255
    analogWrite(en2,130); // 255
    
}
// Function Left
void turn_left(){
    digitalWrite(lm1,LOW);
    digitalWrite(lm2,HIGH);
    digitalWrite(rm1,HIGH);
    digitalWrite(rm2,LOW);
    analogWrite(en1,130); // 255
    analogWrite(en2,130); // 255
    

}
// Function Forward
void move_forward(){
      digitalWrite(lm1,HIGH);
      digitalWrite(lm2,LOW);
      digitalWrite(rm1,HIGH);
      digitalWrite(rm2,LOW);
      analogWrite(en1,255); // 255   
      analogWrite(en2,255); // 255
    

}
// Function Backward
void move_backword(){
      digitalWrite(lm1,LOW);
      digitalWrite(lm2,HIGH);
      digitalWrite(rm1,LOW);
      digitalWrite(rm2,HIGH);
     
}
// Break function
void stop(){
      digitalWrite(lm1,LOW);
      digitalWrite(lm2,LOW);
      digitalWrite(rm1,LOW);
      digitalWrite(rm2,LOW);
}
////////////////////////////////////////////////////
int readRangeFront() {
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);
  int duration = pulseIn(echoPin2, HIGH);
  int distance = duration * 0.034 / 2;
  return distance;
}

int readRangeLeft() {
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);
  int duration = pulseIn(echoPin1, HIGH);
  int distance = duration * 0.034 / 2;
  return distance;
}

int readRangeRight() {
  digitalWrite(trigPin3, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin3, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin3, LOW);
  int duration = pulseIn(echoPin3, HIGH);
  int distance = duration * 0.034 / 2;
  return distance;
}

////////////////////////////////////////////////////
void setup() {
  pinMode(trigPin1,OUTPUT);
  pinMode(echoPin1,INPUT);
  pinMode(trigPin2,OUTPUT);
  pinMode(echoPin2,INPUT);
  pinMode(trigPin3,OUTPUT);
  pinMode(echoPin3,INPUT);
  pinMode(lm1,OUTPUT);
  pinMode(lm2,OUTPUT);
  pinMode(rm1,OUTPUT);
  pinMode(rm2,OUTPUT);
  pinMode(en1,OUTPUT);
  pinMode(en2,OUTPUT);
  Serial.begin(9620);
 
}

void loop() {

  rangeFront = readRangeFront();
  rangeLeft = readRangeLeft();
  rangeRight = readRangeRight();

   
  if (rangeFront > 23 && rangeLeft > 25 && rangeRight > 25) {
    move_forward();
    delay(3);
    
  }
  else if (rangeFront > 23 && rangeLeft > 25 && rangeRight <= 25){
    move_forward();
    delay(3);
  }else if (rangeFront >=23 && rangeLeft <= 25 && rangeRight <= 25) {
    move_forward();
    delay(3);
  } else if (rangeFront >= 23 && rangeLeft <= 25 && rangeRight > 25) {
    move_forward();
    delay(3);
  } else if (rangeFront <=23 && rangeLeft > 25 && rangeRight > 25) {
    turn_left();
    delay(610);
  }  else if (rangeFront <= 23 && rangeLeft > 25 && rangeRight <= 25) {
    turn_left();
    delay(610);
  }  else if (rangeFront <= 23 && rangeLeft <= 25 && rangeRight > 25) {
    turn_right();
    delay(610);
  }  else if (rangeFront <= 27 && rangeLeft <= 27 && rangeRight <= 27) {
    stop();
  }

}
