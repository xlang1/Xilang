#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdlib.h>
#include "struct.h"
#include "Operation.h"


void PrintMenu() {
	printf("===*[Menu of LinkStack]*===\n");
	printf("[1]--初始化链栈\n");
	printf("[2]--元素入栈\n");
	printf("[3]--元素出栈\n");
	printf("[4]--输出链栈\n");
	printf("[5]--获取栈顶\n");
	printf("[6]--检测链栈是否为空\n");
	printf("[7]--清空链栈\n");
	printf("[8]--获取链栈长度\n");
	printf("[9]--销毁链栈\n");
	printf("[10]--退出\n");
	printf("===========================\n");
}

void Operator() {
	int command = 0;
	char e[50];
	LinkStack s = { -1,NULL };
	while (1) {
		system("cls");
		PrintMenu();
		printf("请输入操作指令(1-8)：");
		scanf("%d", &command);
		while (getchar() != '\n');
		switch (command) {
		case 1:
			InitLinkStack(&s);
			printf("初始化成功!");
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
			//排除如果没有初始化就选择的情况
			if (s.count < 0) { 
				printf("尚未初始化！"); 
				Sleep(2000);
				break;
			}
			if (IsEmptyStack(s) == 1)printf("链栈为空！");
			else printf("链栈不为空！");
			Sleep(2000);
			break;
		case 7:
			ClearStack(&s);
			printf("清空成功！");
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