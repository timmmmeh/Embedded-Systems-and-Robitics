#include <RedBot.h>
RedBotMotor motors;  

//what input pins im using
RedBotSensor leftSensor = RedBotSensor(A3);  
RedBotSensor middleSensor = RedBotSensor(A6);  
RedBotSensor rightSensor = RedBotSensor(A7);  

int baseLevel;
int moveSpeed = 120;

void setup() {
  Serial.begin(57600);
  //sets baseValue to a number over 500 
  do{
      baseLevel = middleSensor.read();
    }while(baseLevel < 500);
}

void loop() {
  if((middleSensor.read() >= (baseLevel - 100)))
  {
    //go forward
    goForward();

    if((leftSensor.read() >= (baseLevel - 100)) && (rightSensor.read() >= (baseLevel - 100)))
    {
      //go forward
      goForward();
    }
    else
    {
      if(leftSensor.read() >= (baseLevel - 100))
      {
        //turn left
        goLeft(); 
      }
      else
      {
        //turn right
        goRight();
      }
    }  
 }
 
  else
  {
    if(leftSensor.read() >= (baseLevel - 100))
    {
      //turn left
      goLeftHard();
    }
    else
    {
      if(rightSensor.read() >= (baseLevel - 100))
      {
        //turn right
        goRightHard();
      }
      else
      {
        //if none of the sensors get a value it will stop
        stopNow();
      }
    }
  }
}

void goForward()
{
      motors.drive(moveSpeed);
}
void goLeft()
{
      Serial.print("Left");
      motors.rightDrive(moveSpeed);
      motors.leftDrive(0);
}
void goRight()
{
      Serial.print("Right");
      motors.leftDrive(moveSpeed);
      motors.rightDrive(0);
}
void goLeftHard()
{
      Serial.print("Left");
      motors.rightDrive(moveSpeed*2);
      motors.leftDrive(0);
}
void goRightHard()
{
      Serial.print("Right");
      motors.leftDrive(moveSpeed*2);
      motors.rightDrive(0);
}
void stopNow()
{
      motors.stop();
}
  
