#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "DataOperation.h"
//���ɲ�ͬ��������              n������
void CreateNumbers(int* data, int n)
{
	//ѭ��n�β��������
	srand(time(NULL));
	for (int i = 0; i < n; i++) {
		data[i] = rand();//���÷�Χ
	}
}

//�����ļ�            data����   n������      �ļ���
void SaveDataInFile(int* data, int n, char* filename)
{
	FILE* fp;
	if ((fp = fopen(filename, "w")) == NULL) {
		printf("Error��");
		return;
	}
	printf("��ʼ��������������ļ�......\n");
	for (int i = 0; i < n; i++) {
		fprintf(fp, "%d ", data[i]);
	}
	fclose(fp);
}

//��ȡ�ļ�                 data����   n������   �ļ���
int ReadDataFromFile(int* data, char* filename)  //C/c���ļ���ȡ
{
	FILE* fp;
	int i = 0;
	if ((fp = fopen(filename, "r")) == NULL) {
		printf("Error��", filename);
		return;
	}
	//for (i = 0; i < n; i++) {
	//	fscanf(fp, "%d ", &data[i]);
	//}
	while ((fscanf(fp, "%d", &data[i])) != EOF)i++;
	fclose(fp);
	return i;
}