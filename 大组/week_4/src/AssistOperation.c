#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"
#include "AssistOperation.h"
//��ʼ������
void InitQueue(LinkQueue* q)
{
	QueuePtr p = (QueuePtr)malloc(sizeof(QueueNode));
	q->head = q->tail = p;
	p->next = NULL;
}

//���
void EnLinkQueue(LinkQueue* q, BSTNodePtr Node)
{
	QueuePtr p = (QueuePtr)malloc(sizeof(QueueNode));
	p->data = Node;//��ֵ
	p->next = NULL;
	q->tail->next = p;//���һ�����ָ���µĽ��
	q->tail = p;//βָ���½��
}

//����
BSTNodePtr DeLLinkQueue(LinkQueue* q, BSTNodePtr BST)
{
	QueuePtr p = q->head->next;
	BST = p->data;
	q->head->next = p->next;//   q->head    p(q->head->next)    p->next   �Ƚ��ȳ�
	//ע��ֻ��һ���������
	if (q->tail == p)
		q->tail = q->head;
	free(p);
	return BST;
}

//�ж��Ƿ�Ϊ��
int IsEmptyLinkQueue(LinkQueue* q)
{
	//ͷ��β��ͬһ���ط�
	if (q->tail == q->head)
		return 1;
	else
		return 0;
}