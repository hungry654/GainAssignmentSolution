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
	int cat_pos = 1, prev_pos = 1; //고양이 초기 위치, 고양이 이전 위치
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
		printf("현재 턴: %d\n", turn);
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
		printf("=====================================================\n\n");
		Sleep(500);

		//랜덤 주사위 - 고양이 기분 변화
		srand((unsigned)time(NULL));
		int dice = rand() % 6 + 1;
		printf("%d-%d: 주사위 눈이 %d 이하이면 그냥 기분이 나빠집니다.\n", 6, affinity, 6 - affinity);
		printf("주사위를 굴립니다. 또르르...\n");
		printf("%d이(가) 나왔습니다.\n\n", dice);
		if (mood > 0) {
			if (dice <= 6 - affinity) {
				printf("아무 이유 없이 기분이 나빠집니다.\n");
				printf("%s의 기분이 나빠집니다: %d -> %d\n\n", name, mood, mood - 1);
				mood--;
			}
		}
		else if (mood == 0) {
			printf("%s의 기분이 너무 나빠서 더 이상 나빠질 수 없습니다.\n\n", name);
			mood = 0; // 기분이 0 이하로 떨어지지 않도록
		}
		Sleep(500);

		//고양이 행동
		printf("%s가 행동을 합니다.\n", name);
		prev_pos = cat_pos; // 이전 위치 저장
		if (mood == 0) {
			if (cat_pos != HOME_POS) {
				printf("기분이 매우 나쁜 %s은(는) 집으로 향합니다.\n\n", name);
				cat_pos--; // 집으로 이동
			}
		}
		else if (mood == 1) {
			if (scratcher && cat_tower) {
				int dist_scr = abs(cat_pos - scr_pos); 
				int dist_tower = abs(cat_pos - tower_pos);
				if (dist_scr < dist_tower) {
					int close_scr = 0;
					if (close_scr == 0 && cat_pos != scr_pos) {
						printf("%s가 스크래처로 갑니다.\n\n", name);
						if (cat_pos < scratcher) {
							cat_pos++; // 스크래처로 이동
						}
						else if (cat_pos > scratcher) {
							cat_pos--; // 스크래처로 이동
						}
					}
				}
				else if (dist_scr > dist_tower) {
					int close_tower = 0;
					if (close_tower == 0 && cat_pos != tower_pos) {
						printf("%s가 캣타워로 갑니다.\n\n", name);
						if (cat_pos < tower_pos) {
							cat_pos++; // 캣타워로 이동
						}
						else if (cat_pos > tower_pos) {
							cat_pos--; // 캣타워로 이동
						}
					}
				}
			}
			else if (scratcher) {
				if (cat_pos != scr_pos) {
					printf("%s가 스크래처로 갑니다.\n\n", name);
					if (cat_pos < scratcher) {
						cat_pos++; // 스크래처로 이동
					}
					else if (cat_pos > scratcher) {
						cat_pos--; // 스크래처로 이동
					}
				}
			}
			else if (cat_tower) {
				if (cat_pos != tower_pos) {
					printf("%s가 캣타워로 갑니다.\n\n", name);
					if (cat_pos < tower_pos) {
						cat_pos++; // 캣타워로 이동
					}
					else if (cat_pos > tower_pos) {
						cat_pos--; // 캣타워로 이동
					}
				}
			}
			else {
				printf("%s은(는) 놀 거리가 없어서 기분이 좋지 않습니다.\n\n", name);
				printf("%s의 기분이 나빠집니다: %d -> %d\n\n", name, mood, mood - 1);
				mood--;
			}
		}
		else if (mood == 2) {
			printf("%s은(는) 식빵을 굽습니다.\n\n", name);
		}
		else if (mood == 3) {
			printf("%s가 골골송을 부르며 수프를 만들러 갑니다.\n\n", name);
			if (cat_pos != BOWL_POS) {
				printf("%s가 냄비로 갑니다.\n\n", name);
				if (cat_pos < ROOM_WIDTH - 2) {
					 cat_pos++;
				}
				else {
					printf("벽에 막혀 움직일 수 없습니다.\n\n");
				}
			}
		}
		Sleep(500);

		// 고양이 위치에 따른 행동
		if (cat_pos == HOME_POS && prev_pos == HOME_POS) {
			if (turn >= 2) {
				if (mood < 3) {
					printf("%s의 기분이 좋아집니다: %d -> %d\n\n", name, mood, mood + 1);
					mood++;
				}
				else if (mood == 3) {
					printf("%s의 기분이 최고조입니다.\n\n", name);
				}
			}
		}
		else if (cat_pos == BOWL_POS) {
			int Soup_made = rand() % 3 + 1; // 랜덤 수프 만들기
			SoupCount++;
			if (Soup_made == 1) {
				printf("%s(이)가 감자 수프를 만들었습니다!\n", name);
			}
			else if (Soup_made == 2) {
				printf("%s(이)가 양송이 수프를 만들었습니다!\n", name);
			}
			else if (Soup_made == 3) {
				printf("%s(이)가 브로콜리 수프를 만들었습니다!\n", name);
			}
			printf("현재까지 만든 수프: %d개\n\n", SoupCount);
		}
		else if (cat_pos == scr_pos) {
			printf("%s이(가) 스크래처를 긁으며 놀았습니다.\n", name); 
			if (mood < 3) {
					printf("%s의 기분이 조금 좋아집니다: %d -> %d\n\n", name, mood, mood + 1);
					mood++;
			}
			else if(mood == 3) {
				printf("%s의 기분이 최고조입니다.\n\n", name);
				mood == 3;
			}
		}
		else if (cat_pos == tower_pos) {
			printf("%s이(가) 캣타워를 뛰어다닙니다..\n", name);
			if (mood < 3) {
				if (mood == 2) {
					printf("%s의 기분이 좋아집니다: %d -> %d\n", name, mood, mood + 1);
					printf("----기분이 3을 넘어갈 수 없습니다----\n\n");
					mood++;
				}
				else {
					printf("%s의 기분이 많이 좋아집니다: %d -> %d\n\n", name, mood, mood + 2);
					mood += 2;
				}
			}
			else if (mood == 3) {
				printf("%s의 기분이 최고조입니다.\n\n", name);
				mood == 3;
			}
		}
		Sleep(500);

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
		printf("\n\n");
		Sleep(500);

		// 상호작용 (고양이와 집사)
		srand(time(NULL));
		int choice = -1; 
		    //상호작용 선택지 입력
		while (choice < 0 || choice > 1 + mouse_toy + laser_toy) {
			printf("어떤상호작용을하시겠습니까?\n   0.아무것도하지않음\n   1.긁어주기\n");
			if (mouse_toy) {
				printf("   %d. 장난감 쥐로 놀아주기\n", mouse_state);
			}
			if (laser_toy) {
				printf("   %d. 레이저 포인터로 놀아주기\n", laser_state);
			}
			printf(">> ");
			scanf_s("%d", &choice);
		}
		    //상호작용 선택지별 처리
		if (choice == 0) {
			printf("아무것도 하지 않습니다.\n");
			printf("주사위를 굴립니다. 또르르...\n");
			mood--;
			if (mood < 0) {
				mood = 0; // 기분이 0 아래로 떨어지지 않도록 함.
			}
			int dice2 = rand() % 6 + 1;
			printf("%d이(가) 나왔습니다.\n", dice2);
			if (dice2 <= 5) {
				printf("집사와의 관계가 나빠집니다.\n\n");
				printf("집사와의 관계: %d -> %d\n", affinity, affinity - 1);
				affinity--;
				if (affinity < 0) {
					affinity = 0; // 친밀도가 0 아래로 떨어지지 않도록 함.
				}
			}
			else {
				printf("다행히 집사와의 관계가 나빠지지 않았습니다.\n\n");
			}
		}
		else if (choice == 1) {
			printf("%s의 기분은 그대로입니다.: %d\n\n", name, mood);
			printf("주사위를 굴립니다. 또르르...\n");
			int dice2 = rand() % 6 + 1;
			printf("%d이(가) 나왔습니다.\n", dice2);
			if (dice2 >= 5) {
				printf("집사에게 애교를 부립니다.\n");
				printf("집사와의 관계가 좋아집니다.\n\n");
				affinity++;
				if (affinity > 4) {
					affinity = 4; // 친밀도가 4 위로 올라가지 않도록 함.
				}
			}
			else {
				printf("%s의 기분이 그저그럽니다.\n", name);
				printf("분발하세요. 집사!\n\n");
			}
		}
		else if (choice == mouse_state && mouse_toy) {
			printf("장난감 쥐로 %s와 놀아주었습니다.\n", name);
			mood++;
			if (mood > 3) {
				mood = 3; // 기분이 3 위로 올라가지 않도록 함.
			}
			printf("%s의 기분이 조금 좋아집니다: %d -> %d\n", name, mood - 1, mood);
			int dice2 = rand() % 6 + 1;
			printf("%d이(가) 나왔습니다.\n", dice2);
			if (dice2 >= 4) {
				printf("%s가 매우 재미있어합니다.\n", name);
				printf("집사와의 관계가 좋아집니다.\n\n");
				affinity++;
				if (affinity > 4) {
					affinity = 4; // 친밀도가 4 위로 올라가지 않도록 함.
				}
			}
			else {
				printf("%s가 흥미를 잃었습니다.\n", name);
			}
		}
		else if (choice == laser_state && laser_toy) {
			printf("레이저 포인터로 %s와 신나게 놀아주었습니다.\n", name);
			mood += 2;
			if (mood > 3) {
				mood = 3; // 기분이 3 위로 올라가지 않도록 함.
			}
			printf("%s의 기분이 많이 좋아집니다: %d -> %d\n", name, mood - 2, mood );
			int dice2 = rand() % 6 + 1;
			printf("%d이(가) 나왔습니다.\n", dice2);
			if (dice2 >= 2) {
				printf("%s가 매우 신나합니다.\n", name);
				printf("집사와의 관계가 많이 좋아집니다.\n\n");
				affinity++;
				if (affinity > 4) {
					affinity = 4; // 친밀도가 4 위로 올라가지 않도록 함.
				}
			}
			else {
				printf("집사가 피곤해합니다. %s가 실망합니다.\n\n", name);
			}
		}
		Sleep(500);

		// CP 포인트 생산
		printf("%s의 기분(0~3): %d\n", name, mood);
		printf("집사와의 관계(0~4): %d\n", affinity);
		int cp_gain = 0;
		if (mood > 0) {
			cp_gain = (mood - 1) + affinity;
		}
		else {
			cp_gain = affinity;
		}
		cp += cp_gain;
		printf("%s의 기분과 친밀도에 따라서 CP가 %d 포인트 생산되었습니다.\n\n", name, cp_gain);
		
		printf("현재 보유 CP: %d 포인트\n", cp);
		//상점 목록
		int choice_item = -1;
		printf("상점에서 물건을 살 수 있습니다.\n");
		printf("어떤 물건을 구매할까요?\n");
		printf("  0. 아무 것도 사지 않는다.\n");
		if (mouse_toy) {
			printf("  1. 장난감 쥐: 1 CP (품절)\n");
		}
		else {
			printf("  1. 장난감 쥐: 1 CP\n");
		}
		if (laser_toy) {
			printf("  2. 레이저 포인터: 2 CP (품절)\n");
		}
		else {
			printf("  2. 레이저 포인터: 2 CP\n");
		}
		if (scratcher) {
			printf("  3. 스크래처: 4 CP (품절)\n");
		}
		else {
			printf("  3. 스크래처: 4 CP\n");
		}
		if (cat_tower) {
			printf("  4. 캣 타워: 6 CP (품절)\n");
		}
		else {
			printf("  4. 캣 타워: 6 CP\n");
		}
		printf(">> ");
		scanf_s("%d", &choice_item);
		while (choice_item < 0 || choice_item > 4) {
			printf("잘못된 선택입니다. 다시 입력해주세요.\n");
			printf(">> ");
			scanf_s("%d", &choice_item);
		}

		//상점 구매 처리
		int item_check = 0;
		while (!item_check) {
			if (choice_item == 1) {
				if (mouse_toy) {
					printf("장난감 쥐는 이미 구매했습니다.\n\n");
					printf("다시 선택해주세요.>> ");
					scanf_s("%d", &choice_item); // 재입력
					while (choice_item < 0 || choice_item > 4) {
						printf("잘못된 선택입니다. 다시 입력해주세요.\n");
						printf(">> ");
						scanf_s("%d", &choice_item);
					}
					continue; 
				}
				else if (cp >= 1) {
					printf("장난감 쥐를 구매했습니다.\n");
					mouse_toy = 1; // 장난감 쥐 구매
					if (laser_toy) { //상품 번호 지정
						mouse_state = 3;
					}
					else {
						mouse_state = 2;
					}
					cp -= 1;
					item_check = 1; // 구매 완료
					printf("현재 보유 CP: %d 포인트\n\n", cp);
				}
				else {
					printf("CP가 부족합니다. 장난감 쥐를 구매할 수 없습니다.\n\n");
					printf("다시 선택해주세요.>> ");
					scanf_s("%d", &choice_item); // 재입력
					while (choice_item < 0 || choice_item > 4) {
						printf("잘못된 선택입니다. 다시 입력해주세요.\n");
						printf(">> ");
						scanf_s("%d", &choice_item);
					}
					continue;
				}
			}
			else if (choice_item == 2) {
				if (laser_toy) {
					printf("레이저 포인터는 이미 구매했습니다.\n\n");
					printf("다시 선택해주세요.>> ");
					scanf_s("%d", &choice_item); // 재입력
					while (choice_item < 0 || choice_item > 4) {
						printf("잘못된 선택입니다. 다시 입력해주세요.\n");
						printf(">> ");
						scanf_s("%d", &choice_item);
					}
					continue;
				}
				else if (cp >= 2) {
					printf("레이저 포인터를 구매했습니다.\n");
					laser_toy = 1; // 장난감 쥐 구매
					if (mouse_toy) { //상품 번호 지정
						laser_state = 3;
					}
					else {
						laser_state = 2;
					}
					cp -= 2;
					item_check = 1; // 구매 완료
					printf("현재 보유 CP: %d 포인트\n\n", cp);
				}
				else {
					printf("CP가 부족합니다. 레이저 포인터를 구매할 수 없습니다.\n\n");
					printf("다시 선택해주세요.>> ");
					scanf_s("%d", &choice_item); // 재입력
					while (choice_item < 0 || choice_item > 4) {
						printf("잘못된 선택입니다. 다시 입력해주세요.\n");
						printf(">> ");
						scanf_s("%d", &choice_item);
					}
					continue;
				}
			}
			else if (choice_item == 3) {
				if (scratcher) {
					printf("스크래처는 이미 구매했습니다.\n\n");
					printf("다시 선택해주세요.>> ");
					scanf_s("%d", &choice_item); // 재입력
					while (choice_item < 0 || choice_item > 4) {
						printf("잘못된 선택입니다. 다시 입력해주세요.\n");
						printf(">> ");
						scanf_s("%d", &choice_item);
					}
					continue;
				}
				else if (cp >= 4) {
					printf("스크래처를 구매했습니다.\n");
					scratcher = 1;
					for (int i = 0; i < ROOM_WIDTH - 1; i++) {
						int r1 = rand() % (ROOM_WIDTH - 2) + 1; // 랜덤 위치 
						if (r1 != HOME_POS && r1 != BOWL_POS && r1 != tower_pos) {
							scr_pos = r1;
							break;
						}
					}
					printf("스크래처 설치를 완료했습니다.\n");
					cp -= 4;
					item_check = 1; // 구매 완료
					printf("현재 보유 CP: %d 포인트\n\n", cp);
				}
				else {
					printf("CP가 부족합니다. 스크래처를 구매할 수 없습니다.\n\n");
					printf("다시 선택해주세요.>> ");
					scanf_s("%d", &choice_item); // 재입력
					while (choice_item < 0 || choice_item > 4) {
						printf("잘못된 선택입니다. 다시 입력해주세요.\n");
						printf(">> ");
						scanf_s("%d", &choice_item);
					}
					continue;
				}
			}
			else if (choice_item == 4) {
				if (cat_tower) {
					printf("캣 타워는 이미 구매했습니다.\n\n");
					printf("다시 선택해주세요.>> ");
					scanf_s("%d", &choice_item); // 재입력
					while (choice_item < 0 || choice_item > 4) {
						printf("잘못된 선택입니다. 다시 입력해주세요.\n");
						printf(">> ");
						scanf_s("%d", &choice_item);
					}
					continue;
				}
				else if (cp >= 6) {
					printf("캣 타워를 구매했습니다.\n");
					cat_tower = 1;
					for (int i = 0; i < ROOM_WIDTH - 1; i++) {
						int r2 = rand() % (ROOM_WIDTH - 2) + 1; // 랜덤 위치 
						if (r2 != HOME_POS && r2 != BOWL_POS && r2 != scr_pos) {
							tower_pos = r2;
							break;
						}
					}
					printf("캣 타워 설치를 완료했습니다.\n");
					cp -= 6;
					item_check = 1; // 구매 완료
					printf("현재 보유 CP: %d 포인트\n\n", cp);
				}
				else {
					printf("CP가 부족합니다. 캣 타워를 구매할 수 없습니다.\n\n");
					printf("다시 선택해주세요.>> ");
					scanf_s("%d", &choice_item); // 재입력
					while (choice_item < 0 || choice_item > 4) {
						printf("잘못된 선택입니다. 다시 입력해주세요.\n");
						printf(">> ");
						scanf_s("%d", &choice_item);
					}
					continue;
				}
			}
			else if (choice_item == 0) {
				printf("아무것도 구매하지 않습니다.\n\n");
				item_check = 1; //구매 확인
			}
		}

		//돌발퀘스트!!
		if (turn == 3) {
			char quest[100] = { 0 };
			printf("****돌발 퀘스트 발생!!****\n");
			printf("본인 고양이의 이름을 입력하세요! >> ");
			while (1) {
				scanf_s("%s", quest, (unsigned)sizeof(quest));
				if (strcmp(quest, name) == 0) {
					printf("퀘스트 성공! %s의 이름을 정확히 입력했습니다.\n", name);
					break;
				}
				else {
					printf("퀘스트 실패! 다시 시도하세요. >> ");
				}
			}
		}
		turn++;
		Sleep(2000);
		system("cls");
	}
	return 0;
	// 완성
}