#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdlib.h>
#include "struct.h"
#include "StackOperation.h"

//初始化链栈
void InitLinkStack(LinkStack* s) {
	//if (s->count >= 0) {
	//	printf("已初始化链栈！");
	//	return;
	//}
	//无数据的头结点
	s->top = (LinkStackPtr)malloc(LEN);
	s->top = NULL;
	s->count = 0;
}

//判断链栈是否为空
int IsEmptyStack(LinkStack* s) {
	//元素数为0则说明链栈为空
	if (s->count <= 0) {
		return 1;
	}
	else {
		return 0;
	}
}

//清空链栈
void ClearStack(LinkStack* s) {
	LinkStackPtr p, q;   //定义临时链栈结点
	p = s->top;
	while (p) {
		q = p;
		p = p->next;   //向下继续
		free(q);   //清理
	}
	s->count = 0;   //计数器归零
}

//销毁链栈
void DestroyLinkStack(LinkStack* s) {
	//清空后恢复未初始化状态
	ClearStack(s);
	s->count = -1;
	s->top = NULL;
	printf("销毁成功！");
	Sleep(2000);
}

//获取链栈的长度
void GetLength(LinkStack s) {
	if (s.count < 0) {
		printf("尚未初始化！");
		Sleep(2000);
		return;
	}
	else {
		printf("链栈长度是%d", s.count);//链栈的长度就是头结点中的计数器数值
		Sleep(2000);
	}
}

//入栈
void PushStack(LinkStack* s, void* e) {
	LinkStackPtr p = (LinkStackPtr)malloc(LEN);
	p->data = e;
	p->next = s->top; //将头结点设为新结点的下一个结点
	s->top = p;		 // 头结点设为新结点
	s->count++;    //计数器加一
	return;
}

//出栈
void PopStack(LinkStack* s) {
	LinkStackPtr p;
	//判断没有初始化开辟和没有结点的情况
	//1.s - p - p->next，2.s - p->next，3.释放p
	p = s->top;
	s->top = p->next;
	free(p);
	s->count--;
}

//获取链栈的栈顶元素
void* GetTopStack(LinkStack* s) {
	//判断栈顶是否为空
	if (IsEmptyStack(s)) {
		return NULL;
	}
	LinkStackPtr p = s->top;
	return p->data;//以字符型进入函数处理，返回void方便使用不同类型
}

////链栈的打印
//void PrintLinkStack(LinkStack s) {
//	if (s.count < 0) {
//		printf("尚未初始化！");
//		Sleep(2000);
//		return;
//	}
//	//判断链栈是否为空
//	if (IsEmptyStack(s)) {
//		printf("链栈为空！\n");
//		Sleep(2000);
//		return;
//	}
//	LinkStackPtr p;
//	int i = 0;		//计数器
//	p = s.top;		//将p设置为头结点
//	printf("以下就是所有数据：\n");
//	while (p) {
//		i++;
//		printf("Data(%d)：%s\n", i, p->data);
//		p = p->next;
//	}
//	Sleep(2000);
//	return;
//}
