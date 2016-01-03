void start(int);
void ok(int);
void ng(int);
boolean light=false;
int rtime = random(1000,10000);
int stime;
boolean sta = false;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin 13 as an output.
  pinMode(13, OUTPUT);
  pinMode(3, INPUT);
  pinMode(12, OUTPUT);
  pinMode(2, INPUT);
  pinMode(11, OUTPUT);
}

void start(int port){
  tone(port,1000);
  delay(800);
  noTone(8);
}

void ng(int port){
  tone(port,400);
  delay(100);
  noTone(port);
}

void ok(int port){
  tone(port,3300);
  delay(100);
  noTone(port);
  delay(100);
  tone(port,2700);
  delay(100);
  noTone(port);
  delay(100);
  tone(port,3300);
  delay(100);
  noTone(port);
  delay(100);
  tone(port,2700);
  delay(100);
  noTone(port);
}


// the loop function runs over and over again forever
void loop() {
  if(!sta){//もし始まっていなかったら、
    start(8);//スタート音をならして、
    sta = true;//startフラグをtrueにして、2回目以降ならないようにして、
    stime = millis();//スタート時間を記録
  }
  
  if(!light && millis() - stime > rtime){//スタート時間から乱数時間経ったら、
    light = true;//ライトフラグをtrueにして、
    digitalWrite(11,HIGH);//LEDを光らせる
  }
  
  if (digitalRead(2)==HIGH) {
    if(light){//光ってからボタンを押したら
      digitalWrite(12, HIGH);//光らせて
      ok(8);//正解音をならす
      delay(1000000000);
    }
    if(!light){//光る前にボタンを押したら
      ng(8);//ブザーをならす
      stime = millis();//再スタート
    }

  }


  if (digitalRead(3)==HIGH) {
    if(light){//光ってからボタンを押したら
      digitalWrite(13, HIGH);//光らせて
      ok(8);//正解音をならす
      delay(1000000000);
    }
    if(!light){//光る前にボタンを押したら
      ng(8);//ブザーをならす
      stime = millis();//再スタート
    }
  }
  
}



