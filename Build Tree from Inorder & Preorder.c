#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

int findIndex(int inorder[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == value)
            return i;
    }
    return -1;
}

struct Node* buildTree(int preorder[], int inorder[], int preStart, int inStart, int inEnd) {
    if (inStart > inEnd)
        return NULL;

    struct Node* root = createNode(preorder[preStart]);

    int inIndex = findIndex(inorder, inStart, inEnd, root->data);

    int leftSize = inIndex - inStart;

    root->left = buildTree(preorder, inorder, preStart + 1, inStart, inIndex - 1);
    root->right = buildTree(preorder, inorder, preStart + leftSize + 1, inIndex + 1, inEnd);

    return root;
}

void postorder(struct Node* root) {
    if (root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int main() {
    int n;
    scanf("%d", &n);

    int preorder[n], inorder[n];

    for (int i = 0; i < n; i++)
        scanf("%d", &preorder[i]);

    for (int i = 0; i < n; i++)
        scanf("%d", &inorder[i]);

    struct Node* root = buildTree(preorder, inorder, 0, 0, n - 1);

    postorder(root);

    return 0;
}