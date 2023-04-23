/*
@File    :   Stack.c
@Time    :   22.04.2023 15:40:37
@Author  :   Karri Korsu
@Version :   1.0
@Contact :   karri.korsu@edu.turkuamk.fi
@Desc    :   None
*/
/*
#include "Rogue.h"
/*
struct Stack* stackCreation()
{
    struct Stack* stack = calloc(1, sizeof(struct Stack));
    stack->top = -1;
    
    return stack;
}


void push(struct Stack *stack, struct Tile tile)
{
    if (isFull(stack))
    {
        printf("\nOverflow!!");
    }
    else
    {
        stack->data[stack->top] = tile;
        stack->top++;
    }
}

void pop(struct Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("\nUnderflow!!");
    }
    else
    {
        stack->top--;
    }
}


//  Returns the top element of the stack    
struct Tile top(struct Stack *stack)
{
    return stack->data[stack->top];
}

//  Returns false if not empty  
bool isEmpty(struct Stack *stack)
{
    int flag = false;
    if (stack->top < 1)
    {
        flag = true;
    }
    return flag;
}
//  Returns false if not full   
bool isFull(struct Stack *stack)
{
    int flag = false;
    if (stack->top == STACKLIMIT)
    {
        flag = true;
    }
    return flag;
}
*/