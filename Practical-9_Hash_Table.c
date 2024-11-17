#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10

int hashFunction(int key) {
    return key % TABLE_SIZE;
}

struct Node {
    int key;
    struct Node* next;
};

struct HashTableChaining {
    struct Node* table[TABLE_SIZE];
};

void initChaining(struct HashTableChaining* ht) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        ht->table[i] = NULL;
    }
}

void insertChaining(struct HashTableChaining* ht, int key) {
    int index = hashFunction(key);
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->next = ht->table[index];
    ht->table[index] = newNode;
}

int searchChaining(struct HashTableChaining* ht, int key) {
    int index = hashFunction(key);
    struct Node* current = ht->table[index];
    while (current) {
        if (current->key == key) return 1;
        current = current->next;
    }
    return 0;
}

void displayChaining(struct HashTableChaining* ht) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("[%d]: ", i);
        struct Node* current = ht->table[i];
        while (current) {
            printf("%d -> ", current->key);
            current = current->next;
        }
        printf("NULL\n");
    }
}

struct HashTableOpenAddressing {
    int table[TABLE_SIZE];
    int occupied[TABLE_SIZE];
};

void initOpenAddressing(struct HashTableOpenAddressing* ht) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        ht->occupied[i] = 0;
    }
}

void insertOpenAddressing(struct HashTableOpenAddressing* ht, int key) {
    int index = hashFunction(key);
    while (ht->occupied[index]) {
        index = (index + 1) % TABLE_SIZE;
    }
    ht->table[index] = key;
    ht->occupied[index] = 1;
}

int searchOpenAddressing(struct HashTableOpenAddressing* ht, int key) {
    int index = hashFunction(key);
    int startIndex = index;
    while (ht->occupied[index]) {
        if (ht->table[index] == key) return 1;
        index = (index + 1) % TABLE_SIZE;
        if (index == startIndex) break;
    }
    return 0;
}

void displayOpenAddressing(struct HashTableOpenAddressing* ht) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (ht->occupied[i]) {
            printf("[%d]: %d\n", i, ht->table[i]);
        } else {
            printf("[%d]: EMPTY\n", i);
        }
    }
}

int main() {
    struct HashTableChaining htChaining;
    struct HashTableOpenAddressing htOpenAddressing;
    int choice1, choice2, key;

    initChaining(&htChaining);
    initOpenAddressing(&htOpenAddressing);

    while (1) {
        printf("\nChoose Collision Resolution Method:\n");
        printf("1. Chaining\n");
        printf("2. Open Addressing\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice1);

        if (choice1 == 3) break;

        switch (choice1) {
            case 1:
                while (1) {
                    printf("\nChaining Operations:\n");
                    printf("1. Insert\n");
                    printf("2. Search\n");
                    printf("3. Display\n");
                    printf("4. Back to Main Menu\n");
                    printf("Enter your choice: ");
                    scanf("%d", &choice2);

                    if (choice2 == 4) break;

                    switch (choice2) {
                        case 1:
                            printf("Enter key to insert: ");
                            scanf("%d", &key);
                            insertChaining(&htChaining, key);
                            break;
                        case 2:
                            printf("Enter key to search: ");
                            scanf("%d", &key);
                            if (searchChaining(&htChaining, key))
                                printf("Key %d found.\n", key);
                            else
                                printf("Key %d not found.\n", key);
                            break;
                        case 3:
                            printf("Hash Table (Chaining):\n");
                            displayChaining(&htChaining);
                            break;
                        default:
                            printf("Invalid choice! Try again.\n");
                    }
                }
                break;

            case 2:
                while (1) {
                    printf("\nOpen Addressing Operations:\n");
                    printf("1. Insert\n");
                    printf("2. Search\n");
                    printf("3. Display\n");
                    printf("4. Back to Main Menu\n");
                    printf("Enter your choice: ");
                    scanf("%d", &choice2);

                    if (choice2 == 4) break;

                    switch (choice2) {
                        case 1:
                            printf("Enter key to insert: ");
                            scanf("%d", &key);
                            insertOpenAddressing(&htOpenAddressing, key);
                            break;
                        case 2:
                            printf("Enter key to search: ");
                            scanf("%d", &key);
                            if (searchOpenAddressing(&htOpenAddressing, key))
                                printf("Key %d found.\n", key);
                            else
                                printf("Key %d not found.\n", key);
                            break;
                        case 3:
                            printf("Hash Table (Open Addressing):\n");
                            displayOpenAddressing(&htOpenAddressing);
                            break;
                        default:
                            printf("Invalid choice! Try again.\n");
                    }
                }
                break;

            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    printf("Program exited successfully.\n");
    return 0;
}