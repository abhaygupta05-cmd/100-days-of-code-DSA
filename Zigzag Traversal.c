#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

struct Node* buildTree(int arr[], int n, int i) {
    struct Node* root = NULL;
    
    if (i < n && arr[i] != -1) {
        root = createNode(arr[i]);
        root->left = buildTree(arr, n, 2 * i + 1);
        root->right = buildTree(arr, n, 2 * i + 2);
    }
    
    return root;
}

void zigzagTraversal(struct Node* root) {
    if (!root) return;

    struct Node* queue[10000];
    int front = 0, rear = 0;

    queue[rear++] = root;
    int leftToRight = 1;

    while (front < rear) {
        int levelSize = rear - front;
        int currentLevel[levelSize];

        for (int i = 0; i < levelSize; i++) {
            struct Node* node = queue[front++];
            
            if (leftToRight) {
                currentLevel[i] = node->data;
            } else {
                currentLevel[levelSize - 1 - i] = node->data;
            }

            if (node->left) queue[rear++] = node->left;
            if (node->right) queue[rear++] = node->right;
        }

        for (int i = 0; i < levelSize; i++) {
            printf("%d ", currentLevel[i]);
        }
        
        leftToRight = !leftToRight;
    }
}

int main() {
    int n;
    if (scanf("%d", &n) != 1 || n <= 0) return 0;

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct Node* root = buildTree(arr, n, 0);

    zigzagTraversal(root);
    printf("\n");

    return 0;
}