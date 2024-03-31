#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "DataOperation.h"
//生成不同量的数据              n数据量
void CreateNumbers(int* data, int n)
{
	//循环n次产生随机数
	srand(time(NULL));
	for (int i = 0; i < n; i++) {
		data[i] = rand();//设置范围
	}
}

//存入文件            data数据   n数据量      文件名
void SaveDataInFile(int* data, int n, char* filename)
{
	FILE* fp;
	if ((fp = fopen(filename, "w")) == NULL) {
		printf("Error！");
		return;
	}
	printf("开始生成随机数存入文件......\n");
	for (int i = 0; i < n; i++) {
		fprintf(fp, "%d ", data[i]);
	}
	fclose(fp);
}

//读取文件                 data数据   n数据量   文件名
int ReadDataFromFile(int* data, char* filename)  //C/c从文件读取
{
	FILE* fp;
	int i = 0;
	if ((fp = fopen(filename, "r")) == NULL) {
		printf("Error！", filename);
		return;
	}
	//for (i = 0; i < n; i++) {
	//	fscanf(fp, "%d ", &data[i]);
	//}
	while ((fscanf(fp, "%d", &data[i])) != EOF)i++;
	fclose(fp);
	return i;
}