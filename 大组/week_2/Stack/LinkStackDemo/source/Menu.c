#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdlib.h>
#include "struct.h"
#include "Operation.h"


void PrintMenu() {
	printf("===*[Menu of LinkStack]*===\n");
	printf("[1]--��ʼ����ջ\n");
	printf("[2]--Ԫ����ջ\n");
	printf("[3]--Ԫ�س�ջ\n");
	printf("[4]--�����ջ\n");
	printf("[5]--��ȡջ��\n");
	printf("[6]--�����ջ�Ƿ�Ϊ��\n");
	printf("[7]--�����ջ\n");
	printf("[8]--��ȡ��ջ����\n");
	printf("[9]--������ջ\n");
	printf("[10]--�˳�\n");
	printf("===========================\n");
}

void Operator() {
	int command = 0;
	char e[50];
	LinkStack s = { -1,NULL };
	while (1) {
		system("cls");
		PrintMenu();
		printf("���������ָ��(1-8)��");
		scanf("%d", &command);
		while (getchar() != '\n');
		switch (command) {
		case 1:
			InitLinkStack(&s);
			printf("��ʼ���ɹ�!");
			Sleep(2000);
			break;
		case 2:
			PushStack(&s);
			break;
		case 3:
			PopStack(&s);
			break;
		case 4:
			PrintLinkStack(s);
			break;
		case 5:
			printf("The top is %s", GetTopStack(s, e));
			Sleep(2000);
			break;
		case 6:
			//�ų����û�г�ʼ����ѡ������
			if (s.count < 0) { 
				printf("��δ��ʼ����"); 
				Sleep(2000);
				break;
			}
			if (IsEmptyStack(s) == 1)printf("��ջΪ�գ�");
			else printf("��ջ��Ϊ�գ�");
			Sleep(2000);
			break;
		case 7:
			ClearStack(&s);
			printf("��ճɹ���");
			Sleep(2000);
			break;
		case 8:
			GetLength(s);
			break;
		case 9:
			DestroyLinkStack(&s);
			break;
		case 10:
			system("cls");
			printf("Have a nice day!\n");
			return;
		default:
			break;
		}
	}

}