#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "struct.h"
#include "StackOperation.h"

/*
* ����һ������׺���ʽת��Ϊ��׺���ʽ����ջ����
*			1.������TransInfixToSuffix
*			2.���������ִ洢--data���飬������ջ--��ջ
*				1.��������
*				2.��������ȼ�����
*			3.����ֵ��data����--��׺���ʽ
* ��������Ѻ�׺���ʽ��������ó��������ջ����
*			1.
*/

//����һ��
//�����ַ����͵���׺���ʽ�������
char* TransInfixToSuffix(char* data) {
	char sufdata[100] = "";//�����׺���ʽ
	LinkStack* s = (LinkStack*)malloc(sizeof(LinkStack));
	InitLinkStack(s);//��ʼ����ջ
	int i, j;//����ʱ������
	//����data����
	for (i = 0, j = 0; data[i] != '\0'; i++) {
		if (data[i] == ' ')continue;//�ո������������
		//���������
		if ((data[i] >= '0' && data[i] <= '9')) {
			//�������ֱ�����ȥ��������ɣ��˴�Ϊ���ų�һ��ʼֱ������С��������⣬ֻ������������������С����Ų��ᱨ��
			while ((data[i] >= '0' && data[i] <= '9') || data[i] == '.') {
				sufdata[j++] = data[i];
				i++;
			}
			i--;//�������һ��ѭ�����滹���һ
			sufdata[j++] = ' ';//�ո�ֿ����ݴ���
		}
		//�������֣���������
		else {
			if (data[i] == '(') {
				PushStack(s, &data[i]);//������ֱ����ջ
			}
			else if (data[i] == ')') {
				if (data[i - 1] == '(') {
					//printf("��ʽ����");
					return NULL;
				}
				else if (i == 0)return NULL;
				while (IsEmptyStack(s) == 0) {    //�п�
					if (GetTopStack(s) == '(') {
						PopStack(s);//������������ʱ��Ҫ���������Ų�break
						break;
					}
					else {
						sufdata[j++] = *(char*)GetTopStack(s);//û�����������žͰ�ջ��Ԫ�ش����׺���ʽ���ٳ�ջ
						PopStack(s);
						sufdata[j++] = ' ';//�ո�ֿ����ݴ���
					}
				}
			}
			else if (data[i] == '*' || data[i] == '/') {
				PushStack(s, &data[i]);//�����˺źͳ��ţ����ȼ��ߣ�ֱ����ջ
			}
			else if (data[i] == '+' || data[i] == '-') {
				while (IsEmptyStack(s) == 0 && *(char*)GetTopStack(s) != '(') {  //�п��Ҳ�����������
					sufdata[j++] = *((char*)GetTopStack(s));  //���ȼ�С�ڵ���ջ�������ʱ�������׺���ʽ���ٵ���
					PopStack(s);
					sufdata[j++] = ' ';
				}
				PushStack(s, &data[i]);//�������ջ
			}
			else {
				//printf("��ʽ����");
				return NULL;
			}
		}
	}
	//������������ջ��Ԫ�ش����׺���ʽ�У��ٳ�ջ
	while (IsEmptyStack(s) == 0) {
		sufdata[j++] = *((char*)GetTopStack(s));
		PopStack(s);
		sufdata[j++] = ' ';
	}
	return sufdata;
}


//�����
double CalculateSuffix() {
	LinkStack* s = (LinkStack*)malloc(sizeof(LinkStack));
	InitLinkStack(s);//��ʼ����ջ
	char sufdata[1000];
	printf("��������ȷ�ı��ʽ��\n");
	gets(sufdata);
	char* c = TransInfixToSuffix(sufdata);
	if (c == NULL || strlen(sufdata) == 0) {
		printf("��ʽ����");
		return 0.0;
	}
	else {
		strcpy(sufdata, c);
	}
	//sufdata = TransInfixToSuffix(sufdata);

	int i;
	//������׺���ʽ����
	for (i = 0; i < strlen(sufdata); i++) {
		if (sufdata[i] == ' ')continue;
		if ((sufdata[i] >= '0' && sufdata[i] <= '9') || sufdata[i] == '.') {
			//s = (LinkStack*)malloc(sizeof(LinkStack));
			//�ַ���ת˫���ȸ���������һ������ָ��Ҫ���͵��Կ��ַ���β���ֽ��ַ������ڶ�������ָ�����ֺ�ĵ�һ���ַ�
			//double* ans = (double*)malloc(sizeof(double));
			//char* end = (char*)malloc(sizeof(char));
			//*ans = atof(&sufdata[i]);
			double* a = (double*)malloc(sizeof(double));
			*a = 0;
			int head = i, dot = 0, tail;
			for (tail = i; sufdata[tail] != ' '; tail++) {//�������β��λ������
				if (sufdata[tail] == '.')dot = tail;//С����λ������
			}
			if (dot != 0) dot = tail - dot;//��ΪС��λ��+1
			for (; tail - head >= 1; head++) {//ͷ��ǰ��ʹ��������Ӧָ����С
				if (sufdata[head] != '.') {
					//û����С����ǰ
					double num = sufdata[head] - '0';
					*a += num * pow(10, tail - head - dot - 1);//β��ͷ����λ������С���㣬��ȥdotС��λ��Ϊ����λ����һλ
				}
				else dot--;//����С�����ų���һλ����ռ����
			}
			i = tail;
			//while (sufdata[i] != ' ')i++;//�ҵ�����
			//������ջ
			PushStack(s, a);
		}
		else {
			if (IsEmptyStack(s) == 1) {
				printf("��ʽ����");
				return 0.0;
			}
			//�������ſ�ʼ����
			double former = *(double*)(GetTopStack(s));//�ȳ�ջ��
			PopStack(s);
			double latter = *(double*)(GetTopStack(s));//���ջ��
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
					printf("��ʽ����");
					return 0.0;
				}
				*shang = latter / former;
				PushStack(s, shang);
				break;
			default:
				printf("��ʽ����");
				return 0.0;
			}
			i++;
		}
	}
	return  *(double*)GetTopStack(s);
}