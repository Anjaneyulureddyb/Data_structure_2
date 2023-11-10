#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
struct Stack {
    int top;
    unsigned capacity;
    char* array;
};
struct Stack* createStack(unsigned capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (char*)malloc(stack->capacity * sizeof(char));
    return stack;
}
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}
char peek(struct Stack* stack) {
    return stack->array[stack->top];
}
char pop(struct Stack* stack) {
    if (!isEmpty(stack)) {
        return stack->array[stack->top--];
    }
    return '\0';
}
void push(struct Stack* stack, char op) {
    stack->array[++stack->top] = op;
}
int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}
void infixToPostfix(const char* infix) {
    struct Stack* stack = createStack(strlen(infix));
    for (int i = 0; infix[i]; ++i) {
        if (isalnum(infix[i]))
            printf("%c", infix[i]);
        else if (infix[i] == '(')
            push(stack, infix[i]);
        else if (infix[i] == ')') {
            while (!isEmpty(stack) && peek(stack) != '(')
                printf("%c", pop(stack));
            if (!isEmpty(stack) && peek(stack) != '(')
                printf("Invalid Expression");
            else
                pop(stack);
        } else {
            while (!isEmpty(stack) && precedence(infix[i]) <= precedence(peek(stack)))
                printf("%c", pop(stack));
            push(stack, infix[i]);
        }
    }

    while (!isEmpty(stack))
        printf("%c", pop(stack));
}
int main() {
    char infix[100];
    printf("Enter the infix expression: ");
    fgets(infix, sizeof(infix), stdin);
    printf("Postfix expression: ");
    infixToPostfix(infix);
    return 0;
}
