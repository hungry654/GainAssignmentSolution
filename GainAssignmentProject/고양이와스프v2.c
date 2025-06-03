#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>

#define ROOM_WIDTH 15
#define HOME_POS 1
#define BOWL_POS (ROOM_WIDTH -2)

int main(void) {
	int mood = 3; //초기 고양이 기분
	int cp = 0; //상점 포인트
	int affinity = 2; // 집사와의 초기 친밀도
	int SoupCount = 0; //스프 개수
	int mouse_toy = 0, laser_toy = 0, scratcher = 0, cat_tower = 0;
	int mouse_state = 0, laser_state = 0; // 구매 후 상품상태
	int scr_pos = -1, tower_pos = -1; // 구조물 초기 위치 (-1은 위치 없음을 의미)
	int cat_pos = 2, prev_pos = 2; //고양이 초기 위치, 고양이 이전 위치
	int turn = 1; //첫 번째 턴
	char name[100] = { 0 };

	//고양이 만들기 및 이름 정하기
	printf("****고양이와 스프****\n");
	printf("  /\\_/\\ \n");
	printf(" ( o.o )\n");
	printf(" |> ^ <| /\\ \n");
	printf(" |  _  |/ \n");
	printf(" (_| |_) \n");
	printf("두 발로 서있는 고양이를 입양했습니다.\n");
	printf("고양이의 이름을 지어주세요>> ");
	scanf_s("%s", name, (unsigned)sizeof(name));
	printf("고양이의 이름은 %s입니다.\n", name);
	Sleep(3000);
	system("cls");
}