#include <iostream>

using namespace std;

struct node
{
    int val;
    node* next;
};
node* tail=NULL;
node* createnode()
{
    puts("Please enter the value you want to add");
    node* newnode=new node();
    cin>>newnode->val;
    newnode->next=NULL;
    return newnode;
}

node* Enqueue(node* queue)
{
    node* newnode=createnode();
    if(queue==NULL)
    {
        queue=newnode;
        tail=newnode;
    }
    else
    {
        tail->next=newnode;
        tail=tail->next;
    }
    puts("(1) Item is added to the queue");
    return queue;
}
node* Dequeue (node* queue)
{
    if(queue==NULL)
    {
        puts("The queue is empty");
    }
    else
    {
        node* ptr=queue;
        cout<<"Item with value "<<queue->val<<" is removed out from the queue"<<endl;
        queue=queue->next;
        delete(ptr);
    }
    return queue;
}
void print (node*queue)
{
    if(queue==NULL)
    {
        puts("The queue is empty");
    }
    else
    {
        puts("The queue contains : ");
        node*ptr=queue;
        while(ptr!=NULL)
        {
            cout<<ptr->val<<" ";
            ptr=ptr->next;
        }
        puts("");
    }
}
int main()
{
    node* Myqueue=NULL;
    char c;
    while(true)
    {
        puts("a-push\nb-pop\np-print\ne-exit");
        puts("please enter your choice");
        cin>>c;
        if(c=='a'||c=='A')
        {
            Myqueue=Enqueue(Myqueue);
        }
        else if(c=='b'||c=='B')
        {
            Myqueue=Dequeue(Myqueue);
        }
        else if(c=='p'||c=='P')
        {
            print(Myqueue);
        }
        else if(c=='e'||c=='E')
        {
            return 0;
        }
        else
        {
            puts("please enter a valid option");
        }
    }
    return 0;
}
