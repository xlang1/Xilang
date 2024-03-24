#ifndef OPERATION
#define OPERATION
#define LEN sizeof(QueueNode)

void InitQueue(LinkQueue* q);//初始化队列
void DestoryLinkQueue(LinkQueue* q);//销毁队列
void ClearLinkQueue(LinkQueue* q);//清空队列
int IsEmptyLinkQueue(LinkQueue* q);//判断是否为空
void GetHeadQueue(LinkQueue* q);//查看队头元素
void LengthLinkQueue(LinkQueue* q);//队列长度
void EnLinkQueue(LinkQueue* q);//入队
void DeLLinkQueue(LinkQueue* q);//出队
void PrintLinkStack(LinkQueue q);//链队的打印




#endif 