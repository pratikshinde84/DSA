#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void insertAtBeginning(int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = head;
    head = new_node;
    printf("Inserted %d at the beginning\n", new_data);
}

void insertAtEnd(int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = head;
    new_node->data = new_data;
    new_node->next = NULL;
    
    if (head == NULL) {
        head = new_node;
        printf("Inserted %d at the end\n", new_data);
        return;
    }

    while (last->next != NULL) {
        last = last->next;
    }
    last->next = new_node;
    printf("Inserted %d at the end\n", new_data);
}

void insertAtPosition(int pos, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* temp = head;
    new_node->data = new_data;

    if (pos == 1) {
        new_node->next = head;
        head = new_node;
        printf("Inserted %d at position %d\n", new_data, pos);
        return;
    }

    for (int i = 1; temp != NULL && i < pos - 1; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position is out of bounds\n");
        return;
    }

    new_node->next = temp->next;
    temp->next = new_node;
    printf("Inserted %d at position %d\n", new_data, pos);
}

void deleteAtBegin() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = head;
    head = head->next;
    free(temp);
    printf("Node deleted from beginning\n");
}

void deleteAtEnd() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    if (head->next == NULL) {
        free(head);
        head = NULL;
        printf("Node deleted from end\n");
        return;
    }
    struct Node* temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
    printf("Node deleted from end\n");
}

void deleteAtPosition(int position) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    if (position == 0) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
        printf("Node deleted from position 0\n");
        return;
    }
    struct Node* temp = head;
    for (int i = 0; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL) {
        printf("Position is out of bounds\n");
        return;
    }
    struct Node* next = temp->next->next;
    free(temp->next);
    temp->next = next;
    printf("Node deleted from position %d\n", position);
}

void printList() {
    struct Node* node = head;
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

int main() {
    int choice, data, pos;

    while (1) {
        printf("\n1. Insert at beginning\n2. Insert at end\n3. Insert at position\n4. Delete at beginning\n5. Delete at end\n6. Delete at position\n7. Display\n8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                insertAtBeginning(data);
                break;
            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                insertAtEnd(data);
                break;
            case 3:
                printf("Enter data and position: ");
                scanf("%d %d", &data, &pos);
                insertAtPosition(pos, data);
                break;
            case 4:
                deleteAtBegin();
                break;
            case 5:
                deleteAtEnd();
                break;
            case 6:
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                deleteAtPosition(pos);
                break;
            case 7:
                printList();
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}