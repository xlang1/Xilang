#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdlib.h>
#include "struct.h"//�ṹ��
#include "ExtraWork.h"

void JudgeLoop(singleList head)//�ж��Ƿ�ɻ�������ָ�뷨
{
	if (head == NULL) {
		printf("��δ�����������س����أ�");
		getchar();
		return;
	}
	if (head->next == NULL) {
		printf("����û�л������س����أ�");
		getchar();
		return;
	}
	singleList fastPpint, slowPoint;
	fastPpint = slowPoint = head;
	while (fastPpint != NULL) {
		slowPoint = slowPoint->next;
		fastPpint = fastPpint->next->next;
		if (slowPoint == fastPpint)printf("�����л������س����أ�");
		getchar();
		return;
	}
	printf("����û�л������س����أ�");
	getchar();
}

singleList ParitySwap(singleList head) //��ż�Ի�
{
	if (head == NULL || head->next == NULL) {
		printf("��δ����������㲻�����������س����أ�");
		return head;
	}
	singleList p1 = head, p2 = p1->next, p;
	//�ȵ���1 2��㣨����֮�⣩
	head = p2;//ͷָ����p2��λ��
	p1->next = p2->next;
	p2->next = p1;
	if (p1->next == NULL)return head;//ֻ���������
	p = p1;//��¼p1λ��
	p1 = p->next;
	p2 = p1->next;
	while (p1 != NULL && p2 != NULL) {
		p1 = p->next;
		p2 = p1->next;
		//����
		//p->p1->p2
		p->next = p2;
		p1->next = p2->next;
		p2->next = p1;
		p = p1;//ǰ��
	}
	printf("��ż��ת�ɹ������س����أ�");
	getchar();
	return head;
}

//singleList ReverseList(singleList head)//��ת��㣨��������
//  {
//	if (head == NULL) {
//		printf("��δ�����������س����أ�");
//		return head;
//	}
//	// pre�������Ƿ�ת�������β��cur�ǵ�ǰָ��
//	singleList pre = NULL;
//	singleList cur = head;
//	while (cur != NULL) {
//		singleList temp = cur->next;//temp���ڼ�¼curԭ�������һ���
//		cur->next = pre;//��ת
//		pre = cur;//ǰ��
//		cur = temp;//׼����һ���ķ�ת
//	}
//	printf("��ת�ɹ����س����أ�");
//	getchar();
//	return pre;//���pre��ͷ
//}


singleList ReverseSingleList(singleList head) // ��ת��㣨�ݹ鷨��
{
	/*
	* 1    2    3
	* 1.3����㣬һֱ������������ʱhead->next==NULL�������㣬���һ��ʱhead����3
	* 2.��ʼ���ص�һ��head���ص��ڶ��㣬��ʱhead��2
	* 3.ִ����ڶ�����������󣨴�ʱ���һ���͵����ڶ����Ѿ��Ƿ������ˣ�������
	* 4.��ʼ����newHead����ʱnewHeadλ�ò��䣬�ص���һ�㣬��ʱhead��1
	* ������ͬ��
	*/
	if (head == NULL || head->next == NULL)return head;//��LΪ�ջ���ֻ��Lһ���ڵ�ʱ
	singleList newHead, p;
	newHead = ReverseSingleList(head->next);
	p = head->next;
	p->next = head;
	head->next = NULL;
	return newHead;
}

void SearchMidpoint(singleList head) // ���м���
{
	if (head == NULL || head->data[0] == -51) {
		printf("��δ�����������δ�н�㣡���س����أ�");
		getchar();
	}
	if (head->next == NULL) {
		printf("ֻ��һ����㣡���س����أ�");
		getchar();
	}
	singleList fastPoint = head, slowPoint = head;
	while (fastPoint != NULL && fastPoint->next != NULL) {
		fastPoint = fastPoint->next->next;
		slowPoint = slowPoint->next;
	}
	printf("�м������£��س����أ���\n");
	printf("Data:%s", slowPoint->data);
	getchar();
}

