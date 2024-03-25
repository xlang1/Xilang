#ifndef STACKOPERATION
#define STACKOPERATION
#define LEN sizeof(StackNode)

void InitLinkStack(LinkStack* s);//初始化链栈
void PushStack(LinkStack* s, void* e);//入栈
void PopStack(LinkStack* s);//出栈
void PrintLinkStack(LinkStack s);//输出所有元素
int IsEmptyStack(LinkStack* L);//判断链栈是否为空
void* GetTopStack(LinkStack* s);//获取链栈的栈顶元素
void ClearStack(LinkStack* s);//清空链栈
void DestroyLinkStack(LinkStack* s);//销毁链表
void GetLength(LinkStack s);//获取链栈长度

#endif