#include <stdio.h>

#define SIZE 1000

int main() {
    int stack[SIZE];
    int top = -1;
    int n, m;

    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        int value;
        scanf("%d", &value);
        stack[++top] = value;
    }

    scanf("%d", &m);

    for(int i = 0; i < m; i++) {
        if(top != -1) {
            top--;
        }
    }

    for(int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }

    return 0;
}