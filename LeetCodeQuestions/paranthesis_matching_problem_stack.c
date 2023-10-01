// author-akshat khatri
// date-14-08-2023
//  solving paranthesis matching problem using stacks

#include <stdio.h>
#include <stdlib.h>

struct node
{
    char symbol;
    struct node *next;
};

struct node *create_node(char symbol)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL)
    {
        printf("memory error\n");
        exit(EXIT_FAILURE);
    }
    else
    {
        ptr->symbol = symbol;
        return ptr;
    }
}

int is_empty(struct node *stack_node)
{
    if (stack_node == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(struct node **top, char symbol)
{
    struct node *temp = create_node(symbol);

    temp->next = *top;
    *top = temp;
}
void pop(struct node **top)
{
    if (is_empty(*top))
    {
        printf("unbalanced parenthesis\n");
        exit(EXIT_SUCCESS);
    }
    struct node *temp = *top;
    *top = (*top)->next;
    free(temp);
}

int main()
{
    struct node *top = NULL;
    int size;
    printf("enter the size of the expression\n");
    scanf("%d", &size);

    char arr[size + 10];

  
    for (int i = 0; i < size; i++)
    {
        printf("Enter the %dth character: ", i + 1);
        scanf(" %c", &arr[i]);

        if (arr[i] == '(')
        {
            push(&top, '(');
        }
        else if (arr[i] == ')')
        {
            pop(&top);
        }
    }
    if (top == NULL)
    {
        printf("balanced paranthesis\n");
    }
    else
    {
        printf("unbalanced paranthesis\n");
    }
    
    return 0;
}