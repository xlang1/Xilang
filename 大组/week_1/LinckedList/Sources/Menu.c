#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdlib.h>
#include "Menu.h"
#include "EssentialWork.h"
#include "struct.h"
#include "ExtraWork.h"


void DisplayMenu(int n)//目录显示
{
	if (n == 13) {//单链表
		for (int i = 0; i < n; i++) {
			printf("%s\n", singleLinckedListMenu[i]);
		}
	}
	if (n == 9) {//双链表
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

void OperateSingleList() {  //单链表操作
	singleList head = NULL;
	int command;
	for (;;) {
		system("cls");
		DisplayMenu(13);
		printf("请输入指令（1-11）：\n");
		scanf("%d", &command);
		getchar();
		switch (command) {
		case 1:
			if (head == NULL)head = CreateSingleList();//创建空链表
			else {
				printf("已创建链表！");
				Sleep(2000);
			}
			break;
		case 2:
			PrintSingleList(head);          //遍历链表打印出数据
			printf("（回车返回）");
			getchar();
			break;
		case 3:
			system("cls");
			head = AddSingleData(head);     //插入数据
			break;
		case 4:
			SeekSingleData(head);
			printf("（回车返回）");
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
			printf("输入指令有误，请重新输入！");
		}
	}
}

void OperateDoubleList() {  //双链表操作
	doubleList head = NULL;
	int command;
	for (;;) {
		system("cls");
		DisplayMenu(9);
		printf("请输入指令（1-7）：\n");
		scanf("%d", &command);
		getchar();
		switch (command) {
		case 1:
			if (head == NULL)head = CreateDoubleList();//创建空链表
			else {
				printf("已创建链表！");
				Sleep(2000);
			}
			break;
		case 2:
			PrintDoubleList(head);          //遍历链表打印出数据
			printf("（回车返回）");
			getchar();
			break;
		case 3:
			system("cls");
			head = AddSingleData(head);     //插入数据
			break;
		case 4:
			SeekDoubleData(head);           //查找
			printf("（回车返回）");
			getchar();
			break;
		case 5:
			head = DeleteDoubleNode(head);    //删除
			break;
		case 6:
			DestroyDouleList(head);      //销毁
			break;
		case 7:
			return 0;
		default:
			printf("输入指令有误，请重新输入！");
		}
	}
}

void Operator() {//总操作
	int command;
	while (1) {
		system("cls");
		DisplayMenu(5);
		printf("请输入指令（1-3）：\n");
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

