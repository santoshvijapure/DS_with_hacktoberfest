//Menu driven program for Push & Pop operations in a Stack
#include <stdlib.h>

int top = -1;

void Push(int *s, int size, int value)
{
    if (top == size - 1)
    {
        printf("Stack Underflow!\n");
    }

    else
    {
        top = top + 1;
        s[top] = value;
        printf("Element pushed\n");
    }
}

int Pop(int *s, int size)
{
    int temp = -1;
    if (top == -1)
    {
        printf("Stack Underflow!\n");
    }

    else
    {
        temp = s[top];
        top = top - 1;
        printf("Element popped\n");
    }

    return temp;
}

void Display(int *s)
{
    int i;
    if (top == -1)
    {
        puts("stack is empty");
    }

    else
    {
        printf("Elements currently in the stack: ");
        for (i = top; i >= 0; i--)
        {
            printf("%d ", s[i]);
        }

        printf("\n");
    }
}

int main()
{
    int size, ch, value, *s;
    printf("Enter the size of stack: ");
    scanf("%d", &size);
    s = (int *)malloc(sizeof(int) * size);

    do
    {
        printf("\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:

            printf("Enter element to push: ");
            scanf("%d", &value);
            Push(s, size, value);
            break;

        case 2:

            printf("Element deleted is %d", Pop(s, size));
            break;

        case 3:

            Display(s);
            break;

        case 4:

            exit(0);
            break;

        default:
            printf("Enter a valid choice.\n");
        }

    } while (ch <= 3);

    return 0;
}
