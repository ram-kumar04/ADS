#include <stdio.h>
#include <conio.h>

int MAXSIZE = 8;
int stack[8];
int top = -1;

int isEmpty()
{
    if (top == -1)
        return 1;
    else
        return 0;
}

int isFull()
{
    if (top == MAXSIZE)
        return 1;
    else
        return 0;
}

int pop()
{
    int data;
    if (!isEmpty())
    {
        data = stack[top];
        top--;
        return data;
    }

    else
        printf("Cannot remove data as stack is Empty");
}

int push(int data)
{

    if (!isFull())
    {
        top = top + 1;
        stack[top] = data;
    }
    else
        printf("Cannot add data as stack is full");
}

int peek()
{
    return stack[top];
}

void main()
{

    push(10);
    push(30);
    push(90);
    push(44);
    push(10);
    push(62);
    push(123);
    push(15);
    push(9);
    push(80);

    printf("\nTop most data of the stack: %d\n", peek());

    printf("\nPrinting data of the stack:\n");
    while (!isEmpty())
    {
        int data = pop();
        printf("Data is :%d\n", data);
    }

    printf("Stack full: %s\n",isFull()?"true":"false");
    printf("stack empty:%s\n",isEmpty()?"true":"false");
    printf("top=%d",top);

    getch();
}