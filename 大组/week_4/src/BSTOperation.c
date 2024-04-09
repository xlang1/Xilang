#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"
#include "BSTOperation.h"
#include "AssistOperation.h"

//��������---�������ɶ���������(�������)
BSTNodePtr CreateBST(BSTNodePtr BST, int data)
{
	BSTNodePtr LastNodePtr = NULL;//���ڴ����һ�����ĵ�ַ
	int flag = 0;//�����ж�����������Ƿ����

	flag = isDataAlreadyExist(BST, data, &LastNodePtr);//�ж������Ƿ���ڣ�LastNodePtr�Ὣ���һ�����ĵ�ַ��������(����ֵ��䣬ֵ�ĵ�ַ����)
	//�ж�flag�����
	if (flag == 0)return BST;//�����Ѵ���
	if (flag == 1) {         //���ݲ�����
		BSTNodePtr NewNodePtr = (BSTNodePtr)malloc(sizeof(BSTNode));//���ռ�
		NewNodePtr->data = data;//������
		NewNodePtr->left = NewNodePtr->right = NULL;
		if (LastNodePtr->data < data)LastNodePtr->right = NewNodePtr;//���������������������ұ�
		else if (LastNodePtr->data > data)LastNodePtr->left = NewNodePtr;//�����������������������
	}
	if (flag == 2) {           //����
		BSTNodePtr NewNodePtr = (BSTNodePtr)malloc(sizeof(BSTNode));//���ռ�
		NewNodePtr->data = data;//������
		NewNodePtr->left = NewNodePtr->right = NULL;
		BST = NewNodePtr;
	}
	return BST;
}

//1.�ж�����������Ƿ����         ��     �ж�����        2.û���ҵ���ͬ�����ݣ�����������λ��
//����ֵ��0  ���ڣ�1  �����ڣ�2  ����
int isDataAlreadyExist(BSTNodePtr BST, int data, BSTNodePtr* LastNodePtr)
{
	BSTNodePtr t = BST;//��ʱ���ڲ�����
	//����
	if (t == NULL)return 2;
	//�ǿ���
	if (t->data == data)return 0;//����
	while (1) {                  //��ѭ��������Ҫ�����λ�ã��ҵ��ٷ���
		if (t->data < data) {
			if (t->right == NULL) {
				(*LastNodePtr) = t;//�������һ�����ĵ�ַ
				return 1;
			}
			t = t->right;
		}
		else {
			if (t->left == NULL) {
				(*LastNodePtr) = t;//�������һ�����ĵ�ַ
				return 1;
			}
			t = t->left;
		}

	}
}

//�������
void PreOrderTraverse(BSTNodePtr BST)
{
	if (BST == NULL) {
		return;
	}
	else {
		printf("%d ", BST->data);
		PreOrderTraverse(BST->left);
		PreOrderTraverse(BST->right);
	}
}

//�������
void InOrderTraverse(BSTNodePtr BST)
{
	if (BST == NULL) {
		return;
	}
	else {
		InOrderTraverse(BST->left);
		printf("%d ", BST->data);
		InOrderTraverse(BST->right);
	}
}

//�������
void PostOrderTraverse(BSTNodePtr BST)
{
	if (BST == NULL) {
		return;
	}
	else {
		PostOrderTraverse(BST->left);
		PostOrderTraverse(BST->right);
		printf("%d ", BST->data);
	}
}

////�ǵݹ�汾�������
////����
//void PreOrderTraverse(BSTNodePtr BST)
//{
//	// ����һ��ջ
//	BSTNodePtr stack[100], node;
//	int i = -1;
//	if (BST == NULL) {
//		printf("������\n");
//		return;
//	}
//	else {
//		i++;
//		stack[i] = BST; // ���������ջ
//		while (i > -1) {
//			//��ջ
//			node = stack[i--];
//			printf("%d ", node->data);
//			// �Ȱ��������Ž�ȥ��ջ���Ƚ����������������������ȳ�
//			if (node->right != NULL)
//				stack[++i] = node->right;
//			if (node->left != NULL)
//				stack[++i] = node->left;
//		}
//	}
//}
//
////����
//void InOrderTraverse(BSTNodePtr BST) {
//	BSTNodePtr stack[100], node;//ջ�Ͳ������
//	int i = 0;
//	// �ж����Ƿ�Ϊ��
//	if (BST == NULL) {
//		printf("������\n");
//		return;
//	}
//	node = BST;
//	while (node != NULL || i > 0) {
//		// �����е�������ջ��֮��ɨ�赽�ҽ��Ҳ����ջ
//		while (node != NULL) {
//			stack[++i] = node;
//			node = node->left;
//		}
//		node = stack[i--];//��ջ
//		printf("%d ", node->data);
//		// ɨ���ҽڵ�
//		node = node->right;
//	}
//
//}
//
////����һ��
//void PostOrderTraverse(BSTNodePtr BST) {
//
//	BSTNodePtr p = BST;
//	BSTNodePtr stack[100];//ջ
//	int num = 0;
//	BSTNodePtr have_visited = NULL;//��¼���������Ӹ�
//	if (BST == NULL) {
//		printf("����\n");
//		return;
//	}
//	while (NULL != p || num > 0) {
//		while (NULL != p) { //��������ջ
//			stack[num++] = p;
//			p = p->left;
//		}
//		p = stack[num - 1];//��ջ
//		if (NULL == p->right || have_visited == p->right) {//�ж��Ƿ����ҽڵ�
//			printf("%d ", p->data);
//			num--;
//			have_visited = p;//��¼
//			p = NULL;
//		}
//		else {
//			p = p->right;//���ҽڵ�Ҫ��������ջ
//		}
//	}
//}

////���򷨶������Ѻ���������->��->������ٷ�ת������
//void PostOrderTraverse(BSTNodePtr BST) {
//	BSTNodePtr stack[100], node;
//	int i = 0;
//	int count = 0;
//	char array[100]; // ʹ��һ���������������ݣ������������ķ�ת
//	if (BST == NULL) {
//		printf("����\n");
//		return;
//	}
//	else {
//		i++;
//		stack[i] = BST; // �����ڵ���ջ
//		while (i > 0) {
//			node = stack[i--];//��ջ
//			array[count++] = node->data; // ���䱣����һ�����鵱��
//			// �Ȱ��������Ž�ȥ��ջ���Ƚ�ȥ���������������������ȳ�
//			if (node->left != NULL) {
//				stack[++i] = node->left;  // ��ջ
//			}
//			if (node->right != NULL) {
//				stack[++i] = node->right;
//			}
//		}
//	}
//	for (int i = count - 1; i >= 0; i--) {	// ��ת���飬���
//		printf("%d ", array[i]);
//	}
//}

//�������
void LevelTraverse(BSTNodePtr BST)
{
	if (BST == NULL) {
		printf("������");
		Sleep(2000);
		return;
	}
	LinkQueue LQ;
	InitQueue(&LQ);
	//���ڵ����
	EnLinkQueue(&LQ, BST);
	BSTNodePtr t;
	while (!IsEmptyLinkQueue(&LQ)) {
		t = DeLLinkQueue(&LQ, BST);//ͷ������
		printf("%d ", t->data);
		if (t->left != NULL)
			EnLinkQueue(&LQ, t->left);//������
		if (t->right != NULL)
			EnLinkQueue(&LQ, t->right);//�ұ����
	}
	printf("\n�س�����...");
	while (getchar() != '\n');
}

//�������ݣ���������ͬ�����ݣ�          �����޸ĺ��BST
void AddData(BSTNodePtr NewNode, BSTNodePtr* BST)
{
	//1.����
	if (*BST == NULL) {
		*BST = NewNode;
		printf("������ɣ�");
		Sleep(2000);
		return;
	}
	//2.�����Ѵ���
	if (NewNode->data == (*BST)->data) {
		printf("�����Ѵ��ڣ�");
		Sleep(2000);
		return;
	}
	//3.���ݲ�����
	//		1.�����ݴ��ڸ�����
	if (NewNode->data > (*BST)->data) {
		if ((*BST)->right == NULL) {//�ҵ�����λ��
			(*BST)->right = NewNode;
			printf("������ɣ�");
			Sleep(2000);
			return;
		}
		else AddData(NewNode, &(*BST)->right);//�ݹ���NewNode�Ĳ���λ��
	}
	//		2.������С�ڸ�����
	if (NewNode->data < (*BST)->data) {
		if ((*BST)->left == NULL) {//�ҵ�����λ��
			(*BST)->left = NewNode;
			printf("������ɣ�");
			Sleep(2000);
			return;
		}
		else AddData(NewNode, &(*BST)->left);//�ݹ���NewNode�Ĳ���λ��
	}
}

//���ҽ��
BSTNodePtr SearchNode(BSTNodePtr BST, int data)
{
	if (BST == NULL)return BST;//û�ҵ��ĵݹ����
	else if (data < BST->data) {
		return SearchNode(BST->left, data);
	}
	else if (data > BST->data) {
		return SearchNode(BST->right, data);
	}
	else return BST;
}

//�������󣬼���Сֵ
BSTNodePtr MinOfBST(BSTNodePtr BST)
{
	if (BST == NULL)
		return NULL;
	BSTNodePtr pointer = BST;
	while (pointer->left)
		pointer = pointer->left;
	return pointer;
}

//�������ң������ֵ
BSTNodePtr MaxOfBST(BSTNodePtr BST)
{
	if (BST == NULL)//��ָ���ж�
		return NULL;
	BSTNodePtr pointer = BST;
	while (pointer->right)//����ѭ����pointerָ�����һ�����ӽڵ�
		pointer = pointer->right;
	return pointer;
}

//��ȡNode�ڵ�ĸ��ڵ�
BSTNodePtr ParentOfNode(BSTNodePtr Node, BSTNodePtr BST)
{
	if (Node == NULL || BST == NULL || BST == Node) //��ָ���жϣ��Լ�BST�����޸��ڵ�
		return NULL;
	BSTNodePtr p = BST;
	BSTNodePtr parentNode = p;
	while (p != NULL && p->data != Node->data) {
		parentNode = p;
		if (Node->data > p->data)p = p->right;//����������
		else p = p->left;//С��������
	} //ÿһ��ѭ����parentNode����p�ĸ��ڵ�
	//ѭ��������Ҫô�ҵ���dataNode��ҪôpΪNULL�ˣ��ߵ����ˣ�
	if (p == NULL) {
		printf("�ڵ�dataNode������\n");
		return NULL;
	}
	return parentNode;
}

//ɾ�����                                ���ᱣ��ɾ�������
void DeleteNode(BSTNodePtr deleteNode, BSTNodePtr* BST) //ɾ���������е�ĳһ���ڵ�
{
	if (deleteNode == NULL || BST == NULL) {                                  //��ָ���ж�
		return;
	}
	BSTNodePtr parentOfDeleteNode = ParentOfNode(deleteNode, *BST); //��ɾ���ڵ�ĸ��ڵ�
	if (deleteNode != *BST && parentOfDeleteNode == NULL) //ɾ���ڵ㲻��BST��parentOfDeleteNode==NULL˵��û���ҵ�deleteNode��������root�ڵ�ΪNULL,ֱ�ӽ���;
		return;
	if (deleteNode->left == NULL && deleteNode->right == NULL) { //1. ɾ���ڵ�ΪҶ�ӽڵ�����
		if (*BST == deleteNode) { //ɾ���Ľڵ��Ǹ��ڵ�
			*BST = NULL;
			return;
		}
		if (parentOfDeleteNode->left == deleteNode)//���Ϊɾ�����
			parentOfDeleteNode->left = NULL;
		if (parentOfDeleteNode->right == deleteNode)//�ұ�Ϊɾ�����
			parentOfDeleteNode->right = NULL;
	}
	else if (deleteNode->left == NULL || deleteNode->right == NULL) { //2. ɾ���ڵ�ֻ����������������
		if (*BST == deleteNode) {
			if ((*BST)->left != NULL) //ɾ�����Ϊ���ڵ㣬�Ҹ��ڵ�ֻ��������
				(*BST) = (*BST)->left;
			else if ((*BST)->right != NULL)
				(*BST) = (*BST)->right; //ɾ�����Ϊ���ڵ㣬�Ҹ��ڵ�ֻ��������
		}
		else if (deleteNode->left != NULL) { //ɾ���ڵ�ֻ��������
			if (parentOfDeleteNode->left == deleteNode)      //ɾ���ڵ��Ǹ��ڵ������
				parentOfDeleteNode->left = deleteNode->left; //�Ѹ��ڵ��leftָ��deleteNode�����㣬����ͬ��
			if (parentOfDeleteNode->right == deleteNode)
				parentOfDeleteNode->right = deleteNode->left;
		}
		else if (deleteNode->right != NULL) {//ɾ���ڵ�ֻ��������
			if (parentOfDeleteNode->left == deleteNode)
				parentOfDeleteNode->left = deleteNode->right;
			if (parentOfDeleteNode->right == deleteNode)
				parentOfDeleteNode->right = deleteNode->right;
		}
	}
	else if (deleteNode->left != NULL && deleteNode->right != NULL) { //3. ɾ���ڵ�����������������
		BSTNodePtr replaceNode = MaxOfBST(deleteNode->left);//�����㣬Ϊǰ����������(��������)��min & max����һ�ַ���
		BSTNodePtr parentOfReplaceNode = ParentOfNode(replaceNode, *BST); //��ȡ����ڵ�ĸ����
		if (*BST == deleteNode) { //ɾ������Ǹ�
			parentOfReplaceNode->right = replaceNode->left;//����������Ϊ�����������ҵ�ʱ����
			replaceNode->left = (*BST)->left;
			replaceNode->right = (*BST)->right;
			(*BST) = replaceNode;//����������Ϊ������������������ϸ����
		}
		else if (parentOfDeleteNode->left == deleteNode) { //ɾ��������丸��������
			parentOfDeleteNode->left = replaceNode; //ɾ���ڵ�ĸ����leftָ��������
			replaceNode->left = deleteNode->left;
			if (parentOfReplaceNode != deleteNode) { //ɾ����㲻��������ĸ��ڵ�
				replaceNode->right = deleteNode->right;//��ɾ�������ҽ���������
				//������������ָ��ɾ���ڵ�����������������㸸������ɾ����㣬deleteNode->right���Ǹ������㣬��ɺ���������ʧ��parentOfReplaceNode->rightҲû�����壩
				parentOfReplaceNode->right = replaceNode->left;
			}
			else if (parentOfReplaceNode == deleteNode)
				replaceNode->right = replaceNode->left;       //deleteNode->right->left; //����ڵ��������ָ��������ڵ�(�����ʾΪdeleteNode->right)��������������ͼ���������
		}
		else if (parentOfDeleteNode->right == deleteNode) { //ɾ���ڵ��Ǹ��ڵ���ҽ��
			parentOfDeleteNode->right = replaceNode; //ɾ���ڵ�ĸ��ڵ�rightָ��������
			replaceNode->right = deleteNode->right;
			if (parentOfReplaceNode != deleteNode) {
				replaceNode->left = replaceNode->left;
				parentOfReplaceNode->right = replaceNode->left;
			}
			else if (parentOfReplaceNode == deleteNode)
				replaceNode->left = replaceNode->left->left;
		}
	}
	free(deleteNode);
}

