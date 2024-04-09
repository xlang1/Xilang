#ifndef STRUCT
#define STRUCT


typedef struct BSTNode* BSTNodePtr;
typedef struct BSTNode
{
	int data;
	BSTNodePtr left;
	BSTNodePtr right;
}BSTNode;


typedef struct QueueNode* QueuePtr;
typedef struct QueueNode
{
	BSTNodePtr data;
	QueuePtr next;
}QueueNode;

typedef struct LinkQueue
{
	//int length;//���г���
	QueuePtr head;//ͷ
	QueuePtr tail;//β
}LinkQueue;

#endif 
