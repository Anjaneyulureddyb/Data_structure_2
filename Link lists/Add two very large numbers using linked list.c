


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void insertNode(struct Node** head, int value) {
    struct Node* newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void displayList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d", current->data);
        current = current->next;
    }
}

struct Node* add(struct Node* num1, struct Node* num2) {
    struct Node* result = NULL;
    int carry = 0;

    while (num1 != NULL || num2 != NULL || carry) {
        int sum = carry;

        if (num1 != NULL) {
            sum += num1->data;
            num1 = num1->next;
        }

        if (num2 != NULL) {
            sum += num2->data;
            num2 = num2->next;
        }

        carry = sum / 10;
        sum %= 10;
        struct Node* newNode = createNode(sum);
        newNode->next = result;
        result = newNode;
    }

    return result;

}

int main() {
    char str1[10000]; 
    char str2[10000];
    struct Node* num1 = NULL;
    struct Node* num2 = NULL;
    printf("Enter the first very very long integer: ");
    scanf("%s", str1);
    printf("Enter the second very very long integer: ");
    scanf("%s", str2);
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    for (int i = len1 - 1; i >= 0; i--) {
        insertNode(&num1, str1[i] - '0');
    }

    for (int i = len2 - 1; i >= 0; i--) {
        insertNode(&num2, str2[i] - '0');
    }
    struct Node* sum = add(num1, num2);
    printf("Sum: ");
    displayList(sum);
    printf("\n");
    return 0;
}
