Implement the MergeSort algorithm to sort the sequence of integers stored in Linkelist.

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* merge(struct Node* left, struct Node* right) {
    struct Node* result = NULL;

    if (left == NULL)
        return right;
    if (right == NULL)
        return left;

    if (left->data <= right->data) {
        result = left;
        result->next = merge(left->next, right);
    } else {
        result = right;
        result->next = merge(left, right->next);
    }

    return result;
}

void split(struct Node* source, struct Node** left, struct Node** right) {
    struct Node* fast;
    struct Node* slow;
    slow = source;
    fast = source->next;

    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    *left = source;
    *right = slow->next;
    slow->next = NULL;
}

void mergeSort(struct Node** headRef) {
    struct Node* head = *headRef;
    struct Node* left;
    struct Node* right;

    if (head == NULL || head->next == NULL) {
        return;
    }

    split(head, &left, &right);

    mergeSort(&left);
    mergeSort(&right);

    *headRef = merge(left, right);
}

void insert(struct Node** headRef, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*headRef == NULL) {
        *headRef = newNode;
    } else {
        struct Node* current = *headRef;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;

    int n, data;
    printf("Enter the number of elements in the linked list: ");
    scanf("%d", &n);

    printf("Enter the unsorted linked list elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        insert(&head, data);
    }

    mergeSort(&head);

    printf("Sorted linked list: ");
    printList(head);

    return 0;
}
