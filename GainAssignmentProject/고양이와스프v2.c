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
}