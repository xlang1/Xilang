#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"
#include "BSTOperation.h"
#include "AssistOperation.h"

//插入数据---用于生成二叉排序树(先序遍历)
BSTNodePtr CreateBST(BSTNodePtr BST, int data)
{
	BSTNodePtr LastNodePtr = NULL;//用于存最后一个结点的地址
	int flag = 0;//用于判断输入的数据是否存在

	flag = isDataAlreadyExist(BST, data, &LastNodePtr);//判断数据是否存在，LastNodePtr会将最后一个结点的地址保存下来(传参值会变，值的地址不变)
	//判断flag的情况
	if (flag == 0)return BST;//数据已存在
	if (flag == 1) {         //数据不存在
		BSTNodePtr NewNodePtr = (BSTNodePtr)malloc(sizeof(BSTNode));//开空间
		NewNodePtr->data = data;//传数据
		NewNodePtr->left = NewNodePtr->right = NULL;
		if (LastNodePtr->data < data)LastNodePtr->right = NewNodePtr;//按照排序二叉树定义插入右边
		else if (LastNodePtr->data > data)LastNodePtr->left = NewNodePtr;//按照排序二叉树定义插入左边
	}
	if (flag == 2) {           //空树
		BSTNodePtr NewNodePtr = (BSTNodePtr)malloc(sizeof(BSTNode));//开空间
		NewNodePtr->data = data;//传数据
		NewNodePtr->left = NewNodePtr->right = NULL;
		BST = NewNodePtr;
	}
	return BST;
}

//1.判断输入的数据是否存在         树     判断数据        2.没有找到相同的数据，返回最后插入位置
//返回值：0  存在；1  不存在；2  空树
int isDataAlreadyExist(BSTNodePtr BST, int data, BSTNodePtr* LastNodePtr)
{
	BSTNodePtr t = BST;//临时用于操作树
	//空树
	if (t == NULL)return 2;
	//非空树
	if (t->data == data)return 0;//存在
	while (1) {                  //死循环遍历找要插入的位置，找到再返回
		if (t->data < data) {
			if (t->right == NULL) {
				(*LastNodePtr) = t;//保存最后一个结点的地址
				return 1;
			}
			t = t->right;
		}
		else {
			if (t->left == NULL) {
				(*LastNodePtr) = t;//保存最后一个结点的地址
				return 1;
			}
			t = t->left;
		}

	}
}

//先序遍历
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

//中序遍历
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

//后序遍历
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

////非递归版本三序遍历
////先序
//void PreOrderTraverse(BSTNodePtr BST)
//{
//	// 仿照一个栈
//	BSTNodePtr stack[100], node;
//	int i = -1;
//	if (BST == NULL) {
//		printf("空树！\n");
//		return;
//	}
//	else {
//		i++;
//		stack[i] = BST; // 将根结点入栈
//		while (i > -1) {
//			//出栈
//			node = stack[i--];
//			printf("%d ", node->data);
//			// 先把右子树放进去，栈是先进后出，所以下面的左子树先出
//			if (node->right != NULL)
//				stack[++i] = node->right;
//			if (node->left != NULL)
//				stack[++i] = node->left;
//		}
//	}
//}
//
////中序
//void InOrderTraverse(BSTNodePtr BST) {
//	BSTNodePtr stack[100], node;//栈和操作结点
//	int i = 0;
//	// 判断树是否为空
//	if (BST == NULL) {
//		printf("空树！\n");
//		return;
//	}
//	node = BST;
//	while (node != NULL || i > 0) {
//		// 将所有的左结点入栈，之后扫描到右结点也会入栈
//		while (node != NULL) {
//			stack[++i] = node;
//			node = node->left;
//		}
//		node = stack[i--];//出栈
//		printf("%d ", node->data);
//		// 扫描右节点
//		node = node->right;
//	}
//
//}
//
////后序法一：
//void PostOrderTraverse(BSTNodePtr BST) {
//
//	BSTNodePtr p = BST;
//	BSTNodePtr stack[100];//栈
//	int num = 0;
//	BSTNodePtr have_visited = NULL;//记录遍历到的子根
//	if (BST == NULL) {
//		printf("空树\n");
//		return;
//	}
//	while (NULL != p || num > 0) {
//		while (NULL != p) { //让左结点入栈
//			stack[num++] = p;
//			p = p->left;
//		}
//		p = stack[num - 1];//出栈
//		if (NULL == p->right || have_visited == p->right) {//判断是否有右节点
//			printf("%d ", p->data);
//			num--;
//			have_visited = p;//记录
//			p = NULL;
//		}
//		else {
//			p = p->right;//有右节点要先让其入栈
//		}
//	}
//}

////后序法二：（把后序当作：根->右->左，最后再反转回来）
//void PostOrderTraverse(BSTNodePtr BST) {
//	BSTNodePtr stack[100], node;
//	int i = 0;
//	int count = 0;
//	char array[100]; // 使用一个数组来保存数据，方便最后数组的反转
//	if (BST == NULL) {
//		printf("空树\n");
//		return;
//	}
//	else {
//		i++;
//		stack[i] = BST; // 将根节点入栈
//		while (i > 0) {
//			node = stack[i--];//出栈
//			array[count++] = node->data; // 将其保存在一个数组当中
//			// 先把右子树放进去，栈是先进去后出，所以下面的左子树先出
//			if (node->left != NULL) {
//				stack[++i] = node->left;  // 入栈
//			}
//			if (node->right != NULL) {
//				stack[++i] = node->right;
//			}
//		}
//	}
//	for (int i = count - 1; i >= 0; i--) {	// 反转数组，输出
//		printf("%d ", array[i]);
//	}
//}

//层序遍历
void LevelTraverse(BSTNodePtr BST)
{
	if (BST == NULL) {
		printf("空树！");
		Sleep(2000);
		return;
	}
	LinkQueue LQ;
	InitQueue(&LQ);
	//根节点入队
	EnLinkQueue(&LQ, BST);
	BSTNodePtr t;
	while (!IsEmptyLinkQueue(&LQ)) {
		t = DeLLinkQueue(&LQ, BST);//头结点出队
		printf("%d ", t->data);
		if (t->left != NULL)
			EnLinkQueue(&LQ, t->left);//左边入队
		if (t->right != NULL)
			EnLinkQueue(&LQ, t->right);//右边入队
	}
	printf("\n回车返回...");
	while (getchar() != '\n');
}

//插入数据（不插入相同的数据）          保存修改后的BST
void AddData(BSTNodePtr NewNode, BSTNodePtr* BST)
{
	//1.空树
	if (*BST == NULL) {
		*BST = NewNode;
		printf("插入完成！");
		Sleep(2000);
		return;
	}
	//2.数据已存在
	if (NewNode->data == (*BST)->data) {
		printf("数据已存在！");
		Sleep(2000);
		return;
	}
	//3.数据不存在
	//		1.新数据大于根数据
	if (NewNode->data > (*BST)->data) {
		if ((*BST)->right == NULL) {//找到插入位置
			(*BST)->right = NewNode;
			printf("插入完成！");
			Sleep(2000);
			return;
		}
		else AddData(NewNode, &(*BST)->right);//递归找NewNode的插入位置
	}
	//		2.新数据小于根数据
	if (NewNode->data < (*BST)->data) {
		if ((*BST)->left == NULL) {//找到插入位置
			(*BST)->left = NewNode;
			printf("插入完成！");
			Sleep(2000);
			return;
		}
		else AddData(NewNode, &(*BST)->left);//递归找NewNode的插入位置
	}
}

//查找结点
BSTNodePtr SearchNode(BSTNodePtr BST, int data)
{
	if (BST == NULL)return BST;//没找到的递归出口
	else if (data < BST->data) {
		return SearchNode(BST->left, data);
	}
	else if (data > BST->data) {
		return SearchNode(BST->right, data);
	}
	else return BST;
}

//树的最左，即最小值
BSTNodePtr MinOfBST(BSTNodePtr BST)
{
	if (BST == NULL)
		return NULL;
	BSTNodePtr pointer = BST;
	while (pointer->left)
		pointer = pointer->left;
	return pointer;
}

//树的最右，即最大值
BSTNodePtr MaxOfBST(BSTNodePtr BST)
{
	if (BST == NULL)//空指针判断
		return NULL;
	BSTNodePtr pointer = BST;
	while (pointer->right)//跳出循环后，pointer指向最后一个右子节点
		pointer = pointer->right;
	return pointer;
}

//获取Node节点的父节点
BSTNodePtr ParentOfNode(BSTNodePtr Node, BSTNodePtr BST)
{
	if (Node == NULL || BST == NULL || BST == Node) //空指针判断，以及BST自身无父节点
		return NULL;
	BSTNodePtr p = BST;
	BSTNodePtr parentNode = p;
	while (p != NULL && p->data != Node->data) {
		parentNode = p;
		if (Node->data > p->data)p = p->right;//大了往右走
		else p = p->left;//小了往左走
	} //每一次循环后parentNode总是p的父节点
	//循环跳出后，要么找到了dataNode，要么p为NULL了（走到底了）
	if (p == NULL) {
		printf("节点dataNode不存在\n");
		return NULL;
	}
	return parentNode;
}

//删除结点                                最后会保留删除后的树
void DeleteNode(BSTNodePtr deleteNode, BSTNodePtr* BST) //删除二叉树中的某一个节点
{
	if (deleteNode == NULL || BST == NULL) {                                  //空指针判断
		return;
	}
	BSTNodePtr parentOfDeleteNode = ParentOfNode(deleteNode, *BST); //被删除节点的父节点
	if (deleteNode != *BST && parentOfDeleteNode == NULL) //删除节点不是BST，parentOfDeleteNode==NULL说明没有找到deleteNode或者树的root节点为NULL,直接结束;
		return;
	if (deleteNode->left == NULL && deleteNode->right == NULL) { //1. 删除节点为叶子节点的情况
		if (*BST == deleteNode) { //删除的节点是根节点
			*BST = NULL;
			return;
		}
		if (parentOfDeleteNode->left == deleteNode)//左边为删除结点
			parentOfDeleteNode->left = NULL;
		if (parentOfDeleteNode->right == deleteNode)//右边为删除结点
			parentOfDeleteNode->right = NULL;
	}
	else if (deleteNode->left == NULL || deleteNode->right == NULL) { //2. 删除节点只有左子树或右子树
		if (*BST == deleteNode) {
			if ((*BST)->left != NULL) //删除结点为根节点，且根节点只有左子树
				(*BST) = (*BST)->left;
			else if ((*BST)->right != NULL)
				(*BST) = (*BST)->right; //删除结点为根节点，且根节点只有右子树
		}
		else if (deleteNode->left != NULL) { //删除节点只有左子树
			if (parentOfDeleteNode->left == deleteNode)      //删除节点是父节点的左结点
				parentOfDeleteNode->left = deleteNode->left; //把父节点的left指向deleteNode的左结点，下面同理
			if (parentOfDeleteNode->right == deleteNode)
				parentOfDeleteNode->right = deleteNode->left;
		}
		else if (deleteNode->right != NULL) {//删除节点只有右子树
			if (parentOfDeleteNode->left == deleteNode)
				parentOfDeleteNode->left = deleteNode->right;
			if (parentOfDeleteNode->right == deleteNode)
				parentOfDeleteNode->right = deleteNode->right;
		}
	}
	else if (deleteNode->left != NULL && deleteNode->right != NULL) { //3. 删除节点有左子树和右子树
		BSTNodePtr replaceNode = MaxOfBST(deleteNode->left);//替代结点，为前驱或后驱结点(相邻两个)，min & max任意一种方法
		BSTNodePtr parentOfReplaceNode = ParentOfNode(replaceNode, *BST); //获取替代节点的父结点
		if (*BST == deleteNode) { //删除结点是根
			parentOfReplaceNode->right = replaceNode->left;//替代结点设置为左子树的最右点时做法
			replaceNode->left = (*BST)->left;
			replaceNode->right = (*BST)->right;
			(*BST) = replaceNode;//将替代结点设为根，替代结点的左结点连上父结点
		}
		else if (parentOfDeleteNode->left == deleteNode) { //删除结点是其父结点的左结点
			parentOfDeleteNode->left = replaceNode; //删除节点的父结点left指向替代结点
			replaceNode->left = deleteNode->left;
			if (parentOfReplaceNode != deleteNode) { //删除结点不是替代结点的父节点
				replaceNode->right = deleteNode->right;//把删除结点的右结点给替代结点
				//替代结点右子树指向删除节点右子树（如果替代结点父结点就是删除结点，deleteNode->right就是该替代结点，造成后面子树丢失；parentOfReplaceNode->right也没有意义）
				parentOfReplaceNode->right = replaceNode->left;
			}
			else if (parentOfReplaceNode == deleteNode)
				replaceNode->right = replaceNode->left;       //deleteNode->right->left; //替代节点的右子树指向了替代节点(这里表示为deleteNode->right)的左子树，看树图很容易理解
		}
		else if (parentOfDeleteNode->right == deleteNode) { //删除节点是父节点的右结点
			parentOfDeleteNode->right = replaceNode; //删除节点的父节点right指向替代结点
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

