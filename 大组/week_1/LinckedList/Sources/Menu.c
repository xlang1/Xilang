#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdlib.h>
#include "Menu.h"
#include "EssentialWork.h"
#include "struct.h"

void DisplayMenu(int n)//Ŀ¼��ʾ
{
	if (n == 13) {//������
		for (int i = 0; i < n; i++) {
			printf("%s\n", singleLinckedListMenu[i]);
		}
	}
	if (n == 7) {//˫����
		for (int i = 0; i < n; i++) {
			printf("%s\n", doublieLickedListMenu[i]);
		}
	}
	if (n == 6) {
		for (int i = 0; i < n; i++) {
			printf("%s\n", menu[i]);
		}
	}
	if (n == 5) {
		for (int i = 0; i < n; i++) {
			printf("%s\n", insertMenu[i]);
		}
	}
}

void OperateSingleList() {  //���������
	singleList head = NULL;
	int command;
	for (;;) {
		system("cls");
		displayMenu(13);
		printf("������ָ�1-11����\n");
		scanf("%d", &command);
		getchar();
		switch (command) {
		case 1:
			if (head == NULL)head = CreateEmptyList();//����������
			else {
				printf("�Ѵ�������");
				Sleep(2000);
			}
			break;
		case 2:
			PrintSingleList(head);          //���������ӡ������
			printf("���س����أ�");
			getchar();
			break;
		case 3:
			system("cls");
			head = AddSingleData(head);     //��������
			break;
		case 4:
			SeekSingleData(head);
			printf("���س����أ�");
			getchar();
			break;
		case 5:
			head = DeleteSingleNode(head);
			break;
		case 6:
			DestroySingleList(head);
			break;
		case 7:
		case 8:
			judgeLoop(head);
			printf("���س����أ�");
			getchar();
			break;
		case 9:
			paritySwap(head);
			break;
		case 10:
		case 11:
			system("cls");
			printf("Hava a nice day!\n");
			return 0;
		default:
			printf("����ָ���������������룡");
		}
	}
}

void Operator() {//�ܲ���
	int command;
	while (1) {
		system("cls");
		DisplayMenu(5);
		printf("������ָ�1-3����\n");
		scanf("%d", &command);
		getchar();
		switch (command) {
		case 1:
			OperateSingleList();
			break;
		case 2:

		case 3:
			return;
		}
	}

}

