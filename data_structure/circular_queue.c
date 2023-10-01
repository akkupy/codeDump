#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <time.h>

int queue[5];
int N;
int front = -1, rear = -1;
int item;

void insert(int item)
{
    scanf("%d", &item);
    if ((front == 0 && rear == N - 1) || (front == rear + 1))
    {
        printf("Circular Queue Full\n");
    }

    else
    {

        if (front == -1)
        {
            front = rear = 0;
            queue[rear] = item;
        }

        else if ((rear == N - 1) && (front != 0))
        {
            rear = 0;
            queue[rear] = item;
        }
        else
        {
            rear++;
            queue[rear] = item;
        }
        printf("Inserted : %d \n", item);
    }
    return;
}

void delete()
{
    if (front == -1)
        printf("Circular Queue is underflowed\n");
    else
    {
        int t = queue[front];
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else if (front == N - 1)
            front = 0;
        else
            front++;
        printf("Deleted: %d", t);
    }
    return;
}
/*void display()
{
    if (front == -1)
        printf("Circular Queue Empty\n");
    else
    {
        while (front <= rear)
        {
            printf("%d\t", queue[front]);
            front = (front + 1) % N;
        }
    }

    return;
}
*/
void display()
{
    if (front == -1)
        printf("Q empty");
    else
    {
        if (front <= rear)
        {
            for (int i = 0; i <= front - 1; i++)
            {
                printf("* ");
            }
            for (int i = front; i <= rear; i++)
                printf("%d ", queue[i]);
            for (int i = rear + 1; i < N; i++)
                printf("* ");
        }
        else
        {

            for (int i = 0; i <= rear; i++)
            {
                printf("%d ", queue[i]);
            }
            for (int i = rear + 1; i <= front - 1; i++)
                printf("* ");
            for (int i = front; i < N; i++)
                printf("%d ", queue[i]);
        }
    }
}
int main()
{

    int ch;
    N = 5;
    while (1)
    {
        printf("\nSelect your choice\n1.Insert\n2.Delete\n3.Display\n4.Exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            insert(item);
            break;
        case 2:
            delete ();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(time(0));
        }
    }
    return 0;
}