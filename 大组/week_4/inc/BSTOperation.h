#ifndef OPERATION
#define OPERATION

BSTNodePtr CreateBST(BSTNodePtr BST, int data);//创建排序二叉树
int isDataAlreadyExist(BSTNodePtr BST, int data, BSTNodePtr* LastNodePtr);// 判断输入的数据是否存在，没有找到相同的数据，返回最后插入位置
void PreOrderTraverse(BSTNodePtr BST);//先序遍历
void InOrderTraverse(BSTNodePtr BST);//中序遍历
void PostOrderTraverse(BSTNodePtr BST);//后序遍历
void LevelTraverse(BSTNodePtr BST);//层序遍历
BSTNodePtr SearchNode(BSTNodePtr BST, int data);//查找数据
void AddData(BSTNodePtr NewNode, BSTNodePtr* BST);//插入数据（不插入相同的数据）
BSTNodePtr MaxOfBST(BSTNodePtr BST);//树的最右，即最大值
BSTNodePtr MinOfBST(BSTNodePtr BST);//树的最左，即最小值
BSTNodePtr ParentOfNode(BSTNodePtr Node, BSTNodePtr BST);//获取Node节点的父节点
void DeleteNode(BSTNodePtr deleteNode, BSTNodePtr* BST); //删除二叉树中的某一个节点


#endif
