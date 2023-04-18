unsigned long t1 = 0; // LED를 제어하는데 필요한 타이밍(1초)
unsigned long t2 = 0; // unsigned타입을 사용하는 이유는 millis()함수의 반환타입이 unsigned이기 때문
unsigned long t3 = 0; // 버튼이 눌린 횟수 측정
unsigned long t4 = 0; // LED

int btn_cnt = 0; // 버튼이 1회 눌려지면 1씩 증가
int motion_cnt = 0; // 움직임이 1회 감지되면 1씩 증가

bool old_btn = HIGH;
bool old_motion = LOW;

void setup() {
  Serial.begin(115200); //통신
  pinMode(16, OUTPUT); //출력
  pinMode(17, INPUT); //입력
  pinMode(5, INPUT);

  old_btn = digitalRead(17);
}

void loop() {
  // 모션센서의 상승엣지를 검출
  bool now_motion = digitalRead(5);

  if(old_motion == LOW && now_motion == HIGH){
    motion_cnt++;
  }

  old_motion = now_motion;
  
  //LED가 켜졌다면 3초뒤에 끔
  if(digitalRead(16 == HIGH)) {
    // LED가 켜진 경우
    if(millis() - t4 > 3000){
      digitalWrite(16,LOW);
    }
  }
  // 버튼이 눌려진 횟수
  bool now_btn = digitalRead(17);

  // now_btn = n번째 상태
  // old_btn = n-1번째 상태
  // 직전 상태가 HIGH였는데 현재 상태가 LOW = 하강엣지 == 버튼이 눌러짐
  if(old_btn == HIGH && now_btn == LOW){
    // 하강엣지
    t3 = millis();
  } else if(old_btn == LOW && now_btn == HIGH) {
    // 상승엣지 누르고 있다가 누름을 해제하는 시점
    
    // 누름 - 안누름 사이의 시간을 여기서 출력
    Serial.print("버튼을 누른 시간=");
    Serial.println(millis() - t3); 
    if(millis() - t3 > 50){
      // 버튼이 눌려진 것으로 인정
      digitalWrite(16, HIGH); // LED ON
      t4 = millis(); // LED가 켜진시간
      btn_cnt++;
    }
  }
  
  old_btn = now_btn;

//  메인 루프 안에 2가지 이상의 작업이 있을 경우 delay함수는 사용 불가능
//  if(millis() - t1 > 1000){
//    t1 = millis();
//    bool state = digitalRead(16);
//    digitalWrite(16, !state);
//  }

  if(millis() - t2 > 3000){
    t2 = millis();
    Serial.print("현재 버튼 카운터=");
    Serial.print(btn_cnt);
    Serial.print(", 현재 모션 카운터=");
    Serial.println(motion_cnt);
    // Serial.println("이 문장은 10초 간격으로 출력");
  }
  /*
  digitalWrite(16, HIGH);
  delay(1000);
  digitalWrite(16, LOW);
  delay(1000);
  */
}
