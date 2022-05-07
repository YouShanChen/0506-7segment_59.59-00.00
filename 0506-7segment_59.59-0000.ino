const byte segment_pins[8] = {9, 8, 7, 6, 5, 4, 3, 2};
const byte power_pins[4] = {10, 11, 12, 13};
const byte digit[10][8] = {
  {0, 0, 0, 0, 0, 0, 1, 1},
  {1, 0, 0, 1, 1, 1, 1, 1},
  {0, 0, 1, 0, 0, 1, 0, 1},
  {0, 0, 0, 0, 1, 1, 0, 1},
  {1, 0, 0, 1, 1, 0, 0, 1},
  {0, 1, 0, 0, 1, 0, 0, 1},
  {1, 1, 0, 0, 0, 0, 0, 1},
  {0, 0, 0, 1, 1, 1, 1, 1},
  {0, 0, 0, 0, 0, 0, 0, 1},
  {0, 0, 0, 1, 1, 0, 0, 1},
};
const byte digit2[10][8] = {
  {0, 0, 0, 0, 0, 0, 1, 0},
  {1, 0, 0, 1, 1, 1, 1, 0},
  {0, 0, 1, 0, 0, 1, 0, 0},
  {0, 0, 0, 0, 1, 1, 0, 0},
  {1, 0, 0, 1, 1, 0, 0, 0},
  {0, 1, 0, 0, 1, 0, 0, 0},
  {1, 1, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 1, 1, 1, 1, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 1, 1, 0, 0, 0},
};
const byte scan[4][4] = {
  {1, 0, 0, 0},
  {0, 1, 0, 0},
  {0, 0, 1, 0},
  {0, 0, 0, 1}
};
byte btn;
byte d[4];
unsigned long start_time, count;

void setup()
{
  for (byte i = 0; i < 8; i++) {
    pinMode(segment_pins[i], OUTPUT); 
  }
  for (byte i = 0; i < 4; i++) {
    pinMode(power_pins[i], OUTPUT);
  }
  start_time =6000;
  pinMode(1, INPUT_PULLUP);
}

void loop()
{
btn = digitalRead(1);
  if(btn==HIGH){
  count = start_time-(millis() / 10);
  }
  else{count=millis() / 10;}
  set_decimal(count);
  for(byte k = 0; k < 4; k++){

    for(byte j = 0; j < 4; j++) {
      digitalWrite(power_pins[j],LOW);
    }    

    if(k==2){ 
      for(byte j = 0; j < 8; j++){
      digitalWrite(segment_pins[j], digit2[d[k]][j]);
      }
    }
    else{
     for(byte j = 0; j < 8; j++){
      digitalWrite(segment_pins[j], digit[d[k]][j]);
     }
    }
    for(byte j = 0; j < 4; j++) {
      digitalWrite(power_pins[j], scan[k][j]);
    }   
    delay(4);
  }
}

void set_decimal(int count){ 
  d[0] = count%10; 
  d[1] = (count/10)%10; 
  d[2] = (count/100)%10; 
  d[3] = (count/1000)%10; 
}
