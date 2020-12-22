//RC Car Project
//By: Sahara Shahab, Allyson Hur, and Melissa Cai

//Motor 1
int enA=8;
int Q1=2;
int Q2=3; 

//Motor 2
int enB=9;
int Q3=4;
int Q4=5;

//Headlights
int leftLED = 13;
int rightLED = 12;

char direction;

void setup() {
 //set motor pins to output
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(Q1, OUTPUT);
  pinMode(Q2, OUTPUT);
  pinMode(Q3, OUTPUT);
  pinMode(Q4, OUTPUT);
  
  pinMode(leftLED, OUTPUT);
  pinMode(rightLED, OUTPUT); //initializes ports
  
  Serial.begin(9600);	//initialize serial monitor
}

void loop()
{
  if (Serial.available() > 0){
    direction = Serial.read();
    Serial.println(direction);	//print direction input on serial monitor
  }
  motorControl();
}
 
void Accelerate() {
  for (int en=0; en<256; en++) {    //keep adding to en
    analogWrite(enA, en);
    analogWrite(enB, en);	//the car's speed increases
  }
}
  
void Decelerate() {
  for (int en=255; en>=0; --en) {	//keep subtracting from en
    analogWrite(enA, en);
    analogWrite(enB, en);	//the car's speed decreases
  }
}

void Forward() {	//car moves forward
  digitalWrite(Q1, 1); 
  digitalWrite(Q2, 0);
  digitalWrite(Q3, 1); 
  digitalWrite(Q4, 0);
  Accelerate();
  
  digitalWrite(leftLED, LOW);	//both LEDs are off
  digitalWrite(rightLED, LOW);
}
  
void Backward() {	//car moves backward
  digitalWrite(Q1, 0); 
  digitalWrite(Q2, 1);
  digitalWrite(Q3, 0); 
  digitalWrite(Q4, 1);
  Accelerate();
  
  digitalWrite(leftLED, HIGH);	//both LEDs turn on
  digitalWrite(rightLED, HIGH);
}
  
void Left()	{	//car turns left
  digitalWrite(Q1, 0);
  digitalWrite(Q2, 0);
  digitalWrite(Q3, 1);
  digitalWrite(Q4, 0);
  
  digitalWrite(leftLED, HIGH);	//left LED turns on
  digitalWrite(rightLED, LOW);
}

void Right() {	//car turns right 
  digitalWrite(Q1, 1);
  digitalWrite(Q2, 0);
  digitalWrite(Q3, 0);
  digitalWrite(Q4, 0);
  
  digitalWrite(rightLED, HIGH);	//right LED turns on
  digitalWrite(leftLED, LOW);
}

void Brake() {	//braking function
  digitalWrite(Q1, 0); 
  digitalWrite(Q2, 0);
  digitalWrite(Q3, 0);
  digitalWrite(Q4, 0);
  Decelerate();	//slow down before stopping
  
  digitalWrite(leftLED, LOW);	//both LEDs are off
  digitalWrite(rightLED, LOW);
}
  
void Coast() {	//coasting function
  digitalWrite(Q1, 1);
  digitalWrite(Q2, 1); 
  digitalWrite(Q3, 1);
  digitalWrite(Q4, 1);	
  Decelerate();	//slow down before stopping
  
  digitalWrite(leftLED, LOW);	//both LEDs are off
  digitalWrite(rightLED, LOW);
}
  
void motorControl() {	//possible inputs
  switch (direction) {
    case 'f' :		//'f' for forward
      Forward();
      break;
    case 'b' :		//'b' for backward
      Backward();
      break;
    case 'l' :		//'l' for left
      Left();
      break;
    case 'r' :		//'r' for right
      Right();
      break;
    case 'x' :		//'x' for brake
      Brake();
      break;
    case 'c' :		//'c' for coast
      Coast();
      break;

    default:
      break;
  } 
}
