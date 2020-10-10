#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
} *start = NULL;

void insert_end();
void insert_beg();
void insert_sp();
void del_val();
void del_node();
void search();
void traversal();
int count_n();

int main(void)
{
    start = (struct node *)malloc(sizeof(struct node));
    start->data = 0;
    start->next = NULL;
    int ch;
    while (1)
    {
        printf("\n\n1.Insertion\n2.Traversal\n3.Search\n4.Deletion\n5.Count No. of Nodes\n6.Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            insert_sp();
            break;
        case 2:
            traversal();
            break;
        case 3:
            search();
            break;
        case 4:

            if (start->data == 0)
            {
                printf("\n\n    Error! List is Empty");
            }

            else
            {
                printf("\n1.Delete by Value\n2.Delete by Node Number");
                printf("\nEnter your choice: ");
                scanf("%d", &ch);
                if (ch == 1)
                {
                    del_val();
                }
                else if (ch == 2)
                {
                    del_node();
                }
                else
                    printf("\nError! Invalid\n");
            }

            break;
        case 5:
            count_n();
            break;
        case 6:
            exit(0);
            break;
        default:
            printf("\nError! Invalid\n");
        }
    }
}
void insert_sp()
{
    int pos, value;
    struct node *ptr;
    struct node *save;
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    printf("\n\tEnter position:\t");
    scanf("%d", &pos);
    if ((start->next == NULL && pos > 1) || (start->next != NULL && pos > (start->data) + 1))
    {
        printf("\t\nInvalid Position!");
    }
    else
    {
        printf("\tEnter data:\t");
        scanf("%d", &value);
        newnode->data = value;
        if (start->next == NULL && pos == 1)
        {
            start->next = newnode;
            newnode->next = NULL;
            (start->data)++;
        }
        else
        {
            if (pos == 1)
            {
                newnode->next = start->next;
                start->next = newnode;
                (start->data)++;
            }

            else
            {
                ptr = start->next;
                for (int i = 1; i < pos - 1; i++)
                {
                    ptr = ptr->next;
                }
                newnode->next = ptr->next;
                ptr->next = newnode;
                (start->data)++;
            }
        }
    }
}

/*void insert_beg()
{
    struct node *ptr;
    struct node newnode = (struct node)malloc(sizeof(struct node));
    printf("\tEnter data:\t");
    scanf("%d",&(newnode->data));

    if(start==NULL)
    {
        start=(struct node*)malloc(sizeof(struct node));
        start->next=newnode;
        start->data=1;
        newnode->next=NULL;
    }
    else
    {
        ptr=start;
        ptr->next=newnode;
        newnode->next=start->next;
        start->data++;
    }
    count_n();
}
void insert_end()
{
    struct node *ptr;
    struct node newnode = (struct node)malloc(sizeof(struct node));
    printf("\tEnter data:\t");
    scanf("%d",&(newnode->data));
    newnode->next=NULL;
    if(start==NULL)
    {
        start=(struct node*)malloc(sizeof(struct node));
        start->next=newnode;
        start->data=1;
    }
    else
    {
        for(ptr=start;ptr->next!=NULL;ptr=ptr->next);
        ptr->next=newnode;
        start->data++;
    }
    count_n();
}*/
void traversal()
{
    if (start->data == 0)
        printf("list empty");
    else
        printf("\n\n");
    struct node *ptr;
    ptr = start->next;
    while (ptr != NULL)
    {
        printf("\t %d", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}
void del_node()
{
    int num;
    int check = 0;
    printf("\n\tEnter Node number to be deleted:\t");
    scanf("%d", &num);
    if (start->data < num)
    {
        printf("\n\tInvalid node number");
    }
    else
    {
        struct node *ptr, *save;
        if (num == 1)
        {
            save = start, ptr = start->next;
            save->next = ptr->next;
        }
        else
        {
            for (save = start, ptr = save->next; ptr != NULL && check < num - 1; save = ptr, ptr = ptr->next, check++)
                ;
            save->next = ptr->next;
        }
        start->data--;
        printf("\n\tNo. of nodes after deletion : %d", start->data);
        free(ptr);
    }
}
void del_val()
{
    int val;
    printf("\n\tEnter value to be deleted:\t");
    scanf("%d", &val);
    struct node *Loc, *LocP;
    Loc = NULL;
    LocP = NULL;
    //To find location of Element
    if (start->next == NULL)
    {
        Loc = NULL;
        LocP = NULL;
    }
    else if (start->next->data == val)
    {
        LocP = NULL;
        Loc = start->next;
    }
    else
    {
        struct node *ptr;
        struct node *save;
        for (save = start, ptr = start->next; ptr != NULL; save = ptr, ptr = ptr->next)
        {
            if (ptr->data == val)
            {
                LocP = save;
                Loc = ptr;
            }
        }
    }
    //Deletion
    if (Loc == NULL)
    {
        printf("\n\tItem not in List");
    }
    else if (LocP == NULL)
    {
        start->data--;
        start->next = start->next->next;
    }
    else
    {
        LocP->next = Loc->next;
        start->data--;
    }
    printf("\n\tNo. of nodes after deletion : %d", start->data);
    free(Loc);
}
void search()
{
    int item, count = 1;
    int check = 0;
    struct node *temp = start->next;
    if (temp == NULL)
    {
        printf("\n\tError! List Empty");
    }
    else
    {
        count_n();
        printf("\n\tEnter the element to be searched:\t");
        scanf("%d", &item);
        while (temp != NULL)
        {
            if (item == temp->data)
            {
                printf("\nThe element is found at position: ");
                printf("%d", count);
                check++;
            }
            count++;
            temp = temp->next;
        }
        if (check == 0)
            printf("\nItem not in list");
        printf("\n");
    }
}
int count_n()
{
    if (start != NULL)
    {
        printf("\n\tNo. of nodes in list : %d", start->data);
        return (start->data);
    }
    else
    {
        printf("\n\tList has no nodes!");
        return 0;
    }
}
