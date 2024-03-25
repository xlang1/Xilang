#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <conio.h >
#include <Windows.h>

void PrintExplain() {
	printf(" ------------------------\n");
	printf("|       四则计算器       |\n");
	printf(" ------------------------\n");
	printf("|       +  加号          |\n");
	printf(" ------------------------\n");
	printf("|       -  减号          |\n");
	printf(" ------------------------\n");
	printf("|       *  乘号          |\n");
	printf(" ------------------------\n");
	printf("|       /  除号          |\n");
	printf(" ------------------------\n");
	printf("|       () 括号          |\n");
	printf(" ------------------------\n");
	printf("|      输入法：英文      |\n");
	printf(" ------------------------\n");
}



//void GoToxy(int x, int y)  //光标移动函数，X表示横坐标，Y表示纵坐标。
//{
//	COORD  coord;         //使用头文件自带的坐标结构
//	coord.X = x;            //这里将int类型值传给short,不过程序中涉及的坐标值均不会超过short范围
//	coord.Y = y;
//	HANDLE a = GetStdHandle(STD_OUTPUT_HANDLE);  //获得标准输出句柄
//	SetConsoleCursorPosition(a, coord);         //以标准输出的句柄为参数设置控制台光标坐标
//}