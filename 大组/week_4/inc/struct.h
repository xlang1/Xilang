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
	//int length;//队列长度
	QueuePtr head;//头
	QueuePtr tail;//尾
}LinkQueue;

#endif 
