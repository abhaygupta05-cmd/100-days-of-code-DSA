#include <stdio.h>
#include <string.h>

int heap[100005]; 
int size = 0;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insert(int x) {
    heap[size] = x;
    int curr = size;
    size++;
    while (curr > 0 && heap[(curr - 1) / 2] > heap[curr]) {
        swap(&heap[(curr - 1) / 2], &heap[curr]);
        curr = (curr - 1) / 2;
    }
}

void delete() {
    if (size == 0) {
        printf("-1\n");
        return;
    }
    printf("%d\n", heap[0]);
    heap[0] = heap[size - 1];
    size--;
    
    int curr = 0;
    while (2 * curr + 1 < size) {
        int smallest = 2 * curr + 1;
        int right = 2 * curr + 2;
        if (right < size && heap[right] < heap[smallest]) {
            smallest = right;
        }
        if (heap[curr] <= heap[smallest]) break;
        swap(&heap[curr], &heap[smallest]);
        curr = smallest;
    }
}

int main() {
    int N;
    scanf("%d", &N);
    char op[10];
    while (N--) {
        scanf("%s", op);
        if (strcmp(op, "insert") == 0) {
            int x;
            scanf("%d", &x);
            insert(x);
        } else if (strcmp(op, "delete") == 0) {
            delete();
        } else if (strcmp(op, "peek") == 0) {
            if (size == 0) printf("-1\n");
            else printf("%d\n", heap[0]);
        }
    }
    return 0;
}