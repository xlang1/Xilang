#ifndef OPERATION
#define OPERATION

BSTNodePtr CreateBST(BSTNodePtr BST, int data);//�������������
int isDataAlreadyExist(BSTNodePtr BST, int data, BSTNodePtr* LastNodePtr);// �ж�����������Ƿ���ڣ�û���ҵ���ͬ�����ݣ�����������λ��
void PreOrderTraverse(BSTNodePtr BST);//�������
void InOrderTraverse(BSTNodePtr BST);//�������
void PostOrderTraverse(BSTNodePtr BST);//�������
void LevelTraverse(BSTNodePtr BST);//�������
BSTNodePtr SearchNode(BSTNodePtr BST, int data);//��������
void AddData(BSTNodePtr NewNode, BSTNodePtr* BST);//�������ݣ���������ͬ�����ݣ�
BSTNodePtr MaxOfBST(BSTNodePtr BST);//�������ң������ֵ
BSTNodePtr MinOfBST(BSTNodePtr BST);//�������󣬼���Сֵ
BSTNodePtr ParentOfNode(BSTNodePtr Node, BSTNodePtr BST);//��ȡNode�ڵ�ĸ��ڵ�
void DeleteNode(BSTNodePtr deleteNode, BSTNodePtr* BST); //ɾ���������е�ĳһ���ڵ�


#endif
