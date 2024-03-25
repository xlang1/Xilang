#ifndef STRUCT
#define STRUCT


typedef struct LinkStackNode* LinkStackPtr;
typedef struct LinkStackNode
{
	void* data;
	LinkStackPtr next;
}StackNode;

typedef struct LinkStack
{
	int	count;				//ջ��Ԫ�ظ���
	LinkStackPtr top;		//ջ��ָ��
}LinkStack;

#endif 
