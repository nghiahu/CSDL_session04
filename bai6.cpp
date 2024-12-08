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

Node* findAndReplace(Node* head, int oldValue, int newValue) {
    Node* temp = head;
    while (temp != NULL) {
        if (temp->data == oldValue) {
            temp->data = newValue;  
            return head;
        }
        temp = temp->next;
    }
    printf("Không tìm thay %d\n", oldValue);
    return head;  
}

int main() {
    Node* head = NULL;

    head = append(head, 1);
    head = append(head, 2);
    head = append(head, 3);
    head = append(head, 4);

    printf("Danh sách ban d?u:\n");
    printList(head);

    int oldValue = 2, newValue = 10;
    printf("\nGiá tri can thay the: %d\n", oldValue);
    printf("Giá tri moi: %d\n", newValue);
    head = findAndReplace(head, oldValue, newValue);

    // In danh sách sau khi thay th?
    printf("\nDanh sách sau khi thay the:\n");
    printList(head);

    // T?o danh sách không có giá tr? c?n thay th?
    Node* head2 = NULL;
    head2 = append(head2, 5);
    head2 = append(head2, 7);
    head2 = append(head2, 9);

    // In danh sách ban d?u
    printf("\nDanh sách thu hai:\n");
    printList(head2);

    // Tìm và thay th? giá tr? không có trong danh sách
    oldValue = 8;
    newValue = 20;
    printf("\nGiá tri can thay the: %d\n", oldValue);
    printf("Giá tri moi: %d\n", newValue);
    head2 = findAndReplace(head2, oldValue, newValue);

    return 0;
}

