#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"
#include "Operation.h"

//初始化队列
void InitQueue(LinkQueue* q)
{
	if (q->length >= 0) {
		printf("已初始化队列！");
		Sleep(2000);
		return;
	}
	QueuePtr p = (QueuePtr)malloc(LEN);
	q->head = q->tail = p;
	p->next = NULL;
	q->length = 0;
	printf("初始化成功！");
	Sleep(2000);
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

//查看队头元素
void GetHeadQueue(LinkQueue* q)
{
	if (q->length < 0) {
		printf("尚未初始化！");
		Sleep(2000);
		return;
	}
	if (IsEmptyLinkQueue(q)) {
		printf("队列为空！");
		Sleep(2000);
		return;
	}
	void* e = (void*)malloc(sizeof(char*));
	e = (char*)q->head->next->data;
	printf("队头元素是：%s", (char*)e);
	Sleep(2000);
	return;
}

//确定队列长度
void LengthLinkQueue(LinkQueue* q)
{
	if (q->length < 0) {
		printf("尚未初始化！");
		Sleep(2000);
		return 0;
	}
	else {
		printf("队列长度是%d", q->length);//链栈的长度就是头结点中的计数器数值
		Sleep(2000);
	}
}

//入队
void EnLinkQueue(LinkQueue* q)
{
	if (q->length < 0) {
		printf("尚未初始化！");
		Sleep(2000);
		return;
	}
	QueuePtr p = (QueuePtr)malloc(LEN);
	printf("请输入数据：\n");
	void* e = (void*)malloc(sizeof(char*));//每次开辟空间
	gets(e);//以字符串输入
	//memcpy(p->data, e, sizeof(e));//将e中的数据复制到p中
	p->data = e;//赋值
	p->next = NULL;
	q->tail->next = p;//最后一个结点指向新的结点
	q->tail = p;//尾指向新结点
	q->length++;//长度加一
	printf("入队成功");
	Sleep(2000);
}

//出队
void DeLLinkQueue(LinkQueue* q)
{
	if (q->length < 0) {
		printf("尚未初始化！");
		Sleep(2000);
		return;
	}
	if (IsEmptyLinkQueue(q)) {
		printf("队列为空！");
		Sleep(2000);
		return;
	}
	QueuePtr p;
	p = q->head->next;
	q->head->next = p->next;//   q->head    p(q->head->next)    p->next   先进先出
	//注意只有一个结点的情况
	if (q->tail == p) {
		q->tail = q->head;
	}
	free(p);
	q->length--;
	printf("出队成功！");
	Sleep(2000);
	return;
}

//清空队列
void ClearLinkQueue(LinkQueue* q)
{
	if (q->length < 0) {
		printf("尚未初始化！");
		Sleep(2000);
		return;
	}
	QueuePtr p, t;
	p = q->head->next;
	while (p) {
		t = p;
		p = p->next;
		free(p);
	}
	q->tail = q->head;
	q->length = 0;
}

//销毁队列
void DestoryLinkQueue(LinkQueue* q)
{
	if (q->length < 0) {
		printf("尚未初始化！");
		Sleep(2000);
		return;
	}
	ClearLinkQueue(q);
	/*QueuePtr p;*/
	//free(q->head);
	//清空后重新初始化
	q->head = q->tail = NULL;
	q->length = -1;
	printf("销毁完成！");
	Sleep(2000);
	//for (p = q->head; p; p = q->head) {
	//	q->head = q->head->next;
	//	free(p);
	//}

	//free()
}

//链队的打印
void PrintLinkStack(LinkQueue q) {
	if (q.length < 0) {
		printf("尚未初始化！");
		Sleep(2000);
		return;
	}
	//判断队列是否为空
	if (IsEmptyLinkQueue(&q)) {
		printf("队列为空！\n");
		Sleep(2000);
		return;
	}
	QueuePtr p = q.head->next;	//将p设置为头结点
	int i = 0;		//计数器
	printf("以下就是所有数据：\n");
	while (p) {
		i++;
		printf("Data(%d)：%s\n", i, (char*)p->data);
		p = p->next;
	}
	Sleep(2000);
	return;
}










