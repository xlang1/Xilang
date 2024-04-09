#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"
#include "AssistOperation.h"
//初始化队列
void InitQueue(LinkQueue* q)
{
	QueuePtr p = (QueuePtr)malloc(sizeof(QueueNode));
	q->head = q->tail = p;
	p->next = NULL;
}

//入队
void EnLinkQueue(LinkQueue* q, BSTNodePtr Node)
{
	QueuePtr p = (QueuePtr)malloc(sizeof(QueueNode));
	p->data = Node;//赋值
	p->next = NULL;
	q->tail->next = p;//最后一个结点指向新的结点
	q->tail = p;//尾指向新结点
}

//出队
BSTNodePtr DeLLinkQueue(LinkQueue* q, BSTNodePtr BST)
{
	QueuePtr p = q->head->next;
	BST = p->data;
	q->head->next = p->next;//   q->head    p(q->head->next)    p->next   先进先出
	//注意只有一个结点的情况
	if (q->tail == p)
		q->tail = q->head;
	free(p);
	return BST;
}

//判断是否为空
int IsEmptyLinkQueue(LinkQueue* q)
{
	//头和尾在同一个地方
	if (q->tail == q->head)
		return 1;
	else
		return 0;
}