#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

// Structure to represent a stack
typedef struct {
    int top;
    char items[MAX_SIZE];
} Stack;

// Function to initialize an empty stack
void initialize(Stack *stack) {
    stack->top = -1;
}

// Function to check if the stack is empty
int isEmpty(Stack *stack) {
    return stack->top == -1;
}

// Function to check if the stack is full
int isFull(Stack *stack) {
    return stack->top == MAX_SIZE - 1;
}

// Function to push an item onto the stack
void push(Stack *stack, char item) {
    if (isFull(stack)) {
        printf("Stack overflow\n");
        exit(EXIT_FAILURE);
    }
    stack->items[++stack->top] = item;
}

// Function to pop an item from the stack
char pop(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow\n");
        exit(EXIT_FAILURE);
    }
    return stack->items[stack->top--];
}

// Function to get the top item from the stack without popping it
char peek(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow\n");
        exit(EXIT_FAILURE);
    }
    return stack->items[stack->top];
}

// Function to determine the precedence of operators
int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

// Function to check if a character is an operator
int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

// Function to convert infix expression to postfix expression
void infixToPostfix(char infix[], char postfix[]) {
    Stack stack;
    initialize(&stack);
    int i, j;
    char ch, x;

    for (i = j = 0; infix[i] != '\0'; i++) {
        ch = infix[i];
        if (isalnum(ch))
            postfix[j++] = ch;
        else if (ch == '(')
            push(&stack, ch);
        else if (ch == ')') {
            while (peek(&stack) != '(')
                postfix[j++] = pop(&stack);
            pop(&stack); // Discard '(' from the stack
        } else {
            while (!isEmpty(&stack) && precedence(ch) <= precedence(peek(&stack)))
                postfix[j++] = pop(&stack);
            push(&stack, ch);
        }
    }

    // Pop any remaining operators from the stack
    while (!isEmpty(&stack))
        postfix[j++] = pop(&stack);

    postfix[j] = '\0'; // Null-terminate the postfix expression
}

// Function to convert infix expression to prefix expression
void infixToPrefix(char infix[], char prefix[]) {
    // Reverse the infix expression
    strrev(infix);

    // Convert reversed infix to reversed postfix
    char reversedPostfix[MAX_SIZE];
    infixToPostfix(infix, reversedPostfix);

    // Reverse the postfix expression to get the prefix expression
    strrev(reversedPostfix);
    strcpy(prefix, reversedPostfix);
}

int main() {
    char infix[MAX_SIZE], postfix[MAX_SIZE], prefix[MAX_SIZE];

    // Input infix expression
    printf("Enter infix expression: ");
    gets(infix);

    // Convert infix to postfix
    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);

    // Convert infix to prefix
    infixToPrefix(infix, prefix);
    printf("Prefix expression: %s\n", prefix);

    return 0;
}
