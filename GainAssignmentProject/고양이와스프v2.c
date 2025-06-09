#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>

#define ROOM_WIDTH 15
#define HOME_POS 1
#define BOWL_POS (ROOM_WIDTH -2)

int main(void) {
	int mood = 3; //�ʱ� ����� ���
	int cp = 0; //���� ����Ʈ
	int affinity = 2; // ������� �ʱ� ģ�е�
	int SoupCount = 0; //���� ����
	int mouse_toy = 0, laser_toy = 0, scratcher = 0, cat_tower = 0;
	int mouse_state = 0, laser_state = 0; // ���� �� ��ǰ����
	int scr_pos = -1, tower_pos = -1; // ������ �ʱ� ��ġ (-1�� ��ġ ������ �ǹ�)
	int cat_pos = 1, prev_pos = 1; //����� �ʱ� ��ġ, ����� ���� ��ġ
	int turn = 1; //ù ��° ��
	char name[100] = { 0 };

	//����� ����� �� �̸� ���ϱ�
	printf("****����̿� ����****\n");
	printf("  /\\_/\\ \n");
	printf(" ( o.o )\n");
	printf(" |> ^ <| /\\ \n");
	printf(" |  _  |/ \n");
	printf(" (_| |_) \n");
	printf("�� �߷� ���ִ� ����̸� �Ծ��߽��ϴ�.\n");
	printf("������� �̸��� �����ּ���>> ");
	scanf_s("%s", name, (unsigned)sizeof(name));
	printf("������� �̸��� %s�Դϴ�.\n", name);
	Sleep(3000);
	system("cls");

	while (1) {
		// ���� ����â
		printf("======================���� ����======================\n");
		printf("���� ��: %d\n", turn);
		printf("������� ���� ����: %d��\n", SoupCount);
		printf("CP: %d ����Ʈ\n", cp);
		printf("%s�� ���(0~3): %d\n", name, mood);
		switch (mood) {
		case 0:
			printf("����� �ſ� ���޴ϴ�.\n");
			break;
		case 1:
			printf("�ɽ��� �մϴ�.\n");
			break;
		case 2:
			printf("�Ļ��� �����ϴ�.\n");
			printf("  /\\_/\\ \n");
			printf(" ( o.o )___/\\ \n");
			printf("  | _____  | \\ \n");
			printf(" (_|     (_| \n");
			break;
		case 3:
			printf("������ �θ��ϴ�.\n");
			break;
		}
		printf("������� ����(0~4): %d\n", affinity);
		switch (affinity) {
		case 0:
			printf("�翡 ���� ������ �����մϴ�.\n");
			break;
		case 1:
			printf("���� ���Ǳ� ����Դϴ�.\n");
			break;
		case 2:
			printf("�׷����� ������ �����Դϴ�.\n");
			break;
		case 3:
			printf("�Ǹ��� ����� �����ް� �ֽ��ϴ�.\n");
			break;
		case 4:
			printf("���� �������Դϴ�.\n");
			break;
		}
		printf("=====================================================\n\n");
		Sleep(500);

		//���� �ֻ��� - ����� ��� ��ȭ
		srand((unsigned)time(NULL));
		int dice = rand() % 6 + 1;
		printf("%d-%d: �ֻ��� ���� %d �����̸� �׳� ����� �������ϴ�.\n", 6, affinity, 6 - affinity);
		printf("�ֻ����� �����ϴ�. �Ǹ���...\n");
		printf("%d��(��) ���Խ��ϴ�.\n\n", dice);
		if (mood > 0) {
			if (dice <= 6 - affinity) {
				printf("�ƹ� ���� ���� ����� �������ϴ�.\n");
				printf("%s�� ����� �������ϴ�: %d -> %d\n\n", name, mood, mood - 1);
				mood--;
			}
		}
		else if (mood == 0) {
			printf("%s�� ����� �ʹ� ������ �� �̻� ������ �� �����ϴ�.\n\n", name);
			mood = 0; // ����� 0 ���Ϸ� �������� �ʵ���
		}
		Sleep(500);

		//����� �ൿ
		printf("%s�� �ൿ�� �մϴ�.\n", name);
		prev_pos = cat_pos; // ���� ��ġ ����
		if (mood == 0) {
			if (cat_pos != HOME_POS) {
				printf("����� �ſ� ���� %s��(��) ������ ���մϴ�.\n\n", name);
				cat_pos--; // ������ �̵�
			}
		}
		else if (mood == 1) {
			if (scratcher && cat_tower) {
				int dist_scr = abs(cat_pos - scr_pos); 
				int dist_tower = abs(cat_pos - tower_pos);
				if (dist_scr < dist_tower) {
					int close_scr = 0;
					if (close_scr == 0 && cat_pos != scr_pos) {
						printf("%s�� ��ũ��ó�� ���ϴ�.\n\n", name);
						if (cat_pos < scratcher) {
							cat_pos++; // ��ũ��ó�� �̵�
						}
						else if (cat_pos > scratcher) {
							cat_pos--; // ��ũ��ó�� �̵�
						}
					}
				}
				else if (dist_scr > dist_tower) {
					int close_tower = 0;
					if (close_tower == 0 && cat_pos != tower_pos) {
						printf("%s�� ĹŸ���� ���ϴ�.\n\n", name);
						if (cat_pos < tower_pos) {
							cat_pos++; // ĹŸ���� �̵�
						}
						else if (cat_pos > tower_pos) {
							cat_pos--; // ĹŸ���� �̵�
						}
					}
				}
			}
			else if (scratcher) {
				if (cat_pos != scr_pos) {
					printf("%s�� ��ũ��ó�� ���ϴ�.\n\n", name);
					if (cat_pos < scratcher) {
						cat_pos++; // ��ũ��ó�� �̵�
					}
					else if (cat_pos > scratcher) {
						cat_pos--; // ��ũ��ó�� �̵�
					}
				}
			}
			else if (cat_tower) {
				if (cat_pos != tower_pos) {
					printf("%s�� ĹŸ���� ���ϴ�.\n\n", name);
					if (cat_pos < tower_pos) {
						cat_pos++; // ĹŸ���� �̵�
					}
					else if (cat_pos > tower_pos) {
						cat_pos--; // ĹŸ���� �̵�
					}
				}
			}
			else {
				printf("%s��(��) �� �Ÿ��� ��� ����� ���� �ʽ��ϴ�.\n\n", name);
				printf("%s�� ����� �������ϴ�: %d -> %d\n\n", name, mood, mood - 1);
				mood--;
			}
		}
		else if (mood == 2) {
			printf("%s��(��) �Ļ��� �����ϴ�.\n\n", name);
		}
		else if (mood == 3) {
			printf("%s�� ������ �θ��� ������ ���鷯 ���ϴ�.\n\n", name);
			if (cat_pos != BOWL_POS) {
				printf("%s�� ����� ���ϴ�.\n\n", name);
				if (cat_pos < ROOM_WIDTH - 2) {
					 cat_pos++;
				}
				else {
					printf("���� ���� ������ �� �����ϴ�.\n\n");
				}
			}
		}
		Sleep(500);

		// ����� ��ġ�� ���� �ൿ
		if (cat_pos == HOME_POS && prev_pos == HOME_POS) {
			if (turn >= 2) {
				if (mood < 3) {
					printf("%s�� ����� �������ϴ�: %d -> %d\n\n", name, mood, mood + 1);
					mood++;
				}
				else if (mood == 3) {
					printf("%s�� ����� �ְ����Դϴ�.\n\n", name);
				}
			}
		}
		else if (cat_pos == BOWL_POS) {
			int Soup_made = rand() % 3 + 1; // ���� ���� �����
			SoupCount++;
			if (Soup_made == 1) {
				printf("%s(��)�� ���� ������ ��������ϴ�!\n", name);
			}
			else if (Soup_made == 2) {
				printf("%s(��)�� ����� ������ ��������ϴ�!\n", name);
			}
			else if (Soup_made == 3) {
				printf("%s(��)�� ����ݸ� ������ ��������ϴ�!\n", name);
			}
			printf("������� ���� ����: %d��\n\n", SoupCount);
		}
		else if (cat_pos == scr_pos) {
			printf("%s��(��) ��ũ��ó�� ������ ��ҽ��ϴ�.\n", name); 
			if (mood < 3) {
					printf("%s�� ����� ���� �������ϴ�: %d -> %d\n\n", name, mood, mood + 1);
					mood++;
			}
			else if(mood == 3) {
				printf("%s�� ����� �ְ����Դϴ�.\n\n", name);
				mood == 3;
			}
		}
		else if (cat_pos == tower_pos) {
			printf("%s��(��) ĹŸ���� �پ�ٴմϴ�..\n", name);
			if (mood < 3) {
				if (mood == 2) {
					printf("%s�� ����� �������ϴ�: %d -> %d\n", name, mood, mood + 1);
					printf("----����� 3�� �Ѿ �� �����ϴ�----\n\n");
					mood++;
				}
				else {
					printf("%s�� ����� ���� �������ϴ�: %d -> %d\n\n", name, mood, mood + 2);
					mood += 2;
				}
			}
			else if (mood == 3) {
				printf("%s�� ����� �ְ����Դϴ�.\n\n", name);
				mood == 3;
			}
		}
		Sleep(500);

		//�� �����
	//ù ��° ��
		for (int i = 0; i < ROOM_WIDTH; i++) {
			printf("#");
		}
		printf("\n");
		//�� ��° ��
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
		//�� ��° ��
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
		//�� ��° ��
		for (int i = 0; i < ROOM_WIDTH; i++) {
			printf("#");
		}
		printf("\n\n");
		Sleep(500);

		// ��ȣ�ۿ� (����̿� ����)
		srand(time(NULL));
		int choice = -1; 
		    //��ȣ�ۿ� ������ �Է�
		while (choice < 0 || choice > 1 + mouse_toy + laser_toy) {
			printf("���ȣ�ۿ����Ͻðڽ��ϱ�?\n   0.�ƹ��͵���������\n   1.�ܾ��ֱ�\n");
			if (mouse_toy) {
				printf("   %d. �峭�� ��� ����ֱ�\n", mouse_state);
			}
			if (laser_toy) {
				printf("   %d. ������ �����ͷ� ����ֱ�\n", laser_state);
			}
			printf(">> ");
			scanf_s("%d", &choice);
		}
		    //��ȣ�ۿ� �������� ó��
		if (choice == 0) {
			printf("�ƹ��͵� ���� �ʽ��ϴ�.\n");
			printf("�ֻ����� �����ϴ�. �Ǹ���...\n");
			mood--;
			if (mood < 0) {
				mood = 0; // ����� 0 �Ʒ��� �������� �ʵ��� ��.
			}
			int dice2 = rand() % 6 + 1;
			printf("%d��(��) ���Խ��ϴ�.\n", dice2);
			if (dice2 <= 5) {
				printf("������� ���谡 �������ϴ�.\n\n");
				printf("������� ����: %d -> %d\n", affinity, affinity - 1);
				affinity--;
				if (affinity < 0) {
					affinity = 0; // ģ�е��� 0 �Ʒ��� �������� �ʵ��� ��.
				}
			}
			else {
				printf("������ ������� ���谡 �������� �ʾҽ��ϴ�.\n\n");
			}
		}
		else if (choice == 1) {
			printf("%s�� ����� �״���Դϴ�.: %d\n\n", name, mood);
			printf("�ֻ����� �����ϴ�. �Ǹ���...\n");
			int dice2 = rand() % 6 + 1;
			printf("%d��(��) ���Խ��ϴ�.\n", dice2);
			if (dice2 >= 5) {
				printf("���翡�� �ֱ��� �θ��ϴ�.\n");
				printf("������� ���谡 �������ϴ�.\n\n");
				affinity++;
				if (affinity > 4) {
					affinity = 4; // ģ�е��� 4 ���� �ö��� �ʵ��� ��.
				}
			}
			else {
				printf("%s�� ����� �����׷��ϴ�.\n", name);
				printf("�й��ϼ���. ����!\n\n");
			}
		}
		else if (choice == mouse_state && mouse_toy) {
			printf("�峭�� ��� %s�� ����־����ϴ�.\n", name);
			mood++;
			if (mood > 3) {
				mood = 3; // ����� 3 ���� �ö��� �ʵ��� ��.
			}
			printf("%s�� ����� ���� �������ϴ�: %d -> %d\n", name, mood - 1, mood);
			int dice2 = rand() % 6 + 1;
			printf("%d��(��) ���Խ��ϴ�.\n", dice2);
			if (dice2 >= 4) {
				printf("%s�� �ſ� ����־��մϴ�.\n", name);
				printf("������� ���谡 �������ϴ�.\n\n");
				affinity++;
				if (affinity > 4) {
					affinity = 4; // ģ�е��� 4 ���� �ö��� �ʵ��� ��.
				}
			}
			else {
				printf("%s�� ��̸� �Ҿ����ϴ�.\n", name);
			}
		}
		else if (choice == laser_state && laser_toy) {
			printf("������ �����ͷ� %s�� �ų��� ����־����ϴ�.\n", name);
			mood += 2;
			if (mood > 3) {
				mood = 3; // ����� 3 ���� �ö��� �ʵ��� ��.
			}
			printf("%s�� ����� ���� �������ϴ�: %d -> %d\n", name, mood - 2, mood );
			int dice2 = rand() % 6 + 1;
			printf("%d��(��) ���Խ��ϴ�.\n", dice2);
			if (dice2 >= 2) {
				printf("%s�� �ſ� �ų��մϴ�.\n", name);
				printf("������� ���谡 ���� �������ϴ�.\n\n");
				affinity++;
				if (affinity > 4) {
					affinity = 4; // ģ�е��� 4 ���� �ö��� �ʵ��� ��.
				}
			}
			else {
				printf("���簡 �ǰ����մϴ�. %s�� �Ǹ��մϴ�.\n\n", name);
			}
		}
		Sleep(500);

		// CP ����Ʈ ����
		printf("%s�� ���(0~3): %d\n", name, mood);
		printf("������� ����(0~4): %d\n", affinity);
		int cp_gain = 0;
		if (mood > 0) {
			cp_gain = (mood - 1) + affinity;
		}
		else {
			cp_gain = affinity;
		}
		cp += cp_gain;
		printf("%s�� ��а� ģ�е��� ���� CP�� %d ����Ʈ ����Ǿ����ϴ�.\n\n", name, cp_gain);
		
		printf("���� ���� CP: %d ����Ʈ\n", cp);
		//���� ���
		int choice_item = -1;
		printf("�������� ������ �� �� �ֽ��ϴ�.\n");
		printf("� ������ �����ұ��?\n");
		printf("  0. �ƹ� �͵� ���� �ʴ´�.\n");
		if (mouse_toy) {
			printf("  1. �峭�� ��: 1 CP (ǰ��)\n");
		}
		else {
			printf("  1. �峭�� ��: 1 CP\n");
		}
		if (laser_toy) {
			printf("  2. ������ ������: 2 CP (ǰ��)\n");
		}
		else {
			printf("  2. ������ ������: 2 CP\n");
		}
		if (scratcher) {
			printf("  3. ��ũ��ó: 4 CP (ǰ��)\n");
		}
		else {
			printf("  3. ��ũ��ó: 4 CP\n");
		}
		if (cat_tower) {
			printf("  4. Ĺ Ÿ��: 6 CP (ǰ��)\n");
		}
		else {
			printf("  4. Ĺ Ÿ��: 6 CP\n");
		}
		printf(">> ");
		scanf_s("%d", &choice_item);
		while (choice_item < 0 || choice_item > 4) {
			printf("�߸��� �����Դϴ�. �ٽ� �Է����ּ���.\n");
			printf(">> ");
			scanf_s("%d", &choice_item);
		}

		//���� ���� ó��
		int item_check = 0;
		while (!item_check) {
			if (choice_item == 1) {
				if (mouse_toy) {
					printf("�峭�� ��� �̹� �����߽��ϴ�.\n\n");
					printf("�ٽ� �������ּ���.>> ");
					scanf_s("%d", &choice_item); // ���Է�
					while (choice_item < 0 || choice_item > 4) {
						printf("�߸��� �����Դϴ�. �ٽ� �Է����ּ���.\n");
						printf(">> ");
						scanf_s("%d", &choice_item);
					}
					continue; 
				}
				else if (cp >= 1) {
					printf("�峭�� �㸦 �����߽��ϴ�.\n");
					mouse_toy = 1; // �峭�� �� ����
					if (laser_toy) { //��ǰ ��ȣ ����
						mouse_state = 3;
					}
					else {
						mouse_state = 2;
					}
					cp -= 1;
					item_check = 1; // ���� �Ϸ�
					printf("���� ���� CP: %d ����Ʈ\n\n", cp);
				}
				else {
					printf("CP�� �����մϴ�. �峭�� �㸦 ������ �� �����ϴ�.\n\n");
					printf("�ٽ� �������ּ���.>> ");
					scanf_s("%d", &choice_item); // ���Է�
					while (choice_item < 0 || choice_item > 4) {
						printf("�߸��� �����Դϴ�. �ٽ� �Է����ּ���.\n");
						printf(">> ");
						scanf_s("%d", &choice_item);
					}
					continue;
				}
			}
			else if (choice_item == 2) {
				if (laser_toy) {
					printf("������ �����ʹ� �̹� �����߽��ϴ�.\n\n");
					printf("�ٽ� �������ּ���.>> ");
					scanf_s("%d", &choice_item); // ���Է�
					while (choice_item < 0 || choice_item > 4) {
						printf("�߸��� �����Դϴ�. �ٽ� �Է����ּ���.\n");
						printf(">> ");
						scanf_s("%d", &choice_item);
					}
					continue;
				}
				else if (cp >= 2) {
					printf("������ �����͸� �����߽��ϴ�.\n");
					laser_toy = 1; // �峭�� �� ����
					if (mouse_toy) { //��ǰ ��ȣ ����
						laser_state = 3;
					}
					else {
						laser_state = 2;
					}
					cp -= 2;
					item_check = 1; // ���� �Ϸ�
					printf("���� ���� CP: %d ����Ʈ\n\n", cp);
				}
				else {
					printf("CP�� �����մϴ�. ������ �����͸� ������ �� �����ϴ�.\n\n");
					printf("�ٽ� �������ּ���.>> ");
					scanf_s("%d", &choice_item); // ���Է�
					while (choice_item < 0 || choice_item > 4) {
						printf("�߸��� �����Դϴ�. �ٽ� �Է����ּ���.\n");
						printf(">> ");
						scanf_s("%d", &choice_item);
					}
					continue;
				}
			}
			else if (choice_item == 3) {
				if (scratcher) {
					printf("��ũ��ó�� �̹� �����߽��ϴ�.\n\n");
					printf("�ٽ� �������ּ���.>> ");
					scanf_s("%d", &choice_item); // ���Է�
					while (choice_item < 0 || choice_item > 4) {
						printf("�߸��� �����Դϴ�. �ٽ� �Է����ּ���.\n");
						printf(">> ");
						scanf_s("%d", &choice_item);
					}
					continue;
				}
				else if (cp >= 4) {
					printf("��ũ��ó�� �����߽��ϴ�.\n");
					scratcher = 1;
					for (int i = 0; i < ROOM_WIDTH - 1; i++) {
						int r1 = rand() % (ROOM_WIDTH - 2) + 1; // ���� ��ġ 
						if (r1 != HOME_POS && r1 != BOWL_POS && r1 != tower_pos) {
							scr_pos = r1;
							break;
						}
					}
					printf("��ũ��ó ��ġ�� �Ϸ��߽��ϴ�.\n");
					cp -= 4;
					item_check = 1; // ���� �Ϸ�
					printf("���� ���� CP: %d ����Ʈ\n\n", cp);
				}
				else {
					printf("CP�� �����մϴ�. ��ũ��ó�� ������ �� �����ϴ�.\n\n");
					printf("�ٽ� �������ּ���.>> ");
					scanf_s("%d", &choice_item); // ���Է�
					while (choice_item < 0 || choice_item > 4) {
						printf("�߸��� �����Դϴ�. �ٽ� �Է����ּ���.\n");
						printf(">> ");
						scanf_s("%d", &choice_item);
					}
					continue;
				}
			}
			else if (choice_item == 4) {
				if (cat_tower) {
					printf("Ĺ Ÿ���� �̹� �����߽��ϴ�.\n\n");
					printf("�ٽ� �������ּ���.>> ");
					scanf_s("%d", &choice_item); // ���Է�
					while (choice_item < 0 || choice_item > 4) {
						printf("�߸��� �����Դϴ�. �ٽ� �Է����ּ���.\n");
						printf(">> ");
						scanf_s("%d", &choice_item);
					}
					continue;
				}
				else if (cp >= 6) {
					printf("Ĺ Ÿ���� �����߽��ϴ�.\n");
					cat_tower = 1;
					for (int i = 0; i < ROOM_WIDTH - 1; i++) {
						int r2 = rand() % (ROOM_WIDTH - 2) + 1; // ���� ��ġ 
						if (r2 != HOME_POS && r2 != BOWL_POS && r2 != scr_pos) {
							tower_pos = r2;
							break;
						}
					}
					printf("Ĺ Ÿ�� ��ġ�� �Ϸ��߽��ϴ�.\n");
					cp -= 6;
					item_check = 1; // ���� �Ϸ�
					printf("���� ���� CP: %d ����Ʈ\n\n", cp);
				}
				else {
					printf("CP�� �����մϴ�. Ĺ Ÿ���� ������ �� �����ϴ�.\n\n");
					printf("�ٽ� �������ּ���.>> ");
					scanf_s("%d", &choice_item); // ���Է�
					while (choice_item < 0 || choice_item > 4) {
						printf("�߸��� �����Դϴ�. �ٽ� �Է����ּ���.\n");
						printf(">> ");
						scanf_s("%d", &choice_item);
					}
					continue;
				}
			}
			else if (choice_item == 0) {
				printf("�ƹ��͵� �������� �ʽ��ϴ�.\n\n");
				item_check = 1; //���� Ȯ��
			}
		}

		//��������Ʈ!!
		if (turn == 3) {
			char quest[100] = { 0 };
			printf("****���� ����Ʈ �߻�!!****\n");
			printf("���� ������� �̸��� �Է��ϼ���! >> ");
			while (1) {
				scanf_s("%s", quest, (unsigned)sizeof(quest));
				if (strcmp(quest, name) == 0) {
					printf("����Ʈ ����! %s�� �̸��� ��Ȯ�� �Է��߽��ϴ�.\n", name);
					break;
				}
				else {
					printf("����Ʈ ����! �ٽ� �õ��ϼ���. >> ");
				}
			}
		}
		turn++;
		Sleep(2000);
		system("cls");
	}
	return 0;
	// �ϼ�
}