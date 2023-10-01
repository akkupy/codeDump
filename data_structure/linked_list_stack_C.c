// author-akshat khatri
// date-12-08-2023
// stack implementation using linked list

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct list_node
{
    int data;
    struct list_node *next;
};

struct list_node *newnode(int data)
{
    struct list_node *stack_node = (struct list_node *)malloc(sizeof(struct list_node));
    stack_node->data = data;
    stack_node->next = NULL;
    return stack_node;
}

int is_empty(struct list_node *root)
{
    if (root == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(struct list_node **root, int data)
{

    struct list_node *stack_node = newnode(data);

    stack_node->next = *root;
    *root = stack_node;

    printf("element %d pushed to stack", data);
}

void pop(struct list_node **root)
{
    if (is_empty(*root))
        
    {
        printf("severe underflow condition\n");
        return;
    }
    struct list_node *temp = *root;
    *root = (*root)->next;

    printf("element popped out is %d\n", temp->data);
    free(temp);
    return;
}

void peek(struct list_node *root)
{
    if (is_empty(root))
    {
        printf("severe underflow condition\n");
        return;
    }
    printf("element peeked out was %d\n", root->data);
}

void display_stack(struct list_node *root)
{
    if (is_empty(root))
    {
        printf("stack is empty\n");
    }
    else
    {
        struct list_node *temp = root;

        while (temp->next != NULL)
        {
            printf("|%d|\n", temp->data);
            temp = temp->next;
        }
        printf("|%d|",temp->data);
    }
}

int main()
{
    struct list_node *root = NULL;
    int choice, element;

    do
    {
        printf("\npress 1 for pushing an element in the stack\npress 2 for popping an element from the stack\npress 3 for peeking an element from the stack\npress 4 to display the stack\n press 0 to exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("enter the element you want to push in the stack\n");
            scanf("%d", &element);

            push(&root, element);
            break;

        case 2:
            pop(&root);
            break;

        case 3:
            peek(root);
            break;

        case 4:
            display_stack(root);
        }

    } while (choice != 0);

    printf("exited program succesfully\n");

    return 0;
}
/**
 * *hello world
 * !the method is good
 * ? is this useful
 * TODO je
 *
 */
/**
 * !the unthinkable 
 * *oh really
 * ?yes really?
 * *done
*/


