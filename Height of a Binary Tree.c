#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int height(struct Node* root) {
    if (root == NULL)
        return 0;

    int left = height(root->left);
    int right = height(root->right);

    if (left > right)
        return left + 1;
    else
        return right + 1;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);

    if(arr[0] == -1){
        printf("0");
        return 0;
    }

    struct Node* nodes[n];

    for(int i=0;i<n;i++){
        if(arr[i] != -1)
            nodes[i] = createNode(arr[i]);
        else
            nodes[i] = NULL;
    }

    for(int i=0;i<n;i++){
        if(nodes[i] != NULL){
            int leftIndex = 2*i + 1;
            int rightIndex = 2*i + 2;

            if(leftIndex < n)
                nodes[i]->left = nodes[leftIndex];

            if(rightIndex < n)
                nodes[i]->right = nodes[rightIndex];
        }
    }

    printf("%d", height(nodes[0]));

    return 0;
}