#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include "EssentialWork.h"
#include "struct.h"


singleList CreateSingleList()//创建空链表
{
	singleList head;
	head = (singleList)malloc(LEN1);
	head->next = NULL;
	printf("空链表创建成功！\n");
	Sleep(2000);
	return head;
}

doubleList CreateDoubleList()//创建空链表
{
	doubleList head;
	head = (doubleList)malloc(LEN2);
	head->next = NULL;
	head->front = NULL;
	printf("空链表创建成功！\n");
	Sleep(2000);
	return head;
}

void PrintSingleList(singleList head)//遍历链表
{
	//int n = 1;//记录数据数目
	singleList p = head;
	system("cls");
	//没有创建链表时的说明
	if (head == NULL)
	{
		printf("NULL!\n");
		return;
	}
	//创建了空链表的说明
	if (head->data[0] == -51) {
		printf("There is nothing in list.");
		return;
	}
	printf("Here are all data:\n");
	while (p != NULL) {
		printf("Data(%d):%s\n", p->index, p->data);
		p = p->next;
		//n++;
	}
}

void PrintDoubleList(doubleList head)//遍历链表
{
	//int n = 1;//记录数据数目
	doubleList p = head;
	system("cls");
	//没有创建链表时的说明
	if (head == NULL)
	{
		printf("List is NULL!\n");
		return;
	}
	//创建了空链表的说明
	if (head->data[0] == -51) {
		printf("There is nothing in list.");
		return;
	}
	printf("Here are all data:\n");
	while (p != NULL) {
		printf("Data(%d):%s\n", p->index, p->data);
		p = p->next;
		//n++;
	}
}

singleList AddSingleData(singleList head)       //插入结点数据
{
	singleList p0 = (singleList)malloc(LEN2);
	singleList p1 = head;
	if (head == NULL) {
		printf("尚未创建链表！");
		printf("（回车返回）");
		getchar();
		return head;
	}
	DisplayMenu(6);
	int command;                            //插入方式的选择方式
	printf("请输入指令（1-3）：\n");
	scanf("%d", &command);
	getchar();                             //回车
	if (command == 1 || command == 2 || command == 3) {       //选择是要输入数据
		printf("请输入数据:\n");
		gets(p0->data);
	}
	if (head->data[0] == -51) {        //链表为空
		head = p0;
		p0->index = 1;
		p0->next = NULL;
		printf("输入成功！");
		printf("（回车返回）");
		getchar();
		return head;
	}
	switch (command) {
	case 1:                                     //头插入
		head = p0;
		p0->next = p1;
		p0->index = 1;
		do {
			p1->index++;
			p1 = p1->next;
		} while (p1 != NULL);
		printf("输入成功!");
		printf("（回车返回）");
		getchar();
		break;
	case 2:                                     //尾插入
		while (p1->next != NULL)p1 = p1->next;  //找到最后一个结点
		p1->next = p0;
		p0->next = NULL;
		p0->index = p1->index + 1;
		printf("输入成功!");
		printf("（回车返回）");
		getchar();
		break;
	case 3:                                      //中间插入
		PrintSingleList(head);
		printf("请输入要插入位置的前一个结点索引数：\n");
		singleList p2 = p1;
		scanf("%d", &p0->index);
		while ((p0->index >= p1->index) && p1->next != NULL) {//找到上一结点
			p2 = p1;
			p1 = p1->next;
		}
		if (p0->index < p1->index) {
			p2->next = p0;
			p0->next = p1;
			while (p0 != NULL) {
				p0->index++;
				p0 = p0->next;
			}
		}
		else {
			p1->next = p0;
			p0->next = NULL;
			p0->index++;//填了最后一个结点的情况
		}
		printf("输入成功!");
		printf("（回车返回）");
		getchar();
		break;
	case 4:
		return head;   //退出函数
	default:
		printf("输入有误!");
	}
	return head;
}

doubleList AddDoubleData(doubleList head)       //插入结点数据
{
	doubleList p0 = (doubleList)malloc(LEN2);
	doubleList p1 = head;
	if (head == NULL) {
		printf("尚未创建链表！");
		printf("（回车返回）");
		getchar();
		return head;
	}
	DisplayMenu(6);
	int command;                            //插入方式的选择方式
	printf("请输入指令（1-3）：\n");
	scanf("%d", &command);
	getchar();                             //回车
	if (command == 1 || command == 2 || command == 3) {       //选择是要输入数据
		printf("请输入数据:\n");
		gets(p0->data);
	}
	if (head->data[0] == -51) {        //链表为空
		head = p0;
		p0->front = head;
		p0->index = 1;
		p0->next = NULL;
		printf("输入成功！");
		printf("（回车返回）");
		getchar();
		return head;
	}
	switch (command) {
	case 1:                                     //头插入
		head = p0;
		p0->front = head;
		if (p1->next != NULL)p1->next->front = p0;
		p0->next = p1;
		p0->index = 1;
		do {
			p1->index++;
			p1 = p1->next;
		} while (p1 != NULL);
		printf("输入成功!");
		printf("（回车返回）");
		getchar();
		break;
	case 2:                                     //尾插入
		while (p1->next != NULL)p1 = p1->next;  //找到最后一个结点
		p1->next = p0;
		p0->front = p1;
		p0->next = NULL;
		p0->index = p1->index + 1;
		printf("输入成功!");
		printf("（回车返回）");
		getchar();
		break;
	case 3:                                      //中间插入
		PrintDoubleList(head);
		printf("请输入要插入位置的前一个结点索引数：\n");
		doubleList p2 = p1;
		scanf("%d", &p0->index);
		while ((p0->index >= p1->index) && p1->next != NULL) {//找到上一结点
			p2 = p1;
			p1 = p1->next;
		}
		if (p0->index < p1->index) {    //p2->p0->p1
			p2->next = p0;
			p0->front = p2;
			p0->next = p1;
			p1->front = p0;
			while (p0 != NULL) {
				p0->index++;
				p0 = p0->next;
			}//索引加一
		}
		else {
			p1->next = p0;
			p0->front = p1;
			p0->next = NULL;
			p0->index++;//填了最后一个结点的情况，相当于尾插
		}
		printf("输入成功!（回车返回）");
		getchar();
		break;
	case 4:
		return head;   //退出函数
	default:
		printf("输入有误!");
	}
	return head;
}

void SeekSingleData(singleList head) //查找数据，关键词式查找，如ENGLISH，输入关键词LISH也可以找出
{
	char str[30] = "";
	int i, j;
	singleList p;
	if (head == NULL) {
		printf("List is NULL!\n");
		return 0;
	}
	printf("请输入要找的数据：");
	scanf("%s", str);
	getchar();//回车
	p = head;
	while (p != NULL) {      //遍历链表
		for (j = 0, i = 0; p->data[j] != '\0' && *(str + i) != '\0'; j++) {    //比对数据
			if (p->data[j] != *(str + i)) {
				i = 0;
				continue;     //没对上则继续检查后面的
			}
			else {
				i++;
			}
		}
		if (*(str + i) == '\0') {
			printf("Data(%d):%s", p->index, p->data);
			return;
		}
		p = p->next;
	}
	printf("没有找到此数据！");
}

void SeekDoubleData(doubleList head) //查找数据，关键词式查找，如ENGLISH，输入关键词LISH也可以找出
{
	char str[30] = "";
	int i, j;
	doubleList p;
	if (head == NULL) {
		printf("List is NULL!\n");
		return 0;
	}
	printf("请输入要找的数据：");
	scanf("%s", str);
	getchar();//回车
	p = head;
	while (p != NULL) {      //遍历链表
		for (j = 0, i = 0; p->data[j] != '\0' && *(str + i) != '\0'; j++) {    //比对数据
			if (p->data[j] != *(str + i)) {
				i = 0;
				continue;     //没对上则继续检查后面的
			}
			else {
				i++;
			}
		}
		if (*(str + i) == '\0') {
			printf("Data(%d):%s", p->index, p->data);
			return;
		}
		p = p->next;
	}
	printf("没有找到此数据！");
}

singleList DestroySingleList(singleList head)//销毁链表
{
	singleList p;
	while (head != NULL){//p -> head，free(p)，p=head循环执行
		p = head;
		head = head->next;
		free(p);
	}
	printf("链表已被销毁！（回车返回）");
	getchar();
	return head;
}

doubleList DestroyDouleList(doubleList head)//销毁链表
{
	singleList p;
	while (head != NULL) {//p -> head，free(p)，p=head循环执行
		p = head;
		head = head->next;
		free(p);
	}
	printf("链表已被销毁！（回车返回）");
	getchar();
	return head;
}

singleList DeleteSingleNode(singleList head)//删除结点
{
	singleList p1, p2;
	int index;
	if (head == NULL) {
		printf("List is NULL!");
		Sleep(2000);
		return head;
	}
	if (head->data[0] == -51) {
		printf("There is nothing in list.\n");
		Sleep(2000);
		return head;
	}
	PrintSingleList(head);
	printf("请输入要删除的数据索引：");
	scanf("%d", &index);
	getchar();//回车
	p1 = head;
	p2 = p1;
	while (index != p1->index && p1->next != NULL) {
		p2 = p1;
		p1 = p1->next;
	}
	if (index == p1->index) {
		if (p1 == head)head = p1->next;
		else p2->next = p1->next;
		printf("删除成功！");
		do {
			p1->index--;
			p1 = p1->next;
		} while (p1 != NULL);
		printf("（回车返回）");
		getchar();
		return head;
	}
	else printf("索引未被找到！");
	return head;
}

doubleList DeleteDoubleNode(doubleList head)//删除结点
{
	doubleList p1, p2;
	int index;
	if (head == NULL) {//尚未创建链表
		printf("List is NULL!");
		Sleep(2000);
		return head;
	}
	if (head->data[0] == -51) {
		printf("There is nothing in list.\n");
		Sleep(2000);
		return head;
	}
	PrintDoubleList(head);
	printf("请输入要删除的数据索引：");
	scanf("%d", &index);
	getchar();//回车
	p1 = head;
	p2 = p1;
	while (index != p1->index && p1->next != NULL) {//找到删除结点
		p2 = p1;
		p1 = p1->next;
	}
	if (index == p1->index) {
		if (p1 == head) { 
			head = p1->next; 
			p1->next->front = head;
		}
		else {
			p2->next = p1->next;
			p1->next->front = p2;//p2   p1   p1->next   //删除p1
		}
		printf("删除成功！");
		do {
			p1->index--;
			p1 = p1->next;
		} while (p1 != NULL);
		printf("（回车返回）");
		getchar();
		return head;
	}
	else printf("索引未被找到！");
	return head;
}