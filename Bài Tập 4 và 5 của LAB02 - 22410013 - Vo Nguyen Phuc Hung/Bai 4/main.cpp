//////////////////////////////////
// STT: 22410013
// Họ và tên: Võ Nguyễn Phúc Hưng
// Bài 04 - LAB02
/////////////////////////////////

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

using namespace std;

struct Node
{
    char word[100];
    struct Node* next;
};

typedef struct Node* Stack;

bool isEmpty(Stack stack)
{
    return stack == NULL;
}

char* top(Stack stack)
{
    return stack->word;
}

void pop(Stack* stack)
{
    if(!isEmpty(*stack))
    {
        struct Node* p = *stack;
        *stack = (*stack)->next;
        free(p);
    }
}

void push(Stack* stack, char* data)
{
    struct Node* p = (struct Node*)malloc(sizeof(struct Node));
    p->next = NULL;
    strcpy(p->word, data);
    if(stack == NULL)
    {
        *stack = p;
    }
    else
    {
        p->next = *stack;
        *stack = p;
    }
}

void splitWord(Stack* stack, char* data)
{
    char* p = strtok(data, " ");
    while (p != NULL)
    {
        push(stack, p);
        p = strtok(NULL, " ");
    }
}

void showWord(Stack stack)
{
    while (!isEmpty(stack))
    {
        printf("%s ", top(stack));
        pop(&stack);
    }
}

int main()
{
    Stack stack = NULL;
    char input[200];

    puts("Nhap chuoi can dao nguoc: ");
    scanf("%[^\n]", input);

    splitWord(&stack, input);
    showWord(stack);
    puts("\n");

    return 0;
}
