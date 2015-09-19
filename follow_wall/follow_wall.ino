#include <RedBot.h>

#define FORWARD 0
#define TURN 1

RedBotMotor motors;

int trigPin1 = A2;
int echoPin1 = A3;
int trigPin2 = A4;
int echoPin2 = A5; 
float duration1;
float duration2;
float average1 = 10;
float average2 = 10;
float value1[5];
float value2[5];
int count = 0;

int motorSpeed = 150;

int botState = FORWARD;

void setup()
{
  Serial.begin(9600);
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
}

void loop()
{ 
 switch(botState)
 {
   
   case FORWARD:
     //if average1 is greater then average2 it needs to turn
     if(average1 > (average2 + 3))
     {
       botState = TURN;
     }
     break;
     
     case TURN:
     //if average1 is less then then average2 it needs to go forward
     if(average1 < average2)
     {
       botState = FORWARD;
     }
     break;
 }
     //===================================================================================
 switch(botState)
 {
     case FORWARD:
     //need to call goForward and aslo read method which check both sensers
     goForward();
     check();
     
     break;
     
     case TURN:
     //in turn it just needs to go right untill average2 is greater then average1
     //it also needs to be caling check method which reads both sensers
     goRight();
     check();
     
     break;
 }
}

void check()
{
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1,LOW);
  duration1 = pulseIn(echoPin1, HIGH);
  value1[count] = duration1/50;
  
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2,LOW);
  duration2 = pulseIn(echoPin2, HIGH);
  value2[count] = duration2/50;
  count++;
  count = count % 5;
  if(count == 0)
  {
    average1 = (value1[0] + value1[1] + value1[2] + value1[3] + value1[4]) / 5.0;
    average2 = (value2[0] + value2[1] + value2[2] + value2[3] + value2[4]) / 5.0;
  }
  printEverything();
}
void printEverything()
{
  
  Serial.print("value1 ");
  Serial.print(count);
  Serial.print(": ");
  Serial.println(value1[count]);
  
  Serial.print("value2 ");
  Serial.print(count);
  Serial.print(": ");
  Serial.println(value2[count]);
  
  Serial.print("average1:");
  Serial.println(average1);
  Serial.print("average2:");
  Serial.println(average2);
}
void goForward()
{
      motors.drive(motorSpeed);
}

void goRight()
{
      motors.leftDrive(motorSpeed);
      motors.rightDrive(motorSpeed/2);
}

