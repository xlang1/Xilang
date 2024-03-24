#ifndef STRUCT
#define STRUCT


typedef struct LinkStackNode* LinkStackPtr;
typedef struct LinkStackNode
{
	char data[50];
	LinkStackPtr next;
}StackNode;

typedef struct LinkStack
{
	int	count;				//栈中元素个数
	LinkStackPtr top;		//栈顶指针

}LinkStack;






#endif 
