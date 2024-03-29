#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "struct.h"
#include "StackOperation.h"

/*
* 步骤一：把中缀表达式转化为后缀表达式，入栈操作
*			1.方法名TransInfixToSuffix
*			2.参数：数字存储--data数组，符号入栈--链栈
*				1.括号问题
*				2.运算符优先级问题
*			3.返回值：data数组--后缀表达式
* 步骤二：把后缀表达式进行运算得出结果，出栈运算
*			1.
*/

//步骤一：
//会有字符串型的中缀表达式输入进来
char* TransInfixToSuffix(char* data) {
	char sufdata[100] = "";//保存后缀表达式
	LinkStack* s = (LinkStack*)malloc(sizeof(LinkStack));
	InitLinkStack(s);//初始化链栈
	int i, j;//遍历时的索引
	//遍历data数据
	for (i = 0, j = 0; data[i] != '\0'; i++) {
		if (data[i] == ' ')continue;//空格继续，不报错
		//数字情况：
		if ((data[i] >= '0' && data[i] <= '9')) {
			//遇到数字遍历下去到输入完成，此处为了排除一开始直接输入小数点的问题，只有输入了数字再输入小数点才不会报错
			while ((data[i] >= '0' && data[i] <= '9') || data[i] == '.') {
				sufdata[j++] = data[i];
				i++;
			}
			i--;//最后多加了一，循环里面还会加一
			sufdata[j++] = ' ';//空格分开数据处理
		}
		//不是数字，括号问题
		else {
			if (data[i] == '(') {
				PushStack(s, &data[i]);//左括号直接入栈
			}
			else if (data[i] == ')') {
				if (data[i - 1] == '(') {
					//printf("算式错误！");
					return NULL;
				}
				else if (i == 0)return NULL;
				while (IsEmptyStack(s) == 0) {    //判空
					if (GetTopStack(s) == '(') {
						PopStack(s);//输入了右括号时，要遇到左括号才break
						break;
					}
					else {
						sufdata[j++] = *(char*)GetTopStack(s);//没有遇到左括号就把栈中元素存入后缀表达式，再出栈
						PopStack(s);
						sufdata[j++] = ' ';//空格分开数据处理
					}
				}
			}
			else if (data[i] == '*' || data[i] == '/') {
				PushStack(s, &data[i]);//遇到乘号和除号（优先级高）直接入栈
			}
			else if (data[i] == '+' || data[i] == '-') {
				while (IsEmptyStack(s) == 0 && *(char*)GetTopStack(s) != '(') {  //判空且不遇到左括号
					sufdata[j++] = *((char*)GetTopStack(s));  //优先级小于等于栈顶运算符时，存入后缀表达式，再弹出
					PopStack(s);
					sufdata[j++] = ' ';
				}
				PushStack(s, &data[i]);//最后将其入栈
			}
			else {
				//printf("算式错误！");
				return NULL;
			}
		}
	}
	//遍历结束，将栈中元素存入后缀表达式中，再出栈
	while (IsEmptyStack(s) == 0) {
		sufdata[j++] = *((char*)GetTopStack(s));
		PopStack(s);
		sufdata[j++] = ' ';
	}
	return sufdata;
}


//步骤二
double CalculateSuffix() {
	LinkStack* s = (LinkStack*)malloc(sizeof(LinkStack));
	InitLinkStack(s);//初始化链栈
	char sufdata[1000];
	printf("请输入正确的表达式：\n");
	gets(sufdata);
	char* c = TransInfixToSuffix(sufdata);
	if (c == NULL || strlen(sufdata) == 0) {
		printf("算式错误！");
		return 0.0;
	}
	else {
		strcpy(sufdata, c);
	}
	//sufdata = TransInfixToSuffix(sufdata);

	int i;
	//遍历后缀表达式数组
	for (i = 0; i < strlen(sufdata); i++) {
		if (sufdata[i] == ' ')continue;
		if ((sufdata[i] >= '0' && sufdata[i] <= '9') || sufdata[i] == '.') {
			//s = (LinkStack*)malloc(sizeof(LinkStack));
			//字符串转双精度浮点数，第一个参数指向要解释的以空字符结尾的字节字符串，第二个参数指向数字后的第一个字符
			//double* ans = (double*)malloc(sizeof(double));
			//char* end = (char*)malloc(sizeof(char));
			//*ans = atof(&sufdata[i]);
			double* a = (double*)malloc(sizeof(double));
			*a = 0;
			int head = i, dot = 0, tail;
			for (tail = i; sufdata[tail] != ' '; tail++) {//遍历获得尾部位置索引
				if (sufdata[tail] == '.')dot = tail;//小数点位置索引
			}
			if (dot != 0) dot = tail - dot;//此为小数位数+1
			for (; tail - head >= 1; head++) {//头往前移使下面计算对应指数减小
				if (sufdata[head] != '.') {
					//没遇到小数点前
					double num = sufdata[head] - '0';
					*a += num * pow(10, tail - head - dot - 1);//尾减头是总位数包括小数点，减去dot小数位数为整数位数多一位
				}
				else dot--;//遇到小数点排除这一位置所占索引
			}
			i = tail;
			//while (sufdata[i] != ' ')i++;//找到索引
			//存入链栈
			PushStack(s, a);
		}
		else {
			if (IsEmptyStack(s) == 1) {
				printf("算式有误！");
				return 0.0;
			}
			//遇到符号开始运算
			double former = *(double*)(GetTopStack(s));//先出栈的
			PopStack(s);
			double latter = *(double*)(GetTopStack(s));//后出栈的
			PopStack(s);
			char op = sufdata[i];
			double* sum, * cha, * ji, * shang;
			switch (op) {
			case '+':
				sum = (double*)malloc(sizeof(double));
				*sum = former + latter;
				PushStack(s, sum);
				break;
			case '-':
				cha = (double*)malloc(sizeof(double));
				*cha = latter - former;
				PushStack(s, cha);
				break;
			case '*':
				ji = (double*)malloc(sizeof(double));
				*ji = latter * former;
				PushStack(s, ji);
				break;
			case '/':
				shang = (double*)malloc(sizeof(double));
				if (former == 0.0) {
					printf("算式有误！");
					return 0.0;
				}
				*shang = latter / former;
				PushStack(s, shang);
				break;
			default:
				printf("算式有误！");
				return 0.0;
			}
			i++;
		}
	}
	return  *(double*)GetTopStack(s);
}