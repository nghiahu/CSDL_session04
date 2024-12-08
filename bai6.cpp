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
        printf("Danh s�ch rong\n");
        return;
    }

    Node* temp = head;
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

Node* findAndReplace(Node* head, int oldValue, int newValue) {
    Node* temp = head;
    while (temp != NULL) {
        if (temp->data == oldValue) {
            temp->data = newValue;  
            return head;
        }
        temp = temp->next;
    }
    printf("Kh�ng t�m thay %d\n", oldValue);
    return head;  
}

int main() {
    Node* head = NULL;

    head = append(head, 1);
    head = append(head, 2);
    head = append(head, 3);
    head = append(head, 4);

    printf("Danh s�ch ban d?u:\n");
    printList(head);

    int oldValue = 2, newValue = 10;
    printf("\nGi� tri can thay the: %d\n", oldValue);
    printf("Gi� tri moi: %d\n", newValue);
    head = findAndReplace(head, oldValue, newValue);

    // In danh s�ch sau khi thay th?
    printf("\nDanh s�ch sau khi thay the:\n");
    printList(head);

    // T?o danh s�ch kh�ng c� gi� tr? c?n thay th?
    Node* head2 = NULL;
    head2 = append(head2, 5);
    head2 = append(head2, 7);
    head2 = append(head2, 9);

    // In danh s�ch ban d?u
    printf("\nDanh s�ch thu hai:\n");
    printList(head2);

    // T�m v� thay th? gi� tr? kh�ng c� trong danh s�ch
    oldValue = 8;
    newValue = 20;
    printf("\nGi� tri can thay the: %d\n", oldValue);
    printf("Gi� tri moi: %d\n", newValue);
    head2 = findAndReplace(head2, oldValue, newValue);

    return 0;
}

