#ifndef STACK_H
#define STACK_H

#define STACK_MAX 100

#include "Main.h"

struct Stack {
    int     data[STACK_MAX];
    int     size;
};
typedef struct Stack Stack;

int Stack_Top(Stack *S);
void Stack_Init(Stack *S);
void Stack_Push(Stack *S, int d);
void Stack_Pop(Stack *S);

#endif
