#include <stdio.h>
#include <stdlib.h>
#ifndef _STACK_
#define _STACK_ 
typedef struct stack_t
{
    int size;
    int width;
    int* data;
} STACK;
 
void initStack(STACK* stack, int size);
int pop(STACK* stack);
void push(STACK* stack, int val);
int peek(STACK* stack);
void printStack(STACK* stack);
#endif