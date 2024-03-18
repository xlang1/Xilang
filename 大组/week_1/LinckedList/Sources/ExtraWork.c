#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdlib.h>
#include "struct.h"//结构体
#include "ExtraWork.h"

void JudgeLoop(singleList head)//判断是否成环：快慢指针法
{
	if (head == NULL) {
		printf("尚未创建链表！（回车返回）");
		getchar();
		return;
	}
	if (head->next == NULL) {
		printf("链中没有环！（回车返回）");
		getchar();
		return;
	}
	singleList fastPpint, slowPoint;
	fastPpint = slowPoint = head;
	while (fastPpint != NULL) {
		slowPoint = slowPoint->next;
		fastPpint = fastPpint->next->next;
		if (slowPoint == fastPpint)printf("链中有环！（回车返回）");
		getchar();
		return;
	}
	printf("链中没有环！（回车返回）");
	getchar();
}

singleList ParitySwap(singleList head) //奇偶对换
{
	if (head == NULL || head->next == NULL) {
		printf("尚未创建链表或结点不足两个！（回车返回）");
		return head;
	}
	singleList p1 = head, p2 = p1->next, p;
	//先调换1 2结点（规律之外）
	head = p2;//头指针变成p2的位置
	p1->next = p2->next;
	p2->next = p1;
	if (p1->next == NULL)return head;//只有两个结点
	p = p1;//记录p1位置
	p1 = p->next;
	p2 = p1->next;
	while (p1 != NULL && p2 != NULL) {
		p1 = p->next;
		p2 = p1->next;
		//交换
		//p->p1->p2
		p->next = p2;
		p1->next = p2->next;
		p2->next = p1;
		p = p1;//前移
	}
	printf("奇偶反转成功！（回车返回）");
	getchar();
	return head;
}

//singleList ReverseList(singleList head)//反转结点（遍历法）
//  {
//	if (head == NULL) {
//		printf("尚未创建链表！（回车返回）");
//		return head;
//	}
//	// pre是首先是反转后的链表尾，cur是当前指针
//	singleList pre = NULL;
//	singleList cur = head;
//	while (cur != NULL) {
//		singleList temp = cur->next;//temp用于记录cur原链表的下一结点
//		cur->next = pre;//反转
//		pre = cur;//前移
//		cur = temp;//准备下一结点的反转
//	}
//	printf("反转成功（回车返回）");
//	getchar();
//	return pre;//最后pre是头
//}


singleList ReverseSingleList(singleList head) // 反转结点（递归法）
{
	/*
	* 1    2    3
	* 1.3个结点，一直遍历到第三个时head->next==NULL，有三层，最后一层时head到达3
	* 2.开始返回第一个head，回到第二层，此时head在2
	* 3.执行完第二层下面的语句后（此时最后一个和倒数第二个已经是反方向了），返回
	* 4.开始返回newHead，此时newHead位置不变，回到第一层，此时head在1
	* 多个结点同理
	*/
	if (head == NULL || head->next == NULL)return head;//当L为空或者只有L一个节点时
	singleList newHead, p;
	newHead = ReverseSingleList(head->next);
	p = head->next;
	p->next = head;
	head->next = NULL;
	return newHead;
}

void SearchMidpoint(singleList head) // 找中间结点
{
	if (head == NULL || head->data[0] == -51) {
		printf("尚未创建链表或尚未有结点！（回车返回）");
		getchar();
	}
	if (head->next == NULL) {
		printf("只有一个结点！（回车返回）");
		getchar();
	}
	singleList fastPoint = head, slowPoint = head;
	while (fastPoint != NULL && fastPoint->next != NULL) {
		fastPoint = fastPoint->next->next;
		slowPoint = slowPoint->next;
	}
	printf("中间结点如下（回车返回）：\n");
	printf("Data:%s", slowPoint->data);
	getchar();
}

