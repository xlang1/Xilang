#ifndef STRUCT
#define STRUCT


typedef struct QueueNode* QueuePtr;
typedef struct QueueNode
{
	void* data;
	QueuePtr next;
}QueueNode;

typedef struct LinkQueue
{
	int length;//���г���
	QueuePtr head;//ͷ
	QueuePtr tail;//β
}LinkQueue;
#endif 






