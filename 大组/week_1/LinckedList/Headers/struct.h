#ifndef Struct
#define Struct

typedef struct Single* singleList;
typedef struct Single {
	int index;
	char data[50];
	singleList next;
}singleNode;

typedef struct Double* doubleList;
typedef struct Double {
	int index;
	char data[50];
	doubleList next;
	doubleList front;
}doubleNode;

#endif 