#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdlib.h>
#include "Menu.h"//目录
#include "struct.h"//结构体
#include "EssentialWork.h"//必做任务：增删改查
#include "ExtraWork.h" // 选做任务

int main() {
	DisplayMenu(13);
	Operator();


	return 0;
}