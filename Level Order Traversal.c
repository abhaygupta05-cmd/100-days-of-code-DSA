#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* createNode(int val) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    if (!root) {
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    }

    int** result = (int**)malloc(2000 * sizeof(int*));
    *returnColumnSizes = (int*)malloc(2000 * sizeof(int));
    *returnSize = 0;

    struct TreeNode** queue = (struct TreeNode**)malloc(2000 * sizeof(struct TreeNode*));
    int head = 0; 
    int tail = 0;

    queue[tail++] = root;

    while (head < tail) {
        int levelSize = tail - head;
        
        result[*returnSize] = (int*)malloc(levelSize * sizeof(int));
        (*returnColumnSizes)[*returnSize] = levelSize;

        for (int i = 0; i < levelSize; i++) {
            struct TreeNode* node = queue[head++];
            result[*returnSize][i] = node->val;

            if (node->left) queue[tail++] = node->left;
            if (node->right) queue[tail++] = node->right;
        }
        
        (*returnSize)++;
    }

    free(queue);
    return result;
}

int main() {
    struct TreeNode* root = createNode(3);
    root->left = createNode(9);
    root->right = createNode(20);
    root->right->left = createNode(15);
    root->right->right = createNode(7);

    int returnSize;
    int* returnColumnSizes;

    int** result = levelOrder(root, &returnSize, &returnColumnSizes);

    printf("[");
    for (int i = 0; i < returnSize; i++) {
        printf("[");
        for (int j = 0; j < returnColumnSizes[i]; j++) {
            printf("%d", result[i][j]);
            if (j < returnColumnSizes[i] - 1) {
                printf(",");
            }
        }
        printf("]");
        if (i < returnSize - 1) {
            printf(",");
        }
    }
    printf("]\n");

    for (int i = 0; i < returnSize; i++) {
        free(result[i]);
    }
    free(result);
    free(returnColumnSizes);

    return 0;
}