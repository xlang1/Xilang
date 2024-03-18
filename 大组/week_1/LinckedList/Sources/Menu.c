#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdlib.h>
#include "Menu.h"
#include "EssentialWork.h"
#include "struct.h"
#include "ExtraWork.h"


void DisplayMenu(int n)//Ŀ¼��ʾ
{
	if (n == 13) {//������
		for (int i = 0; i < n; i++) {
			printf("%s\n", singleLinckedListMenu[i]);
		}
	}
	if (n == 9) {//˫����
		for (int i = 0; i < n; i++) {
			printf("%s\n", doublieLickedListMenu[i]);
		}
	}
	if (n == 6) {
		for (int i = 0; i < n; i++) {
			printf("%s\n", insertMenu[i]);
		}
	}
	if (n == 5) {
		for (int i = 0; i < n; i++) {
			printf("%s\n", menu[i]);
		}
	}
}

void OperateSingleList() {  //���������
	singleList head = NULL;
	int command;
	for (;;) {
		system("cls");
		DisplayMenu(13);
		printf("������ָ�1-11����\n");
		scanf("%d", &command);
		getchar();
		switch (command) {
		case 1:
			if (head == NULL)head = CreateSingleList();//����������
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
			head = DestroySingleList(head);
			break;
		case 7:
			head = ReverseSingleList(head);
			break;
		case 8:
			JudgeLoop(head);
			break;
		case 9:
			head = ParitySwap(head);
			break;
		case 10:
			SearchMidpoint(head);
			break;
		case 11:
			system("cls");
			printf("Hava a nice day!\n");
			return 0;
		default:
			printf("����ָ���������������룡");
		}
	}
}

void OperateDoubleList() {  //˫�������
	doubleList head = NULL;
	int command;
	for (;;) {
		system("cls");
		DisplayMenu(9);
		printf("������ָ�1-7����\n");
		scanf("%d", &command);
		getchar();
		switch (command) {
		case 1:
			if (head == NULL)head = CreateDoubleList();//����������
			else {
				printf("�Ѵ�������");
				Sleep(2000);
			}
			break;
		case 2:
			PrintDoubleList(head);          //���������ӡ������
			printf("���س����أ�");
			getchar();
			break;
		case 3:
			system("cls");
			head = AddSingleData(head);     //��������
			break;
		case 4:
			SeekDoubleData(head);           //����
			printf("���س����أ�");
			getchar();
			break;
		case 5:
			head = DeleteDoubleNode(head);    //ɾ��
			break;
		case 6:
			DestroyDouleList(head);      //����
			break;
		case 7:
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
			OperateDoubleList();
			break;
		case 3:
			system("cls");
			printf("Hava a nice day!\n");
			return 0;
		}
	}

}

