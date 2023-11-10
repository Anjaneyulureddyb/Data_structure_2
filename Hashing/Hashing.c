#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#define TABLE_SIZE 100
typedef struct KeyValue {
    int key;
    int value;
    struct KeyValue* next;
} KeyValue;
typedef struct {
    KeyValue* table[TABLE_SIZE];
} HashTable;
unsigned int hash(int key) {
    return key % TABLE_SIZE;
}
void initialize(HashTable* ht) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        ht->table[i] = NULL;
    }
}
bool insert(HashTable* ht, int key, int value) {
    unsigned int index = hash(key);
    KeyValue* new_pair = (KeyValue*)malloc(sizeof(KeyValue));
    if (new_pair == NULL) {
        return false;
    }
    new_pair->key = key;
    new_pair->value = value;
    new_pair->next = NULL;
    new_pair->next = ht->table[index];
    ht->table[index] = new_pair;
    return true;
}
bool search(HashTable* ht, int key, int* value) {
    unsigned int index = hash(key);
    KeyValue* current = ht->table[index];
    while (current != NULL) {
        if (current->key == key) {
            *value = current->value;
            return true;
        }
        current = current->next;
    }
    return false;
}
bool delete(HashTable* ht, int key) {
    unsigned int index = hash(key);
    KeyValue* current = ht->table[index];
    KeyValue* prev = NULL;
    while (current != NULL) {
        if (current->key == key) {
            if (prev != NULL) {
                prev->next = current->next;
            } else {
                ht->table[index] = current->next;
            }
            free(current);
            return true;
        }
        prev = current;
        current = current->next;
    }
    return false;
}
void printMenu() {
    printf("\nMenu:\n");
    printf("1. Insert Key-Value Pair\n");
    printf("2. Search for Key\n");
    printf("3. Delete Key\n");
    printf("4. Print Hash Table\n");
    printf("5. Get Random Key-Value Pair\n");
    printf("6. Exit\n");
}
void printHashTable(HashTable* ht) {
    printf("Hash Table Contents:\n");
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        KeyValue* current = ht->table[i];
        if (current != NULL)
        {
            printf("Index %d: ", i);
            while (current->next != NULL) {
                printf("(%d, %d) -> ", current->key, current->value);
                current = current->next;
            }
            printf("(%d, %d)\n ", current->key, current->value);
        }
    }
}
int countElements(KeyValue* list) {
    int count = 0;
    KeyValue* current = list;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}
KeyValue* getRandomKeyValuePair(HashTable* ht) {
    int randomIndex = rand() % TABLE_SIZE;
    KeyValue* current = ht->table[randomIndex];
    if (current == NULL) {
        return NULL;
    }
    int count = countElements(current);
    int random = rand() % count;
    while (random > 0) {
        current = current->next;
        random--;
    }
    return current;
}
int main() {
    HashTable ht;
    initialize(&ht);
    srand(time(NULL));
    int choice;
    int key, value;
    bool result;
    do {
        printMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                do {
                    printf("Enter key: ");
                    scanf("%d", &key);
                    printf("Enter value: ");
                    scanf("%d", &value);
                    result = insert(&ht, key, value);
                    if (result) {
                        printf("Key-Value pair inserted successfully.\n");
                    } else {
                        printf("Failed to insert Key-Value pair.\n");
                    }
                    printf("Do you want to insert another key-value pair? (y/n): ");
                    char ch;
                    scanf(" %c", &ch);  // Read a character, ignoring whitespace
                    if (ch != 'y' && ch != 'Y') {
                        break;
                    }
                } while (1); // Continue inserting until the user chooses to exit
                break;
            case 2:
                printf("Enter key to search: ");
                scanf("%d", &key);
                result = search(&ht, key, &value);
                if (result) {
                    printf("Key found, value: %d\n", value);
                } else {
                    printf("Key not found\n");
                }
                break;
            case 3:
                printf("Enter key to delete: ");
                scanf("%d", &key);
                result = delete(&ht, key);
                if (result) {
                    printf("Key deleted successfully.\n");
                } else {
                    printf("Key not found for deletion.\n");
                }
                break;
            case 4:
                printHashTable(&ht);
                break;
            case 5:
{
    int elementsCount = countElements(&ht);
    if (elementsCount > 0) {
        int randomIndex = rand() % elementsCount;
        KeyValue* randomPair = NULL;
        for (int i = 0; i < TABLE_SIZE; i++) {
            KeyValue* current = ht.table[i];
            while (current != NULL) {
                if (randomIndex == 0) {
                    randomPair = current;
                    break;
                }
                current = current->next;
                randomIndex--;
            }
            if (randomPair != NULL) {
                break;
            }
        }
        if (randomPair != NULL) {
            printf("Random Key-Value Pair: (%d, %d)\n", randomPair->key, randomPair->value);
        }
    } else {
        printf("Hash table is empty, cannot get a random pair.\n");
    }
}
break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);
    return 0;
}
