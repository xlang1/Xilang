#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <conio.h >
#include <Windows.h>
#include <stdlib.h>
#include "menu.h"
#include "CalculateOperation.h"
int main() {
	while (1) {
		//char data[100];
		//char* t = (char*)malloc(sizeof(char)*100);
		double d;
		system("cls");
		PrintExplain();
		//printf("请输入正确的表达式：\n");
		//gets(data);
		d = CalculateSuffix();
		//t != NULL && 
		//if (t != NULL) {
		//	printf("后缀表达式是：%s\n", t);
		//	d = CalculateSuffix(t);
		//}
		if (d != 0.0) {
			printf("计算结果是：%.3f\n", d);
		}
		printf("按回车返回(输入q退出系统)...");
		if (getchar() == 'q')return 0;
	}
	return 0;
}