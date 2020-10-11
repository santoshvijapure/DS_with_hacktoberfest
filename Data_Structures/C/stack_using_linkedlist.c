#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
void push(struct Node **head)
{

    int data;
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));

    printf("Enter the element to be inserted: ");
    scanf("%d", &data);
    temp->data = data;
    temp->next = NULL;

    temp->next = (*head);
    (*head) = temp;
}

void popp(struct Node **head)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));

    //Check Underflow
    if ((*head) == NULL)
    {
        printf("Error! Underflow. Stack Empty");
    }
    else
    {
        temp = (*head);
        (*head) = (*head)->next;
        temp->next = NULL;
        free(temp);
    }
}

void peep(struct Node *head)
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

    while (1)
    {
        printf("\n\n1.Push\n2.Pop\n3.Traverse\n4.Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            push(&head);
            break;
        case 2:
            popp(&head);
            break;
        case 3:
            peep(head);
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("\nError! Invalid\n");
        }
    }
}