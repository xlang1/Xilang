//#define _CRT_SECURE_NO_WARNINGS
//#include "DoubleListDemo.h"
//#include <stdio.h>
//#include <stdlib.h>
//#define LEN sizeof(struct doubleLNode)
//void DDisplayMenu(int n)//Ŀ¼��ʾ
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
//doubleList DCreateEmptyList()//����������
//{
//	doubleList head;
//	head = (doubleList)malloc(LEN);
//	head->next = NULL;
//	printf("���������ɹ���\n");
//	Sleep(2000);
//	return head;
//}
//
//void DPrintData(doubleList head)//��������
//{
//	//int n = 1;//��¼������Ŀ
//	doubleList p = head;
//	system("cls");
//	//û�д�������ʱ��˵��
//	if (head == NULL)
//	{
//		printf("List is NULL!\n");
//		return;
//	}
//	//�����˿������˵��
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
//doubleList DAddData(doubleList head)       //����������
//{
//	doubleList p0 = (doubleList)malloc(LEN);
//	doubleList p1 = head;
//	if (head == NULL) {
//		printf("��δ��������");
//		printf("���س����أ�");
//		getchar();
//		return head;
//	}
//	DDisplayMenu(6);
//	int command;                            //���뷽ʽ��ѡ��ʽ
//	printf("������ָ�1-3����\n");
//	scanf("%d", &command);
//	getchar();                             //�س�
//	if (command == 1 || command == 2 || command == 3) {       //ѡ����Ҫ��������
//		printf("���������ݣ�ֱ�ӻس��˳���:\n");
//		gets(p0->data);
//	}
//	if (head->data[0] == -51) {        //����Ϊ��
//		head = p0;
//		p0->index = 1;
//		p0->next = NULL;
//		printf("����ɹ���");
//		printf("���س����أ�");
//		getchar();
//		return head;
//	}
//	switch (command) {
//	case 1:                                     //ͷ����
//		head = p0;
//		p0->next = p1;
//		p0->index = 1;
//		do {
//			p1->index++;
//			p1 = p1->next;
//		} while (p1 != NULL);
//		printf("����ɹ�!");
//		printf("���س����أ�");
//		getchar();
//		break;
//	case 2:                                     //β����
//		while (p1->next != NULL)p1 = p1->next;  //�ҵ����һ�����
//		p1->next = p0;
//		p0->next = NULL;
//		p0->index = p1->index + 1;
//		printf("����ɹ�!");
//		printf("���س����أ�");
//		getchar();
//		break;
//	case 3:                                      //�м����
//		printData(head);
//		printf("������Ҫ����λ�õ�ǰһ�������������\n");
//		doubleList p2 = p1;
//		scanf("%d", &p0->index);
//		while ((p0->index >= p1->index) && p1->next != NULL) {//�ҵ���һ���
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
//			p0->index++;//�������һ���������
//		}
//		printf("����ɹ�!");
//		printf("���س����أ�");
//		getchar();
//		break;
//	case 4:
//		return head;   //�˳�����
//	default:
//		printf("��������!");
//	}
//	return head;
//}
//
//doubleList DDeleteNode(doubleList head)//ɾ�����
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
//	printf("������Ҫɾ��������������");
//	scanf("%d", &index);
//	getchar();//�س�
//	p1 = head;
//	p2 = p1;
//	while (index != p1->index && p1->next != NULL) {
//		p2 = p1;
//		p1 = p1->next;
//	}
//	if (index == p1->index) {
//		if (p1 == head)head = p1->next;
//		else p2->next = p1->next;
//		printf("ɾ���ɹ���");
//		do {
//			p1->index--;
//			p1 = p1->next;
//		} while (p1 != NULL);
//		printf("���س����أ�");
//		getchar();
//		return head;
//	}
//	else printf("����δ���ҵ���");
//	return head;
//}
//
//void DSeekData(doubleList head) //�������ݣ��ؼ���ʽ���ң���ENGLISH������ؼ���LISHҲ�����ҳ�
//{
//	char str[30] = "";
//	int i, j;
//	doubleList p;
//	if (head == NULL) {
//		printf("List is NULL!\n");
//		return 0;
//	}
//	printf("������Ҫ�ҵ����ݣ�");
//	scanf("%s", str);
//	getchar();//�س�
//	p = head;
//	while (p != NULL) {      //��������
//		for (j = 0, i = 0; p->data[j] != '\0' && *(str + i) != '\0'; j++) {    //�ȶ�����
//			if (p->data[j] != *(str + i)) {
//				i = 0;
//				continue;     //û����������������
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
//	printf("û���ҵ������ݣ�");
//}
//
//void DDestroyList(doubleList head)//��������
//{
//	doubleList p;
//	while (head->next != NULL)
//	{
//		p = head->next;
//		head->next = p->next;
//		free(p);
//	}
//	printf("�����ѱ����٣�");
//	printf("���س����أ�");
//	getchar();
//	return;
//}
//
//void DJudgeLoop(doubleList head)//�ж��Ƿ�ɻ�������ָ�뷨
//{
//	doubleList fastP, slowP;
//	fastP = slowP = head;
//	while (fastP != NULL) {
//		slowP = slowP->next;
//		fastP = fastP->next->next;
//		if (slowP == fastP)printf("�����л���");
//		return;
//	}
//	printf("����û�л���");
//}
//
//void DParitySwap(doubleList head) //��ż�Ի�
//{
//	doubleList p1, p2, p = head;
//	while (p->next != NULL) {
//		p1 = p->next;
//		p2 = p1->next;
//		//����
//		//p->p1->p2
//		p1->next = p;
//		p->next = p2;
//		head = p1;
//		p = p1;//ǰ��
//	}
//
//	printf("��ż��ת�ɹ������س����أ�");
//	getchar();
//}

//int main() {
//	doubleList head = NULL;
//	int command1;//1.��������ָ�2.���Ʋ���ָ��
//	for (;;) {
//		system("cls");
//		DDisplayMenu(13);
//		printf("������ָ�1-11����\n");
//		scanf("%d", &command1);
//		getchar();
//		switch (command1) {
//		case 1:
//			if (head == NULL)head = DCreateEmptyList();//����������
//			else {
//				printf("�Ѵ�������");
//				Sleep(2000);
//			}
//			break;
//		case 2:
//			DPrintData(head);          //���������ӡ������
//			printf("���س����أ�");
//			getchar();
//			break;
//		case 3:
//			system("cls");
//			head = addData(head);     //��������
//			break;
//		case 4:
//			DSeekData(head);
//			printf("���س����أ�");
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
//			printf("���س����أ�");
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
//			printf("����ָ���������������룡");
//		}
//	}
//	return 0;
//}