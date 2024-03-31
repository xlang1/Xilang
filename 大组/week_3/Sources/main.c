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
	int command;//ָ��
	int min, max, n;
	int* data = NULL;
	int* temdata = NULL;
	char filename[50];
	int diff1 = 0, diff2 = 0, diff3 = 0, diff4 = 0, diff5 = 0;//�ֱ��¼С����������������������ʱ
	clock_t start;
	clock_t diff;
	while (1) {
		system("cls");
		OperationMenu();
		printf("���������ָ��(1-11)��");
		scanf("%d", &command);
		while (getchar() != '\n');
		int k = 0;
		switch (command) {
		case 1://����
			printf("��������������С��");
			scanf("%d", &n);
			data = (int*)malloc(sizeof(int) * n);
			while (getchar() != '\n');
			CreateNumbers(data, n);//��������
			printf("���ڼ�����ʱ......\n");
			start = clock();
			InsertSort(data, n);
			diff = clock() - start;
			printf("��ʱΪ��%d ms\n", diff);
			printf("�س�����...");
			while (getchar() != '\n');
			free(data);
			break;
		case 2://�鲢
			printf("��������������С��");
			scanf("%d", &n);
			data = (int*)malloc(sizeof(int) * n);
			while (getchar() != '\n');
			CreateNumbers(data, n);
			printf("���ڼ�����ʱ......\n");
			start = clock();
			MergeSort(data, 0, n - 1);
			diff = clock() - start;
			printf("��ʱΪ��%d ms\n", diff);
			printf("�س�����...");
			while (getchar() != '\n');
			free(data);
			break;
		case 3://����
			printf("��������������С��");
			scanf("%d", &n);
			data = (int*)malloc(sizeof(int) * n);
			while (getchar() != '\n');
			CreateNumbers(data, n);//��������
			printf("���ڼ�����ʱ......\n");
			start = clock();
			QuickSort(data, 0, n - 1);
			diff = clock() - start;
			printf("��ʱΪ��%d ms\n", diff);
			printf("�س�����...");
			while (getchar() != '\n');
			free(data);
			break;
		case 4://����
			printf("��������������С��");
			scanf("%d", &n);
			data = (int*)malloc(sizeof(int) * n);
			while (getchar() != '\n');
			CreateNumbers(data, n);//��������
			printf("���ڼ�����ʱ......\n");
			start = clock();
			CountSort(data, n);
			diff = clock() - start;
			printf("��ʱΪ��%d ms\n", diff);
			printf("�س�����...");
			while (getchar() != '\n');
			free(data);
			break;
		case 5://����
			printf("��������������С��");
			scanf("%d", &n);
			data = (int*)malloc(sizeof(int) * n);
			while (getchar() != '\n');
			CreateNumbers(data, n);//��������
			printf("���ڼ�����ʱ......\n");
			start = clock();
			RadixSort(data, n);
			diff = clock() - start;
			printf("��ʱΪ��%d ms\n", diff);
			printf("�س�����...");
			while (getchar() != '\n');;
			free(data);
			break;
		case 6://С���ݶ��
			printf("���ڼ�����ʱ��ͬ�����ݣ�......\n");
			while (k != 100000) {
				data = (int*)malloc(sizeof(int) * 100);
				temdata = (int*)malloc(sizeof(int) * 100);
				CreateNumbers(data, 100);//��������
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
			printf("����������ʱΪ��%d ms\n", diff1);
			printf("�鲢������ʱΪ��%d ms\n", diff2);
			printf("����������ʱΪ��%d ms\n", diff3);
			printf("����������ʱΪ��%d ms\n", diff4);
			printf("����������ʱΪ��%d ms\n", diff5);
			printf("�س�����...");
			while (getchar() != '\n');
			diff1 = diff2 = diff3 = diff4 = diff5 = 0;
			break;
		case 7:
			printf("��������������С��");
			scanf("%d", &n);
			while (getchar() != '\n');
			data = (int*)malloc(sizeof(int) * n);
			temdata = (int*)malloc(sizeof(int) * n);//��ʱ�洢�ռ�
			CreateNumbers(data, n);//��������
			for (int i = 0; i < n; i++)temdata[i] = data[i];
			printf("���ڼ�����ʱ��ͬ�����ݣ�......\n");
			//
			start = clock();
			InsertSort(data, n);
			diff1 = clock() - start;
			printf("����������ʱΪ��%d ms\n", diff1);
			//
			for (int i = 0; i < n; i++)data[i] = temdata[i];
			start = clock();
			MergeSort(data, 0, n - 1);
			diff2 = clock() - start;
			printf("�鲢������ʱΪ��%d ms\n", diff2);
			//
			for (int i = 0; i < n; i++)data[i] = temdata[i];
			start = clock();
			QuickSort(data, 0, n - 1);
			diff3 = clock() - start;
			printf("����������ʱΪ��%d ms\n", diff3);
			//
			for (int i = 0; i < n; i++)data[i] = temdata[i];
			start = clock();
			CountSort(data, n);
			diff4 = clock() - start;
			printf("����������ʱΪ��%d ms\n", diff4);
			//
			for (int i = 0; i < n; i++)data[i] = temdata[i];
			start = clock();
			RadixSort(data, n);
			diff5 = clock() - start;
			printf("����������ʱΪ��%d ms\n", diff5);
			printf("�س�����...");
			while (getchar() != '\n');
			free(data);
			free(temdata);
			diff1 = diff2 = diff3 = diff4 = diff5 = 0;
			break;
		case 8:
			printf("��������������");
			scanf("%d", &n);
			while (getchar() != '\n');
			data = (int*)malloc(sizeof(int) * n);
			srand(time(NULL));
			for (int i = 0; i < n; i++)data[i] = rand() % 3;//���÷�Χ[0,2]
			printf("����ǰ��");
			for (int i = 0; i < n; i++)printf("%d  ", data[i]);
			printf("\n");
			SortColors(data, n);
			printf("�����");
			for (int i = 0; i < n; i++)printf("%d  ", data[i]);
			printf("�س�����...");
			while (getchar() != '\n');
			free(data);
			break;
		case 9:
			printf("��������������");
			scanf("%d", &n);
			while (getchar() != '\n');
			data = (int*)malloc(sizeof(int) * n);
			CreateNumbers(data, n);
			printf("������Ҫ�ҵڼ������ݣ�");
			int k;
			scanf("%d", &k);
			while (getchar() != '\n');
			printf("�����������£�");
			for (int i = 0; i < n; i++) {
				printf("%d  ", data[i]);
			}
			printf("\n");
			printf("���������е�%d������ǣ�%d\n", k, SortNumK(data, 0, n - 1, k));
			printf("�س�����...");
			while (getchar() != '\n');
			free(data);
			break;
		case 10:
			printf("������Ҫ�洢���ļ���(��data.txt)��");
			scanf("%s", filename);
			while (getchar() != '\n');
			printf("������Ҫ��������������");
			scanf("%d", &n);
			while (getchar() != '\n');
			data = (int*)malloc(sizeof(int) * n);
			CreateNumbers(data, n);
			printf("���ڴ�������......");
			SaveDataInFile(data, n, filename);
			printf("������ɣ�");
			printf("�س�����...");
			while (getchar() != '\n');
			break;
		case 11:
			printf("������Ҫ��ȡ���ļ���(��data.txt)��");
			scanf("%s", filename);
			while (getchar() != '\n');
			data = (int*)malloc(sizeof(int) * 10000000);
			n = ReadDataFromFile(data, filename);
			if (n == 0) {
				printf("�ļ���û�����ݣ�");
				Sleep(2000);
				break;
			}
			temdata = (int*)malloc(sizeof(int) * n);//��ʱ�洢�ռ�
			for (int i = 0; i < n; i++)temdata[i] = data[i];
			printf("���ڼ�����ʱ��ͬ�����ݣ�......\n");
			//
			start = clock();
			InsertSort(data, n);
			diff1 = clock() - start;
			printf("����������ʱΪ��%d ms\n", diff1);
			//
			for (int i = 0; i < n; i++)data[i] = temdata[i];
			start = clock();
			MergeSort(data, 0, n - 1);
			diff2 = clock() - start;
			printf("�鲢������ʱΪ��%d ms\n", diff2);
			//
			for (int i = 0; i < n; i++)data[i] = temdata[i];
			start = clock();
			QuickSort(data, 0, n - 1);
			diff3 = clock() - start;
			printf("����������ʱΪ��%d ms\n", diff3);
			//
			for (int i = 0; i < n; i++)data[i] = temdata[i];
			start = clock();
			CountSort(data, n);
			diff4 = clock() - start;
			printf("����������ʱΪ��%d ms\n", diff4);
			//
			for (int i = 0; i < n; i++)data[i] = temdata[i];
			start = clock();
			RadixSort(data, n);
			diff5 = clock() - start;
			printf("����������ʱΪ��%d ms\n", diff5);
			printf("�س�����...");
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