//핀 번호는 5, 6, 7
#define scissors 1
#define rock 2
#define paper 3
#include "print.h"
/*1:가위
 * 2:바위
 * 3:보
 * 
 */
/* 컴퓨터가
 *  이겼을때: 1
 * 비겼을때: 0
 * 졌을때: -1
 */
 
int getInput();

void mukjipa(int prev_r, int hand);
void startGame();

/*
 * 버튼입력이 가위, 바위 보 중 무엇인지
 */

void setup() {

  reset_print();
  Serial.begin(9600);
  Serial.print("setup start");
  
  pinMode(rock+4, INPUT); 
  pinMode(scissors+4, INPUT); 
  pinMode(paper+4, INPUT); 
  Serial.print("setup complete");
}

void loop() {
  startGame();
}

int getInput(){
  Serial.println("f get_input");
  while(1){
    
    if (digitalRead(rock+4) == 1){
      //print_hand(rock, 3);
      return rock;
    }
    if (digitalRead(scissors+4) == 1){
      //print_hand(scissors, 3);
      return scissors;
    }
    if (digitalRead(paper+4) == 1){
      //print_hand(paper, 3);
      return paper;
    }
    //delay(200);
  }
}

/**
* 가위바위보를 시작하고 그 결과에 따라 묵찌빠를 시작할지 아니면
* 다시 가위바위보를 진행할지 결정 합니다.
*/
void startGame(){
  int rand_hand = random(3)+1;
  int input = getInput();
  print_hand(input, 3);
  print_hand(rand_hand, 0);
  delay(1000);
  reset_print();
  
  if(rand_hand == input+1){//컴퓨터가 이겼을때
    Serial.print("묵찌빠시작");
    mukjipa(1, rand_hand);
    return;
  }
  if(rand_hand == input){
    //w_or_l = 0;
    startGame();
    return;
  }
  if(rand_hand = input -1){
     Serial.print("묵찌빠시작");
    mukjipa(-1, rand_hand);
  }
}

/*
 * prev_r
 * 1: 컴퓨터가 이김
 * -1:컴퓨터가 짐
 */
void mukjipa(int prev_r, int hand){
  int input;
  int rand_hand = random(3)+1;
  
  if(prev_r == 1){//전 묵찌빠나 가위바위보에서 컴퓨터가 이겼을때
    print_hand(hand, 0);//땡
    delay(500);
    reset_print();
    delay(500);
    print_hand(hand, 0);//땡
    delay(500);
    reset_print();
    input = getInput();
    print_hand(input, 3);
    print_hand(rand_hand, 0);//뽝!

    delay(2000);
    reset_print();
    if(rand_hand == input+1){//이겼을때
      mukjipa(1, rand_hand);
      return;
    }
    if(rand_hand == input){
      print_lose();
      delay(10000);
      reset_print();
      return;
    }
    //rand_hand<input
    mukjipa(-1, rand_hand);
    return;
  }
  //전 게임에서 컴퓨터가 졌을때
  //prev_r == -1
  input = getInput();
  input = getInput();
  input = getInput();
  print_hand(input,3);
  print_hand(rand_hand, 0);
  delay(2000);
  
  reset_print();
  if(rand_hand == input+1){
      mukjipa(1, rand_hand);
      return;
  }
  if(rand_hand == input){
      //looooose
      print_win();//you win
      delay(10000);
      reset_print();
      return;
  }

  mukjipa(-1, rand_hand);
}
