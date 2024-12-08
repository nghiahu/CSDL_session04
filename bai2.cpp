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
    Node* temp = head;
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

Node* insertAtPosition(Node* head, int data, int position) {
    Node* newNode = createNode(data);
    
    // Tru?ng h?p d?c bi?t: chèn vào d?u danh sách
    if (position == 0) {
        newNode->next = head;
        if (head != NULL) {
            head->prev = newNode;
        }
        return newNode;
    }

    Node* temp = head;
    int currentIndex = 0;

    // Duy?t d?n v? trí chèn ho?c cu?i danh sách
    while (temp != NULL && currentIndex < position - 1) {
        temp = temp->next;
        currentIndex++;
    }

    if (temp == NULL) {
        printf("Loi\n");
        free(newNode); // Gi?i phóng b? nh? nút m?i
        return head;
    }

    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }
    temp->next = newNode;

    return head;
}

// Hàm chính
int main() {
    Node* head = NULL;

    head = append(head, 1);
    head = append(head, 3);
    head = append(head, 5);

    printf("Danh sách ban dau:\n");
    printList(head);

    printf("Chen gia tri 4 vào vi tri 2:\n");
    head = insertAtPosition(head, 4, 2);
    printList(head);

    Node* head2 = NULL;
    head2 = append(head2, 2);
    head2 = append(head2, 4);
    head2 = append(head2, 6);

    printf("\nDanh sách moi:\n");
    printList(head2);

    printf("Thu chèn giá tri 8 vào vi tri 5:\n");
    head2 = insertAtPosition(head2, 8, 5);
    printList(head2);

    return 0;
}

