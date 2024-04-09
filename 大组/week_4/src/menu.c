#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"
#include "BSTOperation.h"

void PrintMenu()
{
	printf("===*[Menu of Binary Sorting Tree]*===\n");
	printf("[1]--�������������\n");
	printf("[2]--�������\n");
	printf("[3]--�������\n");
	printf("[4]--�������\n");
	printf("[5]--�������\n");
	printf("[6]--��������\n");
	printf("[7]--��������\n");
	printf("[8]--ɾ������\n");
	printf("[9]--�˳�\n");
	printf("=====================================\n");
}

void Operator()
{
	BSTNodePtr BST = NULL;
	int command;
	int* data = (int*)malloc(sizeof(int) * 1000);//�洢���������
	int i;//����
	BSTNodePtr NewNode = NULL;//����&ɾ��ʱ��ʱʹ��
	int tempdata;//����&����&ɾ��ʹ�õ���ʱ���ݱ���
	while (1) {
		system("cls");
		PrintMenu();
		printf("������ָ�");
		scanf("%d", &command);
		while (getchar() != '\n');
		switch (command) {
		case 1:
			printf("����������(����0ֹͣ)��\n");
			for (i = 0; data[i - 1] != 0; i++) {
				printf("Data(%d)��", i + 1);
				scanf("%d", &data[i]);
				while (getchar() != '\n');
			}
			for (i = 0; data[i] != 0; i++) {
				BST = CreateBST(BST, data[i]);
			}
			printf("������ɣ�\n");
			printf("����������£�\n");
			InOrderTraverse(BST);
			Sleep(2000);
			break;
		case 2:
			printf("���������");
			PreOrderTraverse(BST);
			printf("\n�س�����...");
			while (getchar() != '\n');
			break;
		case 3:
			printf("���������");
			InOrderTraverse(BST);
			printf("\n�س�����...");
			while (getchar() != '\n');
			break;
		case 4:
			printf("���������");
			PostOrderTraverse(BST);
			printf("\n�س�����...");
			while (getchar() != '\n');
			break;
		case 5:
			printf("���������");
			LevelTraverse(BST);
			break;
		case 6:
			printf("������Ҫ���ҵ����ݣ�");
			scanf("%d", &tempdata);
			while (getchar() != '\n');
			if (SearchNode(BST, tempdata) == NULL)printf("����û�д�����");
			if (SearchNode(BST, tempdata) != NULL)printf("�����д�����");
			printf("\n�س�����...");
			while (getchar() != '\n');
			break;
		case 7:
			NewNode = NULL;
			printf("���������ݣ�");
			scanf("%d", &tempdata);
			while (getchar() != '\n');
			NewNode = CreateBST(NewNode, tempdata);
			AddData(NewNode, &BST);
			break;
		case 8:
			NewNode = NULL;
			printf("������Ҫɾ�������ݣ�");
			scanf("%d", &tempdata);
			while (getchar() != '\n');
			NewNode = SearchNode(BST, tempdata);
			DeleteNode(NewNode, &BST);
			break;
		case 9:
			system("cls");
			printf("Have a good day��\n");
			return;
		default:
			break;
		}
	}
}