#ifndef STACKOPERATION
#define STACKOPERATION
#define LEN sizeof(StackNode)

void InitLinkStack(LinkStack* s);//��ʼ����ջ
void PushStack(LinkStack* s, void* e);//��ջ
void PopStack(LinkStack* s);//��ջ
void PrintLinkStack(LinkStack s);//�������Ԫ��
int IsEmptyStack(LinkStack* L);//�ж���ջ�Ƿ�Ϊ��
void* GetTopStack(LinkStack* s);//��ȡ��ջ��ջ��Ԫ��
void ClearStack(LinkStack* s);//�����ջ
void DestroyLinkStack(LinkStack* s);//��������
void GetLength(LinkStack s);//��ȡ��ջ����

#endif