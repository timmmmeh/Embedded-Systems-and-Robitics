//Tim Jones Light sensor robot
//finished 12/10/2014
//this will move towards the light 
//will turn in the direction of the light source

int rightAngle = 700;
int motorSpeed = 250;

int leftMotorPower = 3;
int leftMotorDirection1 = 8;
int leftMotorDirection2 = 9;
int rightMotorPower = 5;
int rightMotorDirection1 = 11;
int rightMotorDirection2 = 12;
int wakeUpPin = 10;

void setup() {        
  pinMode(leftMotorPower, OUTPUT);  
  pinMode(leftMotorDirection1, OUTPUT); 
  pinMode(leftMotorDirection2, OUTPUT); 
  pinMode(rightMotorPower, OUTPUT); 
  pinMode(rightMotorDirection1, OUTPUT); 
  pinMode(rightMotorDirection2, OUTPUT); 
  pinMode(wakeUpPin, OUTPUT); 
  digitalWrite(wakeUpPin, HIGH);
}

void loop() 
{
  moveForward(motorSpeed, 1000);
  moveLeft(motorSpeed, rightAngle);
  moveForward(motorSpeed, 300);
  moveLeft(motorSpeed, rightAngle);
  moveForward(motorSpeed, 1000);
  moveRight(motorSpeed, rightAngle);
  moveForward(motorSpeed, 300);
  moveRight(motorSpeed, rightAngle);
  moveForward(motorSpeed, 1000);
  moveLeft(motorSpeed, rightAngle);
  moveForward(motorSpeed, 300);
  moveLeft(motorSpeed, rightAngle);
  moveForward(motorSpeed, 1200);
  moveLeft(motorSpeed, rightAngle);
  moveForward(motorSpeed, 900);
  moveLeft(motorSpeed, rightAngle);
}

void moveForward(int motorSpeed, int duration)
{
  digitalWrite(leftMotorDirection1, LOW);
  digitalWrite(leftMotorDirection2, HIGH);
  analogWrite(leftMotorPower, motorSpeed);
  
  digitalWrite(rightMotorDirection1, LOW);
  digitalWrite(rightMotorDirection2, HIGH);
  analogWrite(rightMotorPower, motorSpeed);
  delay(duration);
  analogWrite(leftMotorPower, 0);
  analogWrite(rightMotorPower, 0);
  delay(duration);
}

void moveBack(int motorSpeed, int duration)
{
  digitalWrite(leftMotorDirection1, HIGH);
  digitalWrite(leftMotorDirection2, LOW);
  analogWrite(leftMotorPower, motorSpeed);
  
  digitalWrite(rightMotorDirection1, HIGH);
  digitalWrite(rightMotorDirection2, LOW);
  analogWrite(rightMotorPower, motorSpeed);
  delay(duration);
  analogWrite(leftMotorPower, 0);
  analogWrite(rightMotorPower, 0);
  delay(duration);
}
void moveLeft(int motorSpeed, int duration)
{
  digitalWrite(rightMotorDirection1, LOW);
  digitalWrite(rightMotorDirection2, HIGH);
  analogWrite(rightMotorPower, motorSpeed-50);
  delay(duration);
  analogWrite(rightMotorPower, 0); 
  delay(duration);
}
void moveRight(int motorSpeed, int duration)
{
  digitalWrite(leftMotorDirection1, LOW);
  digitalWrite(leftMotorDirection2, HIGH);
  analogWrite(leftMotorPower, motorSpeed-50);
  delay(duration);
  analogWrite(leftMotorPower, 0);
  delay(duration);
}
