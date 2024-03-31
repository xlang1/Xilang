#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<Windows.h>

#include "DataOperation.h"
#include "SortOperation.h"
#include "menu.h"
int main()
{
	int command;//指令
	int min, max, n;
	int* data = NULL;
	int* temdata = NULL;
	char filename[50];
	int diff1 = 0, diff2 = 0, diff3 = 0, diff4 = 0, diff5 = 0;//分别记录小数据量多次排序各方法的用时
	clock_t start;
	clock_t diff;
	while (1) {
		system("cls");
		OperationMenu();
		printf("请输入操作指令(1-11)：");
		scanf("%d", &command);
		while (getchar() != '\n');
		int k = 0;
		switch (command) {
		case 1://插入
			printf("请输入数据量大小：");
			scanf("%d", &n);
			data = (int*)malloc(sizeof(int) * n);
			while (getchar() != '\n');
			CreateNumbers(data, n);//创建数据
			printf("正在计算用时......\n");
			start = clock();
			InsertSort(data, n);
			diff = clock() - start;
			printf("用时为：%d ms\n", diff);
			printf("回车返回...");
			while (getchar() != '\n');
			free(data);
			break;
		case 2://归并
			printf("请输入数据量大小：");
			scanf("%d", &n);
			data = (int*)malloc(sizeof(int) * n);
			while (getchar() != '\n');
			CreateNumbers(data, n);
			printf("正在计算用时......\n");
			start = clock();
			MergeSort(data, 0, n - 1);
			diff = clock() - start;
			printf("用时为：%d ms\n", diff);
			printf("回车返回...");
			while (getchar() != '\n');
			free(data);
			break;
		case 3://快排
			printf("请输入数据量大小：");
			scanf("%d", &n);
			data = (int*)malloc(sizeof(int) * n);
			while (getchar() != '\n');
			CreateNumbers(data, n);//创建数据
			printf("正在计算用时......\n");
			start = clock();
			QuickSort(data, 0, n - 1);
			diff = clock() - start;
			printf("用时为：%d ms\n", diff);
			printf("回车返回...");
			while (getchar() != '\n');
			free(data);
			break;
		case 4://计数
			printf("请输入数据量大小：");
			scanf("%d", &n);
			data = (int*)malloc(sizeof(int) * n);
			while (getchar() != '\n');
			CreateNumbers(data, n);//创建数据
			printf("正在计算用时......\n");
			start = clock();
			CountSort(data, n);
			diff = clock() - start;
			printf("用时为：%d ms\n", diff);
			printf("回车返回...");
			while (getchar() != '\n');
			free(data);
			break;
		case 5://基数
			printf("请输入数据量大小：");
			scanf("%d", &n);
			data = (int*)malloc(sizeof(int) * n);
			while (getchar() != '\n');
			CreateNumbers(data, n);//创建数据
			printf("正在计算用时......\n");
			start = clock();
			RadixSort(data, n);
			diff = clock() - start;
			printf("用时为：%d ms\n", diff);
			printf("回车返回...");
			while (getchar() != '\n');;
			free(data);
			break;
		case 6://小数据多次
			printf("正在计算用时（同组数据）......\n");
			while (k != 100000) {
				data = (int*)malloc(sizeof(int) * 100);
				temdata = (int*)malloc(sizeof(int) * 100);
				CreateNumbers(data, 100);//创建数据
				for (int j = 0; j < 100; j++)temdata[j] = data[j];
				start = clock();
				InsertSort(data, 100);
				diff1 += clock() - start;
				//
				for (int j = 0; j < 100; j++)data[j] = temdata[j];
				start = clock();
				MergeSort(data, 0, 99);
				diff2 += clock() - start;
				//
				for (int j = 0; j < 100; j++)data[j] = temdata[j];
				start = clock();
				QuickSort(data, 0, 99);
				diff3 += clock() - start;

				//
				for (int j = 0; j < 100; j++)data[j] = temdata[j];
				start = clock();
				CountSort(data, 100);
				diff4 += clock() - start;

				//
				for (int j = 0; j < 100; j++)data[j] = temdata[j];
				start = clock();
				RadixSort(data, 100);
				diff5 += clock() - start;
				k++;
				free(data);
				free(temdata);
			}
			printf("插入排序用时为：%d ms\n", diff1);
			printf("归并排序用时为：%d ms\n", diff2);
			printf("快速排序用时为：%d ms\n", diff3);
			printf("计数排序用时为：%d ms\n", diff4);
			printf("基数排序用时为：%d ms\n", diff5);
			printf("回车返回...");
			while (getchar() != '\n');
			diff1 = diff2 = diff3 = diff4 = diff5 = 0;
			break;
		case 7:
			printf("请输入数据量大小：");
			scanf("%d", &n);
			while (getchar() != '\n');
			data = (int*)malloc(sizeof(int) * n);
			temdata = (int*)malloc(sizeof(int) * n);//临时存储空间
			CreateNumbers(data, n);//创建数据
			for (int i = 0; i < n; i++)temdata[i] = data[i];
			printf("正在计算用时（同组数据）......\n");
			//
			start = clock();
			InsertSort(data, n);
			diff1 = clock() - start;
			printf("插入排序用时为：%d ms\n", diff1);
			//
			for (int i = 0; i < n; i++)data[i] = temdata[i];
			start = clock();
			MergeSort(data, 0, n - 1);
			diff2 = clock() - start;
			printf("归并排序用时为：%d ms\n", diff2);
			//
			for (int i = 0; i < n; i++)data[i] = temdata[i];
			start = clock();
			QuickSort(data, 0, n - 1);
			diff3 = clock() - start;
			printf("快速排序用时为：%d ms\n", diff3);
			//
			for (int i = 0; i < n; i++)data[i] = temdata[i];
			start = clock();
			CountSort(data, n);
			diff4 = clock() - start;
			printf("计数排序用时为：%d ms\n", diff4);
			//
			for (int i = 0; i < n; i++)data[i] = temdata[i];
			start = clock();
			RadixSort(data, n);
			diff5 = clock() - start;
			printf("基数排序用时为：%d ms\n", diff5);
			printf("回车返回...");
			while (getchar() != '\n');
			free(data);
			free(temdata);
			diff1 = diff2 = diff3 = diff4 = diff5 = 0;
			break;
		case 8:
			printf("请输入数据量：");
			scanf("%d", &n);
			while (getchar() != '\n');
			data = (int*)malloc(sizeof(int) * n);
			srand(time(NULL));
			for (int i = 0; i < n; i++)data[i] = rand() % 3;//设置范围[0,2]
			printf("排序前：");
			for (int i = 0; i < n; i++)printf("%d  ", data[i]);
			printf("\n");
			SortColors(data, n);
			printf("排序后：");
			for (int i = 0; i < n; i++)printf("%d  ", data[i]);
			printf("回车返回...");
			while (getchar() != '\n');
			free(data);
			break;
		case 9:
			printf("请输入数据量：");
			scanf("%d", &n);
			while (getchar() != '\n');
			data = (int*)malloc(sizeof(int) * n);
			CreateNumbers(data, n);
			printf("请输入要找第几大数据：");
			int k;
			scanf("%d", &k);
			while (getchar() != '\n');
			printf("无序数列如下：");
			for (int i = 0; i < n; i++) {
				printf("%d  ", data[i]);
			}
			printf("\n");
			printf("无序数列中第%d大的数是：%d\n", k, SortNumK(data, 0, n - 1, k));
			printf("回车返回...");
			while (getchar() != '\n');
			free(data);
			break;
		case 10:
			printf("请输入要存储的文件名(如data.txt)：");
			scanf("%s", filename);
			while (getchar() != '\n');
			printf("请输入要产生的数据量：");
			scanf("%d", &n);
			while (getchar() != '\n');
			data = (int*)malloc(sizeof(int) * n);
			CreateNumbers(data, n);
			printf("正在存入数据......");
			SaveDataInFile(data, n, filename);
			printf("存入完成！");
			printf("回车返回...");
			while (getchar() != '\n');
			break;
		case 11:
			printf("请输入要读取的文件名(如data.txt)：");
			scanf("%s", filename);
			while (getchar() != '\n');
			data = (int*)malloc(sizeof(int) * 10000000);
			n = ReadDataFromFile(data, filename);
			if (n == 0) {
				printf("文件中没有数据！");
				Sleep(2000);
				break;
			}
			temdata = (int*)malloc(sizeof(int) * n);//临时存储空间
			for (int i = 0; i < n; i++)temdata[i] = data[i];
			printf("正在计算用时（同组数据）......\n");
			//
			start = clock();
			InsertSort(data, n);
			diff1 = clock() - start;
			printf("插入排序用时为：%d ms\n", diff1);
			//
			for (int i = 0; i < n; i++)data[i] = temdata[i];
			start = clock();
			MergeSort(data, 0, n - 1);
			diff2 = clock() - start;
			printf("归并排序用时为：%d ms\n", diff2);
			//
			for (int i = 0; i < n; i++)data[i] = temdata[i];
			start = clock();
			QuickSort(data, 0, n - 1);
			diff3 = clock() - start;
			printf("快速排序用时为：%d ms\n", diff3);
			//
			for (int i = 0; i < n; i++)data[i] = temdata[i];
			start = clock();
			CountSort(data, n);
			diff4 = clock() - start;
			printf("计数排序用时为：%d ms\n", diff4);
			//
			for (int i = 0; i < n; i++)data[i] = temdata[i];
			start = clock();
			RadixSort(data, n);
			diff5 = clock() - start;
			printf("基数排序用时为：%d ms\n", diff5);
			printf("回车返回...");
			while (getchar() != '\n');
			free(data);
			free(temdata);
			diff1 = diff2 = diff3 = diff4 = diff5 = 0;
			break;
		case 12:
			system("cls");
			printf("Good luck!\n");
			return;
		default:
			break;
		}
	}
	return 0;
}