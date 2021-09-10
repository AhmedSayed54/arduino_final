#define SW1 12
#define SW2 11
#define Buz 6
#define M1 8
#define M2 9
#define EN 10
int SW1_val;
int SW2_val;
int flag1 = 0;
int flag2 = 0;  
void setup() {
  Serial.begin(9600);
  pinMode(SW1, INPUT_PULLUP);
  pinMode(SW2, INPUT_PULLUP);
  pinMode(Buz, OUTPUT);
  pinMode(M1, OUTPUT);
  pinMode(M2, OUTPUT);
  pinMode(EN, OUTPUT);
}

void loop() {

  SW1_val = digitalRead(SW1);
  SW2_val = digitalRead(SW2);  
  if(SW2_val == HIGH){
    tone(Buz,500);
    delay(1000);
    }
  if(SW2_val == LOW){
      noTone(Buz);
    }
  
  
  if(SW1_val == HIGH){
    if(flag1 == 0){
      flag1 = 1;
      flag2 = 0;
      for(int i = 75; i >= 0; i = i - 5){
        analogWrite(EN, i);
        digitalWrite(M1, HIGH);
        digitalWrite(M2, LOW);   
        Serial.println(i);
        delay(20);
     }
    }
  }else{
    if(flag2 == 0){
      flag2 = 1;
      flag1 = 0;
      for(int i = 75; i >= 0; i = i - 5){
        analogWrite(EN, i);
        digitalWrite(M2, HIGH);
        digitalWrite(M1, LOW);
        Serial.println(i);
        delay(20);
      }
    }
  }
}
