#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdlib.h>
#include "struct.h"
#include "StackOperation.h"

//��ʼ����ջ
void InitLinkStack(LinkStack* s) {
	//if (s->count >= 0) {
	//	printf("�ѳ�ʼ����ջ��");
	//	return;
	//}
	//�����ݵ�ͷ���
	s->top = (LinkStackPtr)malloc(LEN);
	s->top = NULL;
	s->count = 0;
}

//�ж���ջ�Ƿ�Ϊ��
int IsEmptyStack(LinkStack* s) {
	//Ԫ����Ϊ0��˵����ջΪ��
	if (s->count <= 0) {
		return 1;
	}
	else {
		return 0;
	}
}

//�����ջ
void ClearStack(LinkStack* s) {
	LinkStackPtr p, q;   //������ʱ��ջ���
	p = s->top;
	while (p) {
		q = p;
		p = p->next;   //���¼���
		free(q);   //����
	}
	s->count = 0;   //����������
}

//������ջ
void DestroyLinkStack(LinkStack* s) {
	//��պ�ָ�δ��ʼ��״̬
	ClearStack(s);
	s->count = -1;
	s->top = NULL;
	printf("���ٳɹ���");
	Sleep(2000);
}

//��ȡ��ջ�ĳ���
void GetLength(LinkStack s) {
	if (s.count < 0) {
		printf("��δ��ʼ����");
		Sleep(2000);
		return;
	}
	else {
		printf("��ջ������%d", s.count);//��ջ�ĳ��Ⱦ���ͷ����еļ�������ֵ
		Sleep(2000);
	}
}

//��ջ
void PushStack(LinkStack* s, void* e) {
	LinkStackPtr p = (LinkStackPtr)malloc(LEN);
	p->data = e;
	p->next = s->top; //��ͷ�����Ϊ�½�����һ�����
	s->top = p;		 // ͷ�����Ϊ�½��
	s->count++;    //��������һ
	return;
}

//��ջ
void PopStack(LinkStack* s) {
	LinkStackPtr p;
	//�ж�û�г�ʼ�����ٺ�û�н������
	//1.s - p - p->next��2.s - p->next��3.�ͷ�p
	p = s->top;
	s->top = p->next;
	free(p);
	s->count--;
}

//��ȡ��ջ��ջ��Ԫ��
void* GetTopStack(LinkStack* s) {
	//�ж�ջ���Ƿ�Ϊ��
	if (IsEmptyStack(s)) {
		return NULL;
	}
	LinkStackPtr p = s->top;
	return p->data;//���ַ��ͽ��뺯����������void����ʹ�ò�ͬ����
}

////��ջ�Ĵ�ӡ
//void PrintLinkStack(LinkStack s) {
//	if (s.count < 0) {
//		printf("��δ��ʼ����");
//		Sleep(2000);
//		return;
//	}
//	//�ж���ջ�Ƿ�Ϊ��
//	if (IsEmptyStack(s)) {
//		printf("��ջΪ�գ�\n");
//		Sleep(2000);
//		return;
//	}
//	LinkStackPtr p;
//	int i = 0;		//������
//	p = s.top;		//��p����Ϊͷ���
//	printf("���¾����������ݣ�\n");
//	while (p) {
//		i++;
//		printf("Data(%d)��%s\n", i, p->data);
//		p = p->next;
//	}
//	Sleep(2000);
//	return;
//}
