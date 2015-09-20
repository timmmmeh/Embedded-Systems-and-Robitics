// This was made by Tim Jones for embedded systems 2014.
// Nothing was taken from any other program, 100% of this programme was made by me.
// This is my LED project.
// It works by turning LEDs off and on at a rate that depends on the value of the potentiometer.

//this is setting up all my variables
int sensorPin = 0; 
int led = 13;
int led2 = 12;
int led3 = 11;
int led4 = 10;
int led5 = 9;
int led6 = 8;

void setup() {                
  //set up all my pins to output
  pinMode(led, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);  
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);

}

// 
void loop() {
  int sensorValue;
  sensorValue = analogRead(sensorPin);//allows me to check what value the potentiometer is at 
  
  //this turns the LED from pin 13 on and the rest off
  digitalWrite(led, HIGH); 
  digitalWrite(led2, LOW);   
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW); 
  digitalWrite(led5, LOW);
  digitalWrite(led6, LOW);
  delay(analogRead(sensorPin));//this reads in what the potentiometer is
  
  //this turns the LED from pin 12 on and the rest off
  digitalWrite(led, LOW); 
  digitalWrite(led2, HIGH);   
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
  digitalWrite(led5, LOW);
  digitalWrite(led6, LOW);
  delay(analogRead(sensorPin));//this reads in what the potentiometer is
  
  //this turns the LED from pin 11 on and the rest off
  digitalWrite(led, LOW); 
  digitalWrite(led2, LOW);   
  digitalWrite(led3, HIGH);
  digitalWrite(led4, LOW);
  digitalWrite(led5, LOW);
  digitalWrite(led6, LOW); 
  delay(analogRead(sensorPin));//this reads in what the potentiometer is
  
  //this turns the LED from port 10 on and the rest off
  digitalWrite(led, LOW); 
  digitalWrite(led2, LOW);   
  digitalWrite(led3, LOW);
  digitalWrite(led4, HIGH);
  digitalWrite(led5, LOW);
  digitalWrite(led6, LOW);
  delay(analogRead(sensorPin));//this reads in what the potentiometer is
  
  //this turns the LED from pin 9 on and the rest off
  digitalWrite(led, LOW); 
  digitalWrite(led2, LOW);   
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
  digitalWrite(led5, HIGH);
  digitalWrite(led6, LOW);
  delay(analogRead(sensorPin));//this reads in what the potentiometer is
  
  //this turns the LED from pin 8 on and the rest off
  digitalWrite(led, LOW); 
  digitalWrite(led2, LOW);   
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
  digitalWrite(led5, LOW);
  digitalWrite(led6, HIGH);
  delay(analogRead(sensorPin));//this reads in what the potentiometer is
    
}
