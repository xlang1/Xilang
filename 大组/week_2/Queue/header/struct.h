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
	int length;//队列长度
	QueuePtr head;//头
	QueuePtr tail;//尾
}LinkQueue;
#endif 






