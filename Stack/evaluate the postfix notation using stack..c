#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
struct Stack {
    int top;
    unsigned capacity;
    int* array;
};
struct Stack* createStack(unsigned capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}
int pop(struct Stack* stack) {
    if (!isEmpty(stack)) {
        return stack->array[stack->top--];
    }
    return 0;
}
void push(struct Stack* stack, int value) {
    stack->array[++stack->top] = value;
}
int evaluatePostfix(const char* postfix) {
    struct Stack* stack = createStack(strlen(postfix));
    for (int i = 0; postfix[i]; ++i) {
        if (isdigit(postfix[i])) {
            int num = postfix[i] - '0'; 
            push(stack, num);
        } else {
            int operand2 = pop(stack);
            int operand1 = pop(stack);
            
            switch (postfix[i]) {
                case '+':
                    push(stack, operand1 + operand2);
                    break;
                case '-':
                    push(stack, operand1 - operand2);
                    break;
                case '*':
                    push(stack, operand1 * operand2);
                    break;
                case '/':
                    push(stack, operand1 / operand2);
                    break;
            }
        }
    }
    
    return pop(stack);
}
int main() {
    char postfix[100];
    printf("Enter the postfix expression: ");
    fgets(postfix, sizeof(postfix), stdin);
    int result = evaluatePostfix(postfix);
    printf("Result: %d\n", result);
    return 0;
}
