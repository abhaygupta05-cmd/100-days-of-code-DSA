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

int getLength(struct Node* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

int findIntersection(struct Node* head1, struct Node* head2) {
    int len1 = getLength(head1);
    int len2 = getLength(head2);

    struct Node *ptr1 = head1, *ptr2 = head2;

    int diff = abs(len1 - len2);

    if (len1 > len2) {
        for (int i = 0; i < diff; i++)
            ptr1 = ptr1->next;
    } else {
        for (int i = 0; i < diff; i++)
            ptr2 = ptr2->next;
    }

    while (ptr1 != NULL && ptr2 != NULL) {
        if (ptr1 == ptr2)
            return ptr1->data;

        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    return -1;  
}

int main() {
    int n, m, i, val;

    scanf("%d", &n);

    struct Node *head1 = NULL, *temp = NULL;


    for (i = 0; i < n; i++) {
        scanf("%d", &val);
        struct Node* newNode = createNode(val);

        if (head1 == NULL)
            head1 = temp = newNode;
        else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    scanf("%d", &m);

    struct Node *head2 = NULL;
    temp = NULL;


    for (i = 0; i < m; i++) {
        scanf("%d", &val);
        struct Node* newNode = createNode(val);

        if (head2 == NULL)
            head2 = temp = newNode;
        else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    struct Node* p1 = head1;
    while (p1 != NULL) {
        if (p1->data == 30) {
            temp->next = p1;
            break;
        }
        p1 = p1->next;
    }

    int result = findIntersection(head1, head2);

    if (result == -1)
        printf("No Intersection");
    else
        printf("%d", result);

    return 0;
}