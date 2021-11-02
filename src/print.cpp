#include "Arduino.h"
#include "print.h"

LedControl lc = LedControl(12, 11, 10, 4);

void print_win(){
	for(int i=0;i<4; i++)
		for(int j=0; j<8; j++)
			lc.setRow(3-i,j,p_win[i][j]);  
}

void print_lose(){
	for(int i=0;i<4; i++)
		for(int j=0; j<8; j++)
			lc.setRow(3-i,j,p_lose[i][j]);  
}

void reset_print(){
	for (int num = 0; num < 4; num++) // 매트릭스 0번부터 3번까지 세팅
	{
		lc.shutdown(num, false); // 0~3번까지 매트릭스 절전모드 해제
		lc.setIntensity(num, 8); // 매트릭스의 밝기 선언 0~15의 수
		lc.clearDisplay(num); // 매트릭스 led를 초기화
	}
}

void print_hand(int hand, int p){
	for(int j = 0; j< 8; j++){
		lc.setRow(p, j, p_hands[hand-1][j]);
	}
}