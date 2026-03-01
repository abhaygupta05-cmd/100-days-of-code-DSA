#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Node* rotateRight(struct Node* head, int k) {

    if (head == NULL || head->next == NULL || k == 0)
        return head;

    struct Node* temp = head;
    int length = 1;

    while (temp->next != NULL) {
        temp = temp->next;
        length++;
    }

    temp->next = head;

    k = k % length;

    int steps = length - k;

    struct Node* newLast = head;
    for (int i = 1; i < steps; i++) {
        newLast = newLast->next;
    }

    struct Node* newHead = newLast->next;
    newLast->next = NULL;

    return newHead;
}

int main() {

    int n, value, k;
    scanf("%d", &n);

    struct Node *head = NULL, *temp = NULL;

    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        struct Node* newNode = createNode(value);

        if (head == NULL) {
            head = temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    scanf("%d", &k);

    head = rotateRight(head, k);

    temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}