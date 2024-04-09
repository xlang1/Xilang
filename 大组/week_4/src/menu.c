#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"
#include "BSTOperation.h"

void PrintMenu()
{
	printf("===*[Menu of Binary Sorting Tree]*===\n");
	printf("[1]--创建排序二叉树\n");
	printf("[2]--先序遍历\n");
	printf("[3]--中序遍历\n");
	printf("[4]--后序遍历\n");
	printf("[5]--层序遍历\n");
	printf("[6]--查找数据\n");
	printf("[7]--插入数据\n");
	printf("[8]--删除数据\n");
	printf("[9]--退出\n");
	printf("=====================================\n");
}

void Operator()
{
	BSTNodePtr BST = NULL;
	int command;
	int* data = (int*)malloc(sizeof(int) * 1000);//存储输入的数据
	int i;//索引
	BSTNodePtr NewNode = NULL;//插入&删除时暂时使用
	int tempdata;//插入&查找&删除使用的临时数据变量
	while (1) {
		system("cls");
		PrintMenu();
		printf("请输入指令：");
		scanf("%d", &command);
		while (getchar() != '\n');
		switch (command) {
		case 1:
			printf("请输入数据(输入0停止)：\n");
			for (i = 0; data[i - 1] != 0; i++) {
				printf("Data(%d)：", i + 1);
				scanf("%d", &data[i]);
				while (getchar() != '\n');
			}
			for (i = 0; data[i] != 0; i++) {
				BST = CreateBST(BST, data[i]);
			}
			printf("创建完成！\n");
			printf("中序遍历如下：\n");
			InOrderTraverse(BST);
			Sleep(2000);
			break;
		case 2:
			printf("先序遍历：");
			PreOrderTraverse(BST);
			printf("\n回车返回...");
			while (getchar() != '\n');
			break;
		case 3:
			printf("中序遍历：");
			InOrderTraverse(BST);
			printf("\n回车返回...");
			while (getchar() != '\n');
			break;
		case 4:
			printf("后序遍历：");
			PostOrderTraverse(BST);
			printf("\n回车返回...");
			while (getchar() != '\n');
			break;
		case 5:
			printf("层序遍历：");
			LevelTraverse(BST);
			break;
		case 6:
			printf("请输入要查找的数据：");
			scanf("%d", &tempdata);
			while (getchar() != '\n');
			if (SearchNode(BST, tempdata) == NULL)printf("树中没有此数据");
			if (SearchNode(BST, tempdata) != NULL)printf("树中有此数据");
			printf("\n回车返回...");
			while (getchar() != '\n');
			break;
		case 7:
			NewNode = NULL;
			printf("请输入数据：");
			scanf("%d", &tempdata);
			while (getchar() != '\n');
			NewNode = CreateBST(NewNode, tempdata);
			AddData(NewNode, &BST);
			break;
		case 8:
			NewNode = NULL;
			printf("请输入要删除的数据：");
			scanf("%d", &tempdata);
			while (getchar() != '\n');
			NewNode = SearchNode(BST, tempdata);
			DeleteNode(NewNode, &BST);
			break;
		case 9:
			system("cls");
			printf("Have a good day！\n");
			return;
		default:
			break;
		}
	}
}