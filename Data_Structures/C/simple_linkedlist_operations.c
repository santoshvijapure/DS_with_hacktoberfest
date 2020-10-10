#include <stdlib.h>
#include <stdio.h>

struct Node
{
    int data;
    struct Node *next;
};

void Insert(struct Node **head)
{
    int data, n;
    struct Node *temp1 = (struct Node *)malloc(sizeof(struct Node));

    printf("Enter the element to be inserted: ");
    scanf("%d", &data);
    printf("Enter the position: ");
    scanf("%d", &n);

    temp1->data = data;
    temp1->next = NULL;
    if (n == 1 || (*head) == NULL)
    {
        temp1->next = (*head);
        (*head) = temp1;
        return;
    }
    else
    {
        struct Node *temp2 = (*head);
        for (int i = 0; i < n - 2; i++)
        {
            temp2 = temp2->next;
        }
        temp1->next = temp2->next;
        temp2->next = temp1;
    }
}

void Delete(struct Node **head)
{
    int i, n, ch;
    struct Node *temp1 = (*head);
    struct Node *temp2 = (*head);
    printf("1.Element wise\t2.Position wise ");
    scanf("%d", &ch);
    if (ch == 1)
    {
        printf("Enter the element to be deleted: ");
        scanf("%d", &n);
        while (temp1 != NULL)
        {
            if (temp1->data == n)
            {
                break;
            }
            temp1 = temp1->next;
        }
        while (temp2 != NULL)
        {
            if (temp2->data == n)
            {
                temp1->next = temp2->next;
                free(temp2);
            }
        }
        // if (n == temp1->data)
        // {
        //     while (temp2 != NULL)
        //     {
        //         temp2 = temp2->next;
        //     }
        //     temp2->next = temp1->next;
        //     free(temp1);
        // }
    }
    else if (ch == 2)
    {
        printf("Enter the position of the element to be deleted: ");
        scanf("%d", &n);
        if (n == 1)
        {
            (*head) = temp1->next;
            free(temp1);
            return;
        }
        for (i = 0; i < n - 2; i++)
        {
            temp1 = temp1->next;
        }
        struct Node *temp2 = temp1->next;
        temp1->next = temp2->next;
        free(temp2);
    }
    else
    {
        printf("Error! Invalid");
    }
}

void Traverse(struct Node *head)
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

void Reverse(struct Node **head)
{
    struct Node *curr, *prev, *next;
    curr = (*head);
    prev = NULL;
    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    (*head) = prev;
}

void Recursive_traverse(struct Node *p)
{
    if (p == NULL)
    {
        return; //Exit condition
    }
    printf("%d ", p->data);      //First print value in the node
    Recursive_traverse(p->next); //Recursive Call
}

void Recursive_reverse_traverse(struct Node *p)
{
    if (p == NULL)
    {
        return;
    }
    Recursive_reverse_traverse(p->next);
    printf("%d ", p->data);
}

// void Recursive_reverse(struct Node *p, struct Node **head)
// {
//     if (p->next == NULL)
//     {
//         (*head) = p;
//         return;
//     }
//     Recursive_reverse_traverse(p->next);
//     struct Node *q = p->next;
//     q->next = p;
//     p->next = NULL;
// }

void Count(struct Node *head)
{
    int sum;
    struct Node *temp = head;
    printf("No. of nodes: ");
    while (temp != NULL)
    {
        sum = sum + 1;
        temp = temp->next;
    }
    printf("%d\n", sum);
}

void Search(struct Node *head)
{
    int item, count = 1;
    struct Node *temp = head;
    if (temp == NULL)
    {
        printf("Error! List Empty");
    }
    else
    {
        printf("Enter the element to be searched: ");
        scanf("%d", &item);
        while (temp != NULL)
        {
            if (item == temp->data)
            {
                printf("The element is found at position: ");
                printf("%d", count);
            }
            count = count + 1;
            temp = temp->next;
        }
        printf("\n");
    }
}

int main(void)
{
    int n, i, x, ele, pos, ch;
    struct Node *head = NULL;

    while (1)
    {
        printf("\n\n1.Insertion\n2.Deletion\n3.Traversal\n4.Reversal\n5.Recursive Traversal\n6.Recursive Reverse Traversal\n8.Count\n9.Search\n10.Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            Insert(&head);
            break;
        case 2:
            Delete(&head);
            break;
        case 3:
            Traverse(head);
            break;
        case 4:
            Reverse(&head);
            break;
        case 5:
            Recursive_traverse(head);
            break;
        case 6:
            Recursive_reverse_traverse(head);
            break;
        // case 7:
        //     Recursive_reverse(head, &head);
        //     break;
        case 8:
            Count(head);
            break;
        case 9:
            Search(head);
            break;
        case 10:
            exit(0);
            break;
        default:
            printf("\nError! Invalid\n");
        }
    }
}