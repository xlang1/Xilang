#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdlib.h>
#include "struct.h"
#include "Operation.h"

void PrintMenu() {
	printf("===*[Menu of LinkQueue]*===\n");
	printf("[1]--��ʼ������\n");
	printf("[2]--Ԫ�����\n");
	printf("[3]--Ԫ�س���\n");
	printf("[4]--�������\n");
	printf("[5]--��ȡ��ͷԪ��\n");
	printf("[6]--�������Ƿ�Ϊ��\n");
	printf("[7]--��ն���\n");
	printf("[8]--��ȡ���г���\n");
	printf("[9]--���ٶ���\n");
	printf("[10]--�˳�\n");
	printf("===========================\n");
}

void Operator() {
	int command = 0;
	char e[50];
	LinkQueue q = { -1,NULL,NULL };//��ʼ��
	while (1) {
		system("cls");
		PrintMenu();
		printf("���������ָ��(1-8)��");
		scanf("%d", &command);
		while (getchar() != '\n');
		switch (command) {
		case 1:
			InitQueue(&q);
			break;
		case 2:
			EnLinkQueue(&q);
			break;
		case 3:
			DeLLinkQueue(&q);
			break;
		case 4:
			PrintLinkStack(q);
			break;
		case 5:
			GetHeadQueue(&q);
			break;
		case 6:
			//�ų����û�г�ʼ����ѡ������
			if (q.length < 0) {
				printf("��δ��ʼ����");
				Sleep(2000);
				break;
			}
			if (IsEmptyLinkQueue(&q) == 1)printf("����Ϊ�գ�");
			else printf("���в�Ϊ�գ�");
			Sleep(2000);
			break;
		case 7:
			ClearLinkQueue(&q);
			printf("��ն��гɹ���");
			Sleep(2000);
			break;
		case 8:
			LengthLinkQueue(&q);
			break;
		case 9:
			DestoryLinkQueue(&q);
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