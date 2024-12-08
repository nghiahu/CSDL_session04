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

Node* deleteLast(Node* head) {
    if (head == NULL) {
        printf("Danh s�ch rong, kh�ng the x�a.\n");
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

// H�m ch�nh
int main() {
    Node* head = NULL;

    head = append(head, 1);
    head = append(head, 3);
    head = append(head, 5);
    head = append(head, 7);

    printf("Danh s�ch ban dau:\n");
    printList(head);

    printf("X�a phan tu cuoi c�ng:\n");
    head = deleteLast(head);
    printList(head);

    Node* head2 = NULL;
    head2 = append(head2, 10);

    printf("\nDanh s�ch moi:\n");
    printList(head2);

    printf("X�a phan tu cuoi c�ng:\n");
    head2 = deleteLast(head2);
    printList(head2);

    return 0;
}

