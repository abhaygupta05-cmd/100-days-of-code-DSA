#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* front = NULL;
struct Node* rear = NULL;

void enqueue(int x) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = NULL;

    if (rear == NULL) {
        front = rear = temp;
        return;
    }

    rear->next = temp;
    rear = temp;
}

void dequeue() {
    if (front == NULL) {
        printf("-1\n");
        return;
    }

    struct Node* temp = front;
    printf("%d\n", front->data);

    front = front->next;

    if (front == NULL)
        rear = NULL;

    free(temp);
}

int main() {
    int n;
    char operation[10];
    int value;

    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        scanf("%s", operation);

        if(strcmp(operation, "enqueue") == 0) {
            scanf("%d", &value);
            enqueue(value);
        }
        else if(strcmp(operation, "dequeue") == 0) {
            dequeue();
        }
    }

    return 0;
}