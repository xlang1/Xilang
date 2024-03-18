#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include "EssentialWork.h"
#include "struct.h"


singleList CreateSingleList()//����������
{
	singleList head;
	head = (singleList)malloc(LEN1);
	head->next = NULL;
	printf("���������ɹ���\n");
	Sleep(2000);
	return head;
}

doubleList CreateDoubleList()//����������
{
	doubleList head;
	head = (doubleList)malloc(LEN2);
	head->next = NULL;
	head->front = NULL;
	printf("���������ɹ���\n");
	Sleep(2000);
	return head;
}

void PrintSingleList(singleList head)//��������
{
	//int n = 1;//��¼������Ŀ
	singleList p = head;
	system("cls");
	//û�д�������ʱ��˵��
	if (head == NULL)
	{
		printf("NULL!\n");
		return;
	}
	//�����˿������˵��
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

void PrintDoubleList(doubleList head)//��������
{
	//int n = 1;//��¼������Ŀ
	doubleList p = head;
	system("cls");
	//û�д�������ʱ��˵��
	if (head == NULL)
	{
		printf("List is NULL!\n");
		return;
	}
	//�����˿������˵��
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

singleList AddSingleData(singleList head)       //����������
{
	singleList p0 = (singleList)malloc(LEN2);
	singleList p1 = head;
	if (head == NULL) {
		printf("��δ��������");
		printf("���س����أ�");
		getchar();
		return head;
	}
	DisplayMenu(6);
	int command;                            //���뷽ʽ��ѡ��ʽ
	printf("������ָ�1-3����\n");
	scanf("%d", &command);
	getchar();                             //�س�
	if (command == 1 || command == 2 || command == 3) {       //ѡ����Ҫ��������
		printf("����������:\n");
		gets(p0->data);
	}
	if (head->data[0] == -51) {        //����Ϊ��
		head = p0;
		p0->index = 1;
		p0->next = NULL;
		printf("����ɹ���");
		printf("���س����أ�");
		getchar();
		return head;
	}
	switch (command) {
	case 1:                                     //ͷ����
		head = p0;
		p0->next = p1;
		p0->index = 1;
		do {
			p1->index++;
			p1 = p1->next;
		} while (p1 != NULL);
		printf("����ɹ�!");
		printf("���س����أ�");
		getchar();
		break;
	case 2:                                     //β����
		while (p1->next != NULL)p1 = p1->next;  //�ҵ����һ�����
		p1->next = p0;
		p0->next = NULL;
		p0->index = p1->index + 1;
		printf("����ɹ�!");
		printf("���س����أ�");
		getchar();
		break;
	case 3:                                      //�м����
		PrintSingleList(head);
		printf("������Ҫ����λ�õ�ǰһ�������������\n");
		singleList p2 = p1;
		scanf("%d", &p0->index);
		while ((p0->index >= p1->index) && p1->next != NULL) {//�ҵ���һ���
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
			p0->index++;//�������һ���������
		}
		printf("����ɹ�!");
		printf("���س����أ�");
		getchar();
		break;
	case 4:
		return head;   //�˳�����
	default:
		printf("��������!");
	}
	return head;
}

doubleList AddDoubleData(doubleList head)       //����������
{
	doubleList p0 = (doubleList)malloc(LEN2);
	doubleList p1 = head;
	if (head == NULL) {
		printf("��δ��������");
		printf("���س����أ�");
		getchar();
		return head;
	}
	DisplayMenu(6);
	int command;                            //���뷽ʽ��ѡ��ʽ
	printf("������ָ�1-3����\n");
	scanf("%d", &command);
	getchar();                             //�س�
	if (command == 1 || command == 2 || command == 3) {       //ѡ����Ҫ��������
		printf("����������:\n");
		gets(p0->data);
	}
	if (head->data[0] == -51) {        //����Ϊ��
		head = p0;
		p0->front = head;
		p0->index = 1;
		p0->next = NULL;
		printf("����ɹ���");
		printf("���س����أ�");
		getchar();
		return head;
	}
	switch (command) {
	case 1:                                     //ͷ����
		head = p0;
		p0->front = head;
		if (p1->next != NULL)p1->next->front = p0;
		p0->next = p1;
		p0->index = 1;
		do {
			p1->index++;
			p1 = p1->next;
		} while (p1 != NULL);
		printf("����ɹ�!");
		printf("���س����أ�");
		getchar();
		break;
	case 2:                                     //β����
		while (p1->next != NULL)p1 = p1->next;  //�ҵ����һ�����
		p1->next = p0;
		p0->front = p1;
		p0->next = NULL;
		p0->index = p1->index + 1;
		printf("����ɹ�!");
		printf("���س����أ�");
		getchar();
		break;
	case 3:                                      //�м����
		PrintDoubleList(head);
		printf("������Ҫ����λ�õ�ǰһ�������������\n");
		doubleList p2 = p1;
		scanf("%d", &p0->index);
		while ((p0->index >= p1->index) && p1->next != NULL) {//�ҵ���һ���
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
			}//������һ
		}
		else {
			p1->next = p0;
			p0->front = p1;
			p0->next = NULL;
			p0->index++;//�������һ������������൱��β��
		}
		printf("����ɹ�!���س����أ�");
		getchar();
		break;
	case 4:
		return head;   //�˳�����
	default:
		printf("��������!");
	}
	return head;
}

void SeekSingleData(singleList head) //�������ݣ��ؼ���ʽ���ң���ENGLISH������ؼ���LISHҲ�����ҳ�
{
	char str[30] = "";
	int i, j;
	singleList p;
	if (head == NULL) {
		printf("List is NULL!\n");
		return 0;
	}
	printf("������Ҫ�ҵ����ݣ�");
	scanf("%s", str);
	getchar();//�س�
	p = head;
	while (p != NULL) {      //��������
		for (j = 0, i = 0; p->data[j] != '\0' && *(str + i) != '\0'; j++) {    //�ȶ�����
			if (p->data[j] != *(str + i)) {
				i = 0;
				continue;     //û����������������
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
	printf("û���ҵ������ݣ�");
}

void SeekDoubleData(doubleList head) //�������ݣ��ؼ���ʽ���ң���ENGLISH������ؼ���LISHҲ�����ҳ�
{
	char str[30] = "";
	int i, j;
	doubleList p;
	if (head == NULL) {
		printf("List is NULL!\n");
		return 0;
	}
	printf("������Ҫ�ҵ����ݣ�");
	scanf("%s", str);
	getchar();//�س�
	p = head;
	while (p != NULL) {      //��������
		for (j = 0, i = 0; p->data[j] != '\0' && *(str + i) != '\0'; j++) {    //�ȶ�����
			if (p->data[j] != *(str + i)) {
				i = 0;
				continue;     //û����������������
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
	printf("û���ҵ������ݣ�");
}

singleList DestroySingleList(singleList head)//��������
{
	singleList p;
	while (head != NULL){//p -> head��free(p)��p=headѭ��ִ��
		p = head;
		head = head->next;
		free(p);
	}
	printf("�����ѱ����٣����س����أ�");
	getchar();
	return head;
}

doubleList DestroyDouleList(doubleList head)//��������
{
	singleList p;
	while (head != NULL) {//p -> head��free(p)��p=headѭ��ִ��
		p = head;
		head = head->next;
		free(p);
	}
	printf("�����ѱ����٣����س����أ�");
	getchar();
	return head;
}

singleList DeleteSingleNode(singleList head)//ɾ�����
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
	printf("������Ҫɾ��������������");
	scanf("%d", &index);
	getchar();//�س�
	p1 = head;
	p2 = p1;
	while (index != p1->index && p1->next != NULL) {
		p2 = p1;
		p1 = p1->next;
	}
	if (index == p1->index) {
		if (p1 == head)head = p1->next;
		else p2->next = p1->next;
		printf("ɾ���ɹ���");
		do {
			p1->index--;
			p1 = p1->next;
		} while (p1 != NULL);
		printf("���س����أ�");
		getchar();
		return head;
	}
	else printf("����δ���ҵ���");
	return head;
}

doubleList DeleteDoubleNode(doubleList head)//ɾ�����
{
	doubleList p1, p2;
	int index;
	if (head == NULL) {//��δ��������
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
	printf("������Ҫɾ��������������");
	scanf("%d", &index);
	getchar();//�س�
	p1 = head;
	p2 = p1;
	while (index != p1->index && p1->next != NULL) {//�ҵ�ɾ�����
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
			p1->next->front = p2;//p2   p1   p1->next   //ɾ��p1
		}
		printf("ɾ���ɹ���");
		do {
			p1->index--;
			p1 = p1->next;
		} while (p1 != NULL);
		printf("���س����أ�");
		getchar();
		return head;
	}
	else printf("����δ���ҵ���");
	return head;
}