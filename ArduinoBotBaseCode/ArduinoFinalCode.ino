int RightMotor = 12; //Low for Reverse, High for Forward
int RightBreak = 9;  //High for break, Low for release
int RightSpeed = 3; //Speed, analogWrite 0-255
 
int LeftMotor = 13;//High for Reverse, Low for Forward
int LeftBreak = 8; //High for break, Low for release
int LeftSpeed = 11; //Speed, analogWrite 0-255

const int pingPin = 7;  //Ping pin
const int warningPin = 6;
long distance = 0;      //Distance holder

void setup()
{
    Serial.begin(9600);
    
    pinMode(LeftMotor, OUTPUT);
    pinMode(LeftBreak, OUTPUT);
    pinMode(RightMotor, OUTPUT);
    pinMode(RightBreak, OUTPUT);
    pinMode(pingPin, OUTPUT);
    pinMode(warningPin, OUTPUT);
}

void loop()
{
  /*
    digitalWrite(13,HIGH);
    delay(1000);
    digitalWrite(13,LOW);
    delay(1000);
    */ //LED Test
    
    
    distance = getDist();
    delay(200);
    if(distance<=700){
        digitalWrite(warningPin, HIGH);
        leftBackward();
        rightBackward();
        delay(1000);
        breakWheels();
        digitalWrite(warningPin, LOW);
    }
    else if (Serial.available() > 0) {
        char command = Serial.read();

        switch (command){
         case 'w': //Forward
          Serial.println("Forward");
          rightForward();
          leftForward();
         break; 
         case 'a': //Left
          Serial.println("Left");
          rightForward();
          digitalWrite(LeftBreak, HIGH);
         break; 
         case 's': //Back
          Serial.println("Backward");
          rightBackward();
          leftBackward();
         break; 
         case 'd': //Right
          Serial.println("Right");
          digitalWrite(RightBreak, HIGH);
          leftForward();
         break; 
         case 'b': //Break
          Serial.println("Break");
          breakWheels();
         break; 
         
        }
        
    }
    
    delay(100);
}

//Direction Functions!!
int getDist(){
  //Send ping out with low first to ensure a clean high ping of 2ms or more.
    pinMode(pingPin, OUTPUT);
    digitalWrite(pingPin, LOW);
    delayMicroseconds(2);
    digitalWrite(pingPin, HIGH);
    delayMicroseconds(5);
    digitalWrite(pingPin, LOW);

    pinMode(pingPin, INPUT);
    return pulseIn(pingPin, HIGH);

}


void rightForward(){
 digitalWrite(RightMotor, LOW);
 digitalWrite(RightBreak, LOW);
 analogWrite(RightSpeed, 255); 
}

void leftForward(){
 digitalWrite(LeftMotor, HIGH);
 digitalWrite(LeftBreak, LOW);
 analogWrite(LeftSpeed, 255);  
}

void rightBackward(){
 digitalWrite(RightMotor, HIGH);
 digitalWrite(RightBreak, LOW);
 analogWrite(RightSpeed, 255); 
}

void leftBackward(){
 digitalWrite(LeftMotor, LOW);
 digitalWrite(LeftBreak, LOW);
 analogWrite(LeftSpeed, 255);  
}

void breakWheels(){
 digitalWrite(RightBreak, HIGH);
 digitalWrite(LeftBreak, HIGH); 
}
