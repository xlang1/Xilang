//#define _CRT_SECURE_NO_WARNINGS
//#include "DoubleListDemo.h"
//#include <stdio.h>
//#include <stdlib.h>
//#define LEN sizeof(struct doubleLNode)
//void DDisplayMenu(int n)//目录显示
//{
//	if (n == 13) {
//		for (int i = 0; i < n; i++) {
//			printf("%s\n", doublieLickedListMenu[i]);
//		}
//	}
//	if (n == 6) {
//		for (int i = 0; i < n; i++) {
//			printf("%s\n", InsertMenu[i]);
//		}
//	}
//
//}
//
//doubleList DCreateEmptyList()//创建空链表
//{
//	doubleList head;
//	head = (doubleList)malloc(LEN);
//	head->next = NULL;
//	printf("空链表创建成功！\n");
//	Sleep(2000);
//	return head;
//}
//
//void DPrintData(doubleList head)//遍历链表
//{
//	//int n = 1;//记录数据数目
//	doubleList p = head;
//	system("cls");
//	//没有创建链表时的说明
//	if (head == NULL)
//	{
//		printf("List is NULL!\n");
//		return;
//	}
//	//创建了空链表的说明
//	if (head->data[0] == -51) {
//		printf("There is nothing in list.");
//		return;
//	}
//	printf("Here are all data:\n");
//	while (p != NULL) {
//		printf("Data(%d):%s\n", p->index, p->data);
//		p = p->next;
//		//n++;
//	}
//}
//
//
//
//
//doubleList DAddData(doubleList head)       //插入结点数据
//{
//	doubleList p0 = (doubleList)malloc(LEN);
//	doubleList p1 = head;
//	if (head == NULL) {
//		printf("尚未创建链表！");
//		printf("（回车返回）");
//		getchar();
//		return head;
//	}
//	DDisplayMenu(6);
//	int command;                            //插入方式的选择方式
//	printf("请输入指令（1-3）：\n");
//	scanf("%d", &command);
//	getchar();                             //回车
//	if (command == 1 || command == 2 || command == 3) {       //选择是要输入数据
//		printf("请输入数据（直接回车退出）:\n");
//		gets(p0->data);
//	}
//	if (head->data[0] == -51) {        //链表为空
//		head = p0;
//		p0->index = 1;
//		p0->next = NULL;
//		printf("输入成功！");
//		printf("（回车返回）");
//		getchar();
//		return head;
//	}
//	switch (command) {
//	case 1:                                     //头插入
//		head = p0;
//		p0->next = p1;
//		p0->index = 1;
//		do {
//			p1->index++;
//			p1 = p1->next;
//		} while (p1 != NULL);
//		printf("输入成功!");
//		printf("（回车返回）");
//		getchar();
//		break;
//	case 2:                                     //尾插入
//		while (p1->next != NULL)p1 = p1->next;  //找到最后一个结点
//		p1->next = p0;
//		p0->next = NULL;
//		p0->index = p1->index + 1;
//		printf("输入成功!");
//		printf("（回车返回）");
//		getchar();
//		break;
//	case 3:                                      //中间插入
//		printData(head);
//		printf("请输入要插入位置的前一个结点索引数：\n");
//		doubleList p2 = p1;
//		scanf("%d", &p0->index);
//		while ((p0->index >= p1->index) && p1->next != NULL) {//找到上一结点
//			p2 = p1;
//			p1 = p1->next;
//		}
//		if (p0->index < p1->index) {
//			p2->next = p0;
//			p0->next = p1;
//			while (p0 != NULL) {
//				p0->index++;
//				p0 = p0->next;
//			}
//		}
//		else {
//			p1->next = p0;
//			p0->next = NULL;
//			p0->index++;//填了最后一个结点的情况
//		}
//		printf("输入成功!");
//		printf("（回车返回）");
//		getchar();
//		break;
//	case 4:
//		return head;   //退出函数
//	default:
//		printf("输入有误!");
//	}
//	return head;
//}
//
//doubleList DDeleteNode(doubleList head)//删除结点
//{
//	doubleList p1, p2;
//	int index;
//	if (head == NULL) {
//		printf("List is NULL!");
//		Sleep(2000);
//		return head;
//	}
//	if (head->data[0] == -51) {
//		printf("There is nothing in list.\n");
//		Sleep(2000);
//		return head;
//	}
//	printData(head);
//	printf("请输入要删除的数据索引：");
//	scanf("%d", &index);
//	getchar();//回车
//	p1 = head;
//	p2 = p1;
//	while (index != p1->index && p1->next != NULL) {
//		p2 = p1;
//		p1 = p1->next;
//	}
//	if (index == p1->index) {
//		if (p1 == head)head = p1->next;
//		else p2->next = p1->next;
//		printf("删除成功！");
//		do {
//			p1->index--;
//			p1 = p1->next;
//		} while (p1 != NULL);
//		printf("（回车返回）");
//		getchar();
//		return head;
//	}
//	else printf("索引未被找到！");
//	return head;
//}
//
//void DSeekData(doubleList head) //查找数据，关键词式查找，如ENGLISH，输入关键词LISH也可以找出
//{
//	char str[30] = "";
//	int i, j;
//	doubleList p;
//	if (head == NULL) {
//		printf("List is NULL!\n");
//		return 0;
//	}
//	printf("请输入要找的数据：");
//	scanf("%s", str);
//	getchar();//回车
//	p = head;
//	while (p != NULL) {      //遍历链表
//		for (j = 0, i = 0; p->data[j] != '\0' && *(str + i) != '\0'; j++) {    //比对数据
//			if (p->data[j] != *(str + i)) {
//				i = 0;
//				continue;     //没对上则继续检查后面的
//			}
//			else {
//				i++;
//			}
//		}
//		if (*(str + i) == '\0') {
//			printf("Data(%d):%s", p->index, p->data);
//			return;
//		}
//		p = p->next;
//	}
//	printf("没有找到此数据！");
//}
//
//void DDestroyList(doubleList head)//销毁链表
//{
//	doubleList p;
//	while (head->next != NULL)
//	{
//		p = head->next;
//		head->next = p->next;
//		free(p);
//	}
//	printf("链表已被销毁！");
//	printf("（回车返回）");
//	getchar();
//	return;
//}
//
//void DJudgeLoop(doubleList head)//判断是否成环：快慢指针法
//{
//	doubleList fastP, slowP;
//	fastP = slowP = head;
//	while (fastP != NULL) {
//		slowP = slowP->next;
//		fastP = fastP->next->next;
//		if (slowP == fastP)printf("链中有环！");
//		return;
//	}
//	printf("链中没有环！");
//}
//
//void DParitySwap(doubleList head) //奇偶对换
//{
//	doubleList p1, p2, p = head;
//	while (p->next != NULL) {
//		p1 = p->next;
//		p2 = p1->next;
//		//交换
//		//p->p1->p2
//		p1->next = p;
//		p->next = p2;
//		head = p1;
//		p = p1;//前移
//	}
//
//	printf("奇偶反转成功！（回车返回）");
//	getchar();
//}

//int main() {
//	doubleList head = NULL;
//	int command1;//1.控制链表指令；2.控制插入指令
//	for (;;) {
//		system("cls");
//		DDisplayMenu(13);
//		printf("请输入指令（1-11）：\n");
//		scanf("%d", &command1);
//		getchar();
//		switch (command1) {
//		case 1:
//			if (head == NULL)head = DCreateEmptyList();//创建空链表
//			else {
//				printf("已创建链表！");
//				Sleep(2000);
//			}
//			break;
//		case 2:
//			DPrintData(head);          //遍历链表打印出数据
//			printf("（回车返回）");
//			getchar();
//			break;
//		case 3:
//			system("cls");
//			head = addData(head);     //插入数据
//			break;
//		case 4:
//			DSeekData(head);
//			printf("（回车返回）");
//			getchar();
//			break;
//		case 5:
//			head = DDeleteNode(head);
//			break;
//		case 6:
//			destroyList(head);
//			break;
//		case 7:
//		case 8:
//			DJudgeLoop(head);
//			printf("（回车返回）");
//			getchar();
//			break;
//		case 9:
//			DParitySwap(head);
//			break;
//		case 10:
//		case 11:
//			system("cls");
//			printf("Hava a nice day!\n");
//			return 0;
//		default:
//			printf("输入指令有误，请重新输入！");
//		}
//	}
//	return 0;
//}