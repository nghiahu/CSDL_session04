#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node* createList(int n) {
    struct Node *head = NULL, *temp, *last = NULL;
    int value;

    for (int i = 0; i < n; i++) {
        temp = (struct Node*)malloc(sizeof(struct Node));
        if (!temp) {
            exit(1);
        }
        printf("[%d]= : ", i + 1);
        scanf("%d", &value);
        temp->data = value;

        temp->next = NULL;

        if (head == NULL) {
            head = temp;
        } else {
            last->next = temp; 
        }
        last = temp; 
    }
    return head;
}

void printList(struct Node *head) {
    struct Node *temp = head;
    int count = 1;

    while (temp != NULL) {
        printf("%d-->", temp->data);
        temp = temp->next;
    }
      printf("NULL");
}

void freeList(struct Node *head) {
    struct Node *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    Node* head = NULL;
    int n, value;
    printf("Nhap so nut cua danh sach: ");
    scanf("%d", &n);

    if (n <= 0 || n > 1000) {
        return 0;
    }
    head = createList(n);

    printf("Nhap gia tri chen vao dau danh sach: ");
    scanf("%d", &value);
    insertHead(&head, value);
    printList(head);
    freeList(head);
    return 0;
}

