int RightMotor = 13; //Low for Reverse, High for Forward
int RightBreak = 8;  //High for break, Low for release
int RightSpeed = 11; //Speed, analogWrite 0-255
 
int LeftMotor = 12;//High for Reverse, Low for Forward
int LeftBreak = 9; //High for break, Low for release
int LeftSpeed = 3; //Speed, analogWrite 0-255


void setup()
{
    Serial.begin(9600);
    
    pinMode(LeftMotor, OUTPUT);
    pinMode(LeftBreak, OUTPUT);
    pinMode(RightMotor, OUTPUT);
    pinMode(RightBreak, OUTPUT);
}

void loop()
{
  /*
    digitalWrite(13,HIGH);
    delay(1000);
    digitalWrite(13,LOW);
    delay(1000);
    */ //LED Test

    if (Serial.available() > 0) {
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

void leftForward(){
 digitalWrite(LeftMotor, LOW);
 digitalWrite(LeftBreak, LOW);
 analogWrite(LeftSpeed, 255); 
}

void rightForward(){
 digitalWrite(RightMotor, HIGH);
 digitalWrite(RightBreak, LOW);
 analogWrite(RightSpeed, 255);  
}

void leftBackward(){
 digitalWrite(LeftMotor, HIGH);
 digitalWrite(LeftBreak, LOW);
 analogWrite(LeftSpeed, 255); 
}

void rightBackward(){
 digitalWrite(RightMotor, LOW);
 digitalWrite(RightBreak, LOW);
 analogWrite(RightSpeed, 255);  
}

void breakWheels(){
 digitalWrite(RightBreak, HIGH);
 digitalWrite(LeftBreak, HIGH); 
}
