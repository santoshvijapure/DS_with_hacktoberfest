//Queue - Insert at last , Delete at first

#include<iostream>
using namespace std;

class node
{
    public:
            int data;
            node *next;  
};


class Queue
{
    public:
            node *front, *rear;
            Queue()
            {
                front = NULL;
                rear = NULL;
            }
            void insertInQueue(int);
            void deleteInQueue();
            void create(int);
            void display();
};

void Queue::create(int data)
{
    node *temp = new node;
    temp->data = data;
    if(front == NULL || rear == NULL)
    {
        front = temp;
        rear = temp;
        front->next = rear;
    }
    else
    {
        rear->next = temp;
        rear = temp;
    }
}
void Queue::display()
{
    node *trav = front;
    if(front == NULL || rear == NULL)
    {
        cout<<"Queue empty";
    }
    else
    {
        while(trav != rear->next)
        {
            cout<<trav->data;
            trav = trav->next;
        }
    }
}

void Queue::insertInQueue(int data)
{
    create(data);
}

void Queue::deleteInQueue()
{
    if(front == NULL || rear == NULL)
    {
        cout<<"Queue empty";
    }
    else
    {
        node *temp = front;
        front = front->next;
        delete temp;
    }
}


int main()
{
   
    Queue q;
    q.create(1);
    q.insertInQueue(2);
    q.insertInQueue(3);
    q.insertInQueue(4);
    q.display();
    q.deleteInQueue();
    cout<<endl;
    q.display();
    q.deleteInQueue();
    cout<<endl;
    q.display();
    q.deleteInQueue();
    cout<<endl;
    q.display();
    return 0;
}