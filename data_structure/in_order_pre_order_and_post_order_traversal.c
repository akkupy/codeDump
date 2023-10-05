// author: Akshat Khatri
// date: 16-08-2023

#include <stdio.h>
#include <stdlib.h>

// Define a structure for a binary tree node
struct node
{
    int data;
    struct node *left;
    struct node *right;
};

// Function to create a new tree node with the given data
struct node *create_node(int data)
{
    // Allocate memory for the new node
    struct node *ptr = (struct node *)malloc(sizeof(struct node));

    // Check for memory allocation failure
    if (ptr == NULL)
    {
        printf("Memory allocation error\n");
    }

    // Initialize the node's data and pointers
    ptr->data = data;
    ptr->left = NULL;
    ptr->right = NULL;

    return ptr;
}

// Pre-order tree traversal: root -> left -> right
void pre_order(struct node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        pre_order(root->left);
        pre_order(root->right);
    }
}

// Post-order tree traversal: left -> right -> root
void post_order(struct node *root)
{
    if (root != NULL)
    {
        post_order(root->left);
        post_order(root->right);
        printf("%d ", root->data);
    }
}

// In-order tree traversal: left -> root -> right
void in_order(struct node *root)
{
    if (root != NULL)
    {
        in_order(root->left);
        printf("%d ", root->data);
        in_order(root->right);
    }
}

int main()
{
    // Creating nodes for the binary tree
    struct node *root = create_node(5);
    struct node *root_left_child = create_node(10);
    struct node *root_right_child = create_node(20);
    struct node *left1_left_child = create_node(30);
    struct node *left1_right_child = create_node(40);
    struct node *right1_left_child = create_node(50);
    struct node *right1_right_child = create_node(60);

    // Connecting nodes to form the binary tree
    root->left = root_left_child;
    root->right = root_right_child;
    root_left_child->left = left1_left_child;
    root_left_child->right = left1_right_child;
    root_right_child->left = right1_left_child;
    root_right_child->right = right1_right_child;

    // Printing pre-order traversal
    printf("Pre-order traversal is \n");
    pre_order(root);
    printf("\n");

    // Printing post-order traversal
    printf("Post-order traversal is \n");
    post_order(root);
    printf("\n");

    // Printing in-order traversal
    printf("In-order traversal is\n");
    in_order(root);

    return 0;
}
