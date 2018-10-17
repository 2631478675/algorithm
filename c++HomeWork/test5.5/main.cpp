#include <iostream>
#include "Stack.h"

#define random(x) (rand()%x)

int main() {
    int i = 0;
    pNode pstack = NULL;
    STACK *stack = new STACK(pstack, 0);
    while (i < 20) {
        stack->Push(pstack, random(100));
        i++;
    }
    stack->visit();

    stack->ClearStack();

    stack->visit();

    stack->DestroyStack();
    stack->visit();
    getchar();

    return 0;
}