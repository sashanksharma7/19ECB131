#include <stdio.h>
#include <stdlib.h>

// Structure for AVL tree node
typedef struct Node {
    int key;
    struct Node *left, *right;
} Node;

// Function to create a new node
Node* create_node(int key) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->key = key;
    node->left = node->right = NULL;
    return node;
}

// Right Rotation (RR) - Fixes left-heavy imbalance
Node* right_rotate(Node* y) {
    Node* x = y->left;
    y->left = x->right;
    x->right = y;
    return x;  // New root after rotation
}

// Left Rotation (LL) - Fixes right-heavy imbalance
Node* left_rotate(Node* x) {
    Node* y = x->right;
    x->right = y->left;
    y->left = x;
    return y;  // New root after rotation
}

// Left-Right Rotation (LR) - Convert to Right Rotation
Node* left_right_rotate(Node* node) {
    node->left = left_rotate(node->left);  // Step 1: Left rotation on left child
    return right_rotate(node);             // Step 2: Right rotation on current node
}

// Right-Left Rotation (RL) - Convert to Left Rotation
Node* right_left_rotate(Node* node) {
    node->right = right_rotate(node->right); // Step 1: Right rotation on right child
    return left_rotate(node);                // Step 2: Left rotation on current node
}

// Example usage
int main() {
    // Case 1: Right Rotation (LL Case)
    Node* root = create_node(30);
    root->left = create_node(20);
    root->left->left = create_node(10);
    
    printf("Before Right Rotation: Root = %d\n", root->key);
    root = right_rotate(root);
    printf("After Right Rotation: Root = %d\n", root->key);

    // Case 2: Left Rotation (RR Case)
    root = create_node(10);
    root->right = create_node(20);
    root->right->right = create_node(30);
    
    printf("\nBefore Left Rotation: Root = %d\n", root->key);
    root = left_rotate(root);
    printf("After Left Rotation: Root = %d\n", root->key);

    // Case 3: Left-Right Rotation (LR Case)
    root = create_node(30);
    root->left = create_node(10);
    root->left->right = create_node(20);
    
    printf("\nBefore Left-Right Rotation: Root = %d\n", root->key);
    root = left_right_rotate(root);
    printf("After Left-Right Rotation: Root = %d\n", root->key);

    // Case 4: Right-Left Rotation (RL Case)
    root = create_node(10);
    root->right = create_node(30);
    root->right->left = create_node(20);
    
    printf("\nBefore Right-Left Rotation: Root = %d\n", root->key);
    root = right_left_rotate(root);
    printf("After Right-Left Rotation: Root = %d\n", root->key);

    return 0;
}

//output 
Before Right Rotation: Root = 30
After Right Rotation: Root = 20

Before Left Rotation: Root = 10
After Left Rotation: Root = 20

Before Left-Right Rotation: Root = 30
After Left-Right Rotation: Root = 20

Before Right-Left Rotation: Root = 10
After Right-Left Rotation: Root = 20

---------------------------------------

if we change the key values
node=25,right=77,left=7

Before Right Rotation: Root = 25
After Right Rotation: Root = 7

Before Left Rotation: Root = 10
After Left Rotation: Root = 20

Before Left-Right Rotation: Root = 30
After Left-Right Rotation: Root = 20

Before Right-Left Rotation: Root = 10
After Right-Left Rotation: Root = 20
