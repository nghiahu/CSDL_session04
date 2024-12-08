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

Node* deleteLast(Node* head) {
    if (head == NULL) {
        printf("Danh sách rong, không the xóa.\n");
        return NULL;
    }

    if (head->next == NULL) {
        free(head);
        return NULL;
    }

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->prev->next = NULL;
    free(temp);

    return head;
}

// Hàm chính
int main() {
    Node* head = NULL;

    head = append(head, 1);
    head = append(head, 3);
    head = append(head, 5);
    head = append(head, 7);

    printf("Danh sách ban dau:\n");
    printList(head);

    printf("Xóa phan tu cuoi cùng:\n");
    head = deleteLast(head);
    printList(head);

    Node* head2 = NULL;
    head2 = append(head2, 10);

    printf("\nDanh sách moi:\n");
    printList(head2);

    printf("Xóa phan tu cuoi cùng:\n");
    head2 = deleteLast(head2);
    printList(head2);

    return 0;
}

