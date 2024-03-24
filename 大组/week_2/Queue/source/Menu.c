#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdlib.h>
#include "struct.h"
#include "Operation.h"

void PrintMenu() {
	printf("===*[Menu of LinkQueue]*===\n");
	printf("[1]--初始化队列\n");
	printf("[2]--元素入队\n");
	printf("[3]--元素出队\n");
	printf("[4]--输出队列\n");
	printf("[5]--获取队头元素\n");
	printf("[6]--检测队列是否为空\n");
	printf("[7]--清空队列\n");
	printf("[8]--获取队列长度\n");
	printf("[9]--销毁队列\n");
	printf("[10]--退出\n");
	printf("===========================\n");
}

void Operator() {
	int command = 0;
	char e[50];
	LinkQueue q = { -1,NULL,NULL };//初始化
	while (1) {
		system("cls");
		PrintMenu();
		printf("请输入操作指令(1-8)：");
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
			//排除如果没有初始化就选择的情况
			if (q.length < 0) {
				printf("尚未初始化！");
				Sleep(2000);
				break;
			}
			if (IsEmptyLinkQueue(&q) == 1)printf("队列为空！");
			else printf("队列不为空！");
			Sleep(2000);
			break;
		case 7:
			ClearLinkQueue(&q);
			printf("清空队列成功！");
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