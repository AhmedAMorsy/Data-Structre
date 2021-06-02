#include <iostream>

using namespace std;

struct node
{
    int val;
    node* next;
};
node* top =NULL;
node* createnode()
{
    node* newnode =new node();
    puts("Enter the value you want to add");
    cin>>newnode->val;
    newnode->next=NULL;
    return newnode;
}

node* push(node* stack,node* newnode)
{
    if(stack==NULL)
    {
        stack=newnode;
    }
    else
    {
        newnode->next=stack;
    }
    stack=newnode;
    puts("(1) item is pushed");
    return stack;
}
node* pop (node* stack)
{
    if(stack==NULL)
    {
        puts("The stack is empty");
    }
    else
    {
        cout<<"Item with value "<<stack->val<<" is poped out from the stack"<<endl;
        node*ptr=stack;
        stack=stack->next;
        delete(ptr);
    }
    return stack;
}
void print(node* stack)
{
    if(stack==NULL)
    {
        puts("Stack is empty");
    }
    else
    {
        node*ptr=stack;
        puts("The stack contains : ");
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
    node* Mystack=NULL;
    char c;
    while(true)
    {
        puts("a-push\nb-pop\np-print\ne-exit");
        puts("please enter your choice");
        cin>>c;
        if(c=='a'||c=='A')
        {
            node* newnode=createnode();
            Mystack=push(Mystack,newnode);
        }
        else if(c=='b'||c=='B')
        {
            Mystack=pop(Mystack);
        }
        else if(c=='p'||c=='P')
        {
            print(Mystack);
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
