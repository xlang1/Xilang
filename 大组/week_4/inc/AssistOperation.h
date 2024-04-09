#ifndef ASSIST
#define ASSIST


int IsEmptyLinkQueue(LinkQueue* q);//判断是否为空
BSTNodePtr DeLLinkQueue(LinkQueue* q, BSTNodePtr BST);//出队
void EnLinkQueue(LinkQueue* q, BSTNodePtr Node);//入队
void InitQueue(LinkQueue* q);//初始化队列

#endif
