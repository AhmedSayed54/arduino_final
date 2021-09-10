#include<NewPing.h>
#include<Servo.h>
#define servo 3 
#define led 13
#define ldr A0
NewPing sonar(5,4,50);//Firstvalue is triger pin ,second value is echo pin , third value is the range in cm
Servo ser;
void setup() {
  pinMode(led,OUTPUT);
  pinMode(ldr,INPUT);
  Serial.begin(9600);
  delay(100);
  ser.attach(servo);
}

void loop() {
  int ldr_val = analogRead(ldr);
  Serial.print(" ldr =  ");
  Serial.println(ldr_val);
  delay(200);
  if(ldr_val < 50){
  for (int i = 0 ; i <= 180; i++){
    ldr_val = analogRead(ldr);
    Serial.print(" ldr =  ");
    if(ldr_val > 50){
      digitalWrite(led,LOW);
      break;
    }
        ser.write(i);
        int distance = sonar.ping_cm();
        if(distance != 0){
          digitalWrite(led,HIGH);
          Serial.print(ldr_val);
        }else{
          digitalWrite(led,LOW);
        }
        Serial.print("distance =  ");
        Serial.println(distance);
        delay(30);
      }
  
    
 for (int i = 180 ; i >= 0; i--){
  Serial.print("  revert ldr =  ");
    if(ldr_val > 50){
      digitalWrite(led,LOW);
      break;
    }
      ser.write(i);
      int revertdistance = sonar.ping_cm();
      if(revertdistance != 0){
          digitalWrite(led,HIGH);
          Serial.print(ldr_val);
        }else{
          digitalWrite(led,LOW);
        }
      Serial.print(" Revert distance =  ");
      Serial.println(revertdistance);
      delay(30);
    }
  }
 
}
