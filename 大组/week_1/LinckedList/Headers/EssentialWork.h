#ifndef EssentialWork

#define EssentialWork
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include "struct.h"
#include "Menu.h"
#define LEN1 sizeof(singleNode)
#define LEN2 sizeof(doubleNode)


singleList CreateSingleList();
doubleList CreateDoubleList();
void PrintSingleList(singleList head);
void PrintDoubleList(doubleList head);
singleList AddSingleData(singleList head);
doubleList AddDoubleData(doubleList head);
void SeekSingleData(singleList head);
void SeekDoubleData(doubleList head);
void DestroySingleList(singleList head);
void DestroyDouleList(doubleList head);
singleList DeleteSingleNode(singleList head);
doubleList DeleteDoubleNode(doubleList head);




#endif // !EssentialWork

