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
		//printf("��������ȷ�ı��ʽ��\n");
		//gets(data);
		d = CalculateSuffix();
		//t != NULL && 
		//if (t != NULL) {
		//	printf("��׺���ʽ�ǣ�%s\n", t);
		//	d = CalculateSuffix(t);
		//}
		if (d != 0.0) {
			printf("�������ǣ�%.3f\n", d);
		}
		printf("���س�����(����q�˳�ϵͳ)...");
		if (getchar() == 'q')return 0;
	}
	return 0;
}