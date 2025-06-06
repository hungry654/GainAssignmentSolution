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
	int cat_pos = 2, prev_pos = 2; //����� �ʱ� ��ġ, ����� ���� ��ġ
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
		else if(mood == 0) {
			printf("%s�� ����� �ʹ� ������ �� �̻� ������ �� �����ϴ�.\n\n", name);
			mood = 0; // ����� 0 ���Ϸ� �������� �ʵ���
		}

		//����� �ൿ
		printf("%s�� �ൿ�� �մϴ�.\n", name);
		prev_pos = cat_pos; // ���� ��ġ ����
		if (mood == 0) {
			printf("����� �ſ� ���� %s��(��) ������ ���մϴ�.\n\n", name);
			cat_pos = HOME_POS; // ������ �̵�
		}
		else if (mood == 1) {
			if (scratcher && cat_tower) {
				int dist_scr = abs(cat_pos - scr_pos); 
				int dist_tower = abs(cat_pos - tower_pos);
				if (dist_scr <= dist_tower) {
					printf("%s�� ��ũ��ó�� ���ϴ�.\n\n", name);
					cat_pos = scr_pos; // ��ũ��ó�� �̵�
				}
				else {
					printf("%s�� ĹŸ���� ���ϴ�.\n\n", name);
					cat_pos = tower_pos; // ĹŸ���� �̵�
				}
			}
			else if (scratcher) {
				printf("%s�� ��ũ��ó�� ���ϴ�.\n\n", name);
				cat_pos = scr_pos; // ��ũ��ó�� �̵�
			}
			else if (cat_tower) {
				printf("%s�� ĹŸ���� ���ϴ�.\n\n", name);
				cat_pos = tower_pos; // ĹŸ���� �̵�
			}
			else {
				printf("%s��(��) �� �Ÿ��� ��� ����� ���� �ʽ��ϴ�.\n\n", name);
			}
		}
		else if (mood == 2) {
			printf("%s��(��) �Ļ��� �����ϴ�.\n\n", name);
			cat_pos = cat_pos; //���ڸ� ����
		}
		else if (mood == 3) {
			printf("%s�� ������ �θ��� ������ ���鷯 ���ϴ�.\n\n", name);
			cat_pos = BOWL_POS; 
		}

		// ����� ��ġ�� ���� �ൿ
		if (cat_pos == HOME_POS && prev_pos == HOME_POS) {
			if (mood < 3) {
				printf("%s�� ����� �������ϴ�: %d -> %d\n\n", name, mood, mood + 1);
				mood++;
			}
			else if (mood == 3) {
				printf("%s�� ����� �ְ����Դϴ�.\n\n", name);
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
			else {
				printf("%s��(��) �ູ���մϴ�.\n\n", name);
			}
		}
		else if (cat_pos == tower_pos) {
			printf("%s��(��) ĹŸ���� �پ�ٴմϴ�..\n", name);
			if (mood < 3) {
				printf("%s�� ����� ���� �������ϴ�: %d -> %d\n\n", name, mood, mood + 2);
				mood += 2;
			}
			else {
				printf("%s��(��) �ſ� ����� ���� �̸����� �پ�ٴմϴ�.\n\n", name);
			}
		}
		Sleep(3000);
		// ��ȣ�ۿ� (����̿� ����)
		srand(time(NULL));
		int choice = -1; 
		    //��ȣ�ۿ� ������ �Է�
		while (choice < 0 || choice > 1 + mouse_toy + laser_toy) {
			printf("���ȣ�ۿ����Ͻðڽ��ϱ�?\n   0.�ƹ��͵��������� 1.�ܾ��ֱ�\n");
			if (mouse_toy) {
				printf("   %d. �峭�� ��� ����ֱ�\n", mouse_state);
			}
			if (laser_toy) {
				printf("   %d. ������ �����ͷ� ����ֱ�\n", laser_state);
			}
			printf(">> ");
			scanf_s("%d", &choice);
			if (choice < 0 || choice > 1 + mouse_toy + laser_toy) {
				printf("�߸��� �����Դϴ�. �ٽ� �������ּ���.\n");
			}
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
			printf("%s�� ����� ���� �������ϴ�: %d -> %d\n", name, mood, mood + 1);
			mood++;
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
			printf("%s�� ����� ���� �������ϴ�: %d -> %d\n", name, mood, mood + 2);
			mood += 2;
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
	}
}