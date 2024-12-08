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

Node* reverseList(Node* head) {
    if (head == NULL) {
        return NULL;
    }

    Node* temp = NULL;
    Node* current = head;

    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    if (temp != NULL) {
        head = temp->prev;
    }

    return head;
}

int main() {
    Node* head = NULL;

    head = append(head, 1);
    head = append(head, 2);
    head = append(head, 3);
    head = append(head, 4);


    printf("Danh sách ban dau:\n");
    printList(head);

    head = reverseList(head);

    printf("Danh sách sau khi dao nguoc:\n");
    printList(head);

    Node* emptyList = NULL;
    printf("\nDanh sách rong:\n");
    printList(emptyList);
    emptyList = reverseList(emptyList);
    printf("Danh sách sau khi dao nguoc:\n");
    printList(emptyList);

    return 0;
}

