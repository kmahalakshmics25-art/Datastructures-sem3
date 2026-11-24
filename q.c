
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *front = NULL;
struct Node *rear = NULL;

void enqueue(int value)
{
    struct Node *newnode;

    newnode = (struct Node*)malloc(sizeof(struct Node));

    newnode->data = value;
    newnode->next = NULL;

    if (front == NULL)
    {
        front = rear = newnode;
    }
    else
    {
        rear->next = newnode;
        rear = newnode;
    }

    printf("%d inserted into queue\n", value);
}

void dequeue()
{
    struct Node *temp;

    if (front == NULL)
    {
        printf("Queue is empty\n");
        return;
    }

    temp = front;

    printf("Deleted element: %d\n", front->data);

    front = front->next;

    if (front == NULL)
        rear = NULL;

    free(temp);
}
void display()
{
    struct Node *temp;

    if (front == NULL)
    {
        printf("Queue is empty\n");
        return;
    }

    temp = front;

    printf("Queue: ");

    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

int main()
{
    int choice, value;

    printf("Your Name\t USN \t Date\n");

    while (1)
    {
        printf("\n1. Enqueue");
        printf("\n2. Dequeue");
        printf("\n3. Display");
        printf("\n4. Exit");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter element: ");
                scanf("%d", &value);
                enqueue(value);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
