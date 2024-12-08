#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

Node* append(Node* head, int data) {
    Node* newNode = createNode(data);
    if (head == NULL) {
        return newNode;
    }

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;

    return head;
}

int countNodes(Node* head) {
    int count = 0;
    Node* temp = head;

    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    return count;
}

void printList(Node* head) {
    if (head == NULL) {
        printf("Danh sách rong\n");
        return;
    }

    Node* temp = head;
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    Node* head = NULL;

    head = append(head, 2);
    head = append(head, 4);
    head = append(head, 6);
    head = append(head, 8);

    printf("Danh sách ban dau:\n");
    printList(head);
    printf("S? ph?n t? trong danh sách: %d\n", countNodes(head));

    Node* emptyList = NULL;
    printf("\nDanh sách rong:\n");
    printList(emptyList);
    printf("So ph?n tu trong danh sách: %d\n", countNodes(emptyList));

    return 0;
}

