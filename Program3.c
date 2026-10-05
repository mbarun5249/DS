#include <stdio.h>
#define MAX 5
int queue[MAX];
int front = -1;
int rear = -1;

void insert()
{
    int x;

    if (rear == MAX - 1)
    {
        printf("Queue Overflow\n");
    }
    else
    {
        printf("Enter the element: ");
        scanf("%d", &x);

        if (front == -1)
            front = 0;

        rear++;
        queue[rear] = x;

        printf("Element inserted successfully\n");
    }
}

void delete()
{
    if (front == -1 || front > rear)
    {
        printf("Queue Empty\n");
    }
    else
    {
        printf("Deleted element: %d\n", queue[front]);
        front++;
    }
}
void display()
{
    int i;

    if (front == -1 || front > rear)
    {
        printf("Queue Empty\n");
    }
    else
    {
        printf("Queue elements are:\n");

        for (i = front; i <= rear; i++)
        {
            printf("%d ", queue[i]);
        }

        printf("\n");
    }
}

int main()
{
    int choice;

    while (1)
    {
        printf("\n1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                insert();
                break;

            case 2:
                delete();
                break;

            case 3:
                display();
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
