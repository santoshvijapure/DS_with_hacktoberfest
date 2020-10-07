#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void insert(struct Node **head, struct Node **rear)
{

    int data;
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));

    printf("Enter the element to be inserted: ");
    scanf("%d", &data);
    temp->data = data;
    temp->next = NULL;

    if ((*head) == NULL)
    {
        (*head) = (*rear) = temp;
    }
    else
    {
        (*rear)->next = temp;
        (*rear) = temp;
    }
}

void delete (struct Node **head)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));

    //Check Underflow
    if ((*head) == NULL)
    {
        printf("Error! Queue is empty");
    }
    else
    {
        temp = (*head);
        (*head) = (*head)->next;
        printf("Deleted element: %d", temp->data);
        temp->next = NULL;
        free(temp);
    }
}

void traverse(struct Node *head)
{
    struct Node *temp = head;
    printf("The list is: ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(void)
{
    int ch;
    struct Node *head = NULL;
    struct Node *rear = NULL;

    while (1)
    {
        printf("\n\n1.EnQueue\n2.DeQueue\n3.Traverse\n4.Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            insert(&head, &rear);
            break;
        case 2:
            delete (&head);
            break;
        case 3:
            traverse(head);
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("\nError! Invalid\n");
        }
    }
}