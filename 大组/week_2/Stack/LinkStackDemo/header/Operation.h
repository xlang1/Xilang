#ifndef OPERATION
#define OPERATION
#define LEN sizeof(StackNode)

void InitLinkStack(LinkStack* s);//��ʼ����ջ
void PushStack(LinkStack* s);//��ջ
void PopStack(LinkStack* s);//��ջ
void PrintLinkStack(LinkStack s);//�������Ԫ��
int IsEmptyStack(LinkStack L);//�ж���ջ�Ƿ�Ϊ��
char* GetTopStack(LinkStack L, char e[]);//��ȡ��ջ��ջ��Ԫ��
void ClearStack(LinkStack* s);//�����ջ
void DestroyLinkStack(LinkStack* s);//��������
void GetLength(LinkStack s);//��ȡ��ջ����

#endif

