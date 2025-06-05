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
		printf("%d��(��) ���Խ��ϴ�.\n", dice);
		if (mood > 0) {
			if (dice <= 6 - affinity) {
				printf("�ƹ� ���� ���� ����� �������ϴ�.\n");
				printf("%s�� ����� �������ϴ�: %d -> %d\n\n", name, mood, mood - 1);
				mood--;
			}
		}
		else {
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
				printf("%s��(��) �� �Ÿ��� ��� ����� �ſ� �������ϴ�.\n", name);
				mood--;
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
				mood = mood + 2;
			}
			else {
				printf("%s��(��) �ſ� ����� ���� �̸����� �پ�ٴմϴ�.\n\n", name);
			}
		}
		Sleep(3000);
		// ��ȣ�ۿ� (����̿� ����)
	}
}