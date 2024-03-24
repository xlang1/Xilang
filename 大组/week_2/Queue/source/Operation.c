#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"
#include "Operation.h"

//��ʼ������
void InitQueue(LinkQueue* q)
{
	if (q->length >= 0) {
		printf("�ѳ�ʼ�����У�");
		Sleep(2000);
		return;
	}
	QueuePtr p = (QueuePtr)malloc(LEN);
	q->head = q->tail = p;
	p->next = NULL;
	q->length = 0;
	printf("��ʼ���ɹ���");
	Sleep(2000);
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

//�鿴��ͷԪ��
void GetHeadQueue(LinkQueue* q)
{
	if (q->length < 0) {
		printf("��δ��ʼ����");
		Sleep(2000);
		return;
	}
	if (IsEmptyLinkQueue(q)) {
		printf("����Ϊ�գ�");
		Sleep(2000);
		return;
	}
	void* e = (void*)malloc(sizeof(char*));
	e = (char*)q->head->next->data;
	printf("��ͷԪ���ǣ�%s", (char*)e);
	Sleep(2000);
	return;
}

//ȷ�����г���
void LengthLinkQueue(LinkQueue* q)
{
	if (q->length < 0) {
		printf("��δ��ʼ����");
		Sleep(2000);
		return 0;
	}
	else {
		printf("���г�����%d", q->length);//��ջ�ĳ��Ⱦ���ͷ����еļ�������ֵ
		Sleep(2000);
	}
}

//���
void EnLinkQueue(LinkQueue* q)
{
	if (q->length < 0) {
		printf("��δ��ʼ����");
		Sleep(2000);
		return;
	}
	QueuePtr p = (QueuePtr)malloc(LEN);
	printf("���������ݣ�\n");
	void* e = (void*)malloc(sizeof(char*));//ÿ�ο��ٿռ�
	gets(e);//���ַ�������
	//memcpy(p->data, e, sizeof(e));//��e�е����ݸ��Ƶ�p��
	p->data = e;//��ֵ
	p->next = NULL;
	q->tail->next = p;//���һ�����ָ���µĽ��
	q->tail = p;//βָ���½��
	q->length++;//���ȼ�һ
	printf("��ӳɹ�");
	Sleep(2000);
}

//����
void DeLLinkQueue(LinkQueue* q)
{
	if (q->length < 0) {
		printf("��δ��ʼ����");
		Sleep(2000);
		return;
	}
	if (IsEmptyLinkQueue(q)) {
		printf("����Ϊ�գ�");
		Sleep(2000);
		return;
	}
	QueuePtr p;
	p = q->head->next;
	q->head->next = p->next;//   q->head    p(q->head->next)    p->next   �Ƚ��ȳ�
	//ע��ֻ��һ���������
	if (q->tail == p) {
		q->tail = q->head;
	}
	free(p);
	q->length--;
	printf("���ӳɹ���");
	Sleep(2000);
	return;
}

//��ն���
void ClearLinkQueue(LinkQueue* q)
{
	if (q->length < 0) {
		printf("��δ��ʼ����");
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

//���ٶ���
void DestoryLinkQueue(LinkQueue* q)
{
	if (q->length < 0) {
		printf("��δ��ʼ����");
		Sleep(2000);
		return;
	}
	ClearLinkQueue(q);
	/*QueuePtr p;*/
	//free(q->head);
	//��պ����³�ʼ��
	q->head = q->tail = NULL;
	q->length = -1;
	printf("������ɣ�");
	Sleep(2000);
	//for (p = q->head; p; p = q->head) {
	//	q->head = q->head->next;
	//	free(p);
	//}

	//free()
}

//���ӵĴ�ӡ
void PrintLinkStack(LinkQueue q) {
	if (q.length < 0) {
		printf("��δ��ʼ����");
		Sleep(2000);
		return;
	}
	//�ж϶����Ƿ�Ϊ��
	if (IsEmptyLinkQueue(&q)) {
		printf("����Ϊ�գ�\n");
		Sleep(2000);
		return;
	}
	QueuePtr p = q.head->next;	//��p����Ϊͷ���
	int i = 0;		//������
	printf("���¾����������ݣ�\n");
	while (p) {
		i++;
		printf("Data(%d)��%s\n", i, (char*)p->data);
		p = p->next;
	}
	Sleep(2000);
	return;
}










