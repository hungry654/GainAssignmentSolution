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

	while (1) {
		// 현재 상태창
		printf("======================현재 상태======================\n");
		printf("현재까지 만든 수프: %d개\n", SoupCount);
		printf("CP: %d 포인트\n", cp);
		printf("%s의 기분(0~3): %d\n", name, mood);
		switch (mood) {
		case 0:
			printf("기분이 매우 나쁩니다.\n");
			break;
		case 1:
			printf("심심해 합니다.\n");
			break;
		case 2:
			printf("식빵을 굽습니다.\n");
			printf("  /\\_/\\ \n");
			printf(" ( o.o )___/\\ \n");
			printf("  | _____  | \\ \n");
			printf(" (_|     (_| \n");
			break;
		case 3:
			printf("골골송을 부릅니다.\n");
			break;
		}
		printf("집사와의 관계(0~4): %d\n", affinity);
		switch (affinity) {
		case 0:
			printf("곁에 오는 것조차 긿어합니다.\n");
			break;
		case 1:
			printf("간식 자판기 취급입니다.\n");
			break;
		case 2:
			printf("그럭저럭 쓸만한 집사입니다.\n");
			break;
		case 3:
			printf("훌륭한 집사로 인정받고 있습니다.\n");
			break;
		case 4:
			printf("집사 껌딱지입니다.\n");
			break;
		}
		printf("=====================================================\n");
		Sleep(3000);

		//방 만들기
		//첫 번째 줄
		for (int i = 0; i < ROOM_WIDTH; i++) {
			printf("#");
		}
		printf("\n");
		//두 번째 줄
		printf("#");
		for (int i = 1; i < ROOM_WIDTH - 1; i++) {
			if (i == HOME_POS) {
				printf("H");
			}
			else if (i == BOWL_POS) {
				printf("B");
			}
			else if (i == scr_pos) {
				printf("S");
			}
			else if (i == tower_pos) {
				printf("T");
			}
			else {
				printf(" ");
			}
		}
		printf("#\n");
		//세 번째 줄
		printf("#");
		for (int i = 1; i < ROOM_WIDTH - 1; i++) {
			if (i == cat_pos) {
				printf("C");
			}
			else if (i == prev_pos && cat_pos != prev_pos) {
				printf(".");
			}
			else {
				printf(" ");
			}
		}
		printf("#\n");
		//네 번째 줄
		for (int i = 0; i < ROOM_WIDTH; i++) {
			printf("#");
		}
		printf("\n");

		//랜덤 주사위 - 고양이 기분 변화
		srand((unsigned)time(NULL));
		int dice = rand() % 6 + 1;
		printf("%d-%d: 주사위 눈이 %d 이하이면 그냥 기분이 나빠집니다.\n", 6, affinity, 6 - affinity);
		printf("주사위를 굴립니다. 또르르...\n");
		printf("%d이(가) 나왔습니다.\n", dice);
		if (mood > 0) {
			if (dice <= 6 - affinity) {
				printf("아무 이유 없이 기분이 나빠집니다.\n");
				printf("%s의 기분이 나빠집니다: %d -> %d\n", name, mood, mood - 1);
				mood--;
			}
		}
		else {
			printf("%s의 기분이 너무 나빠서 더 이상 나빠질 수 없습니다.\n", name);
			mood = 0; // 기분이 0 이하로 떨어지지 않도록
		}

		//고양이 행동
		printf("%s가 행동을 합니다.\n", name);
		prev_pos = cat_pos; // 이전 위치 저장
		if (mood == 0) {
			printf("기분이 매우 나쁜 %s은(는) 집으로 향합니다.\n", name);
			cat_pos = HOME_POS; // 집으로 이동
		}
	}
}