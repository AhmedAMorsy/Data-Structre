#include <iostream>
using namespace std;

struct node
{
    node *prev;
    int id;
    node *next;
} ;

node* createNode()
{
    node* node1 = new node();
    node1->prev=NULL;
    cout<<"\nEnter the ID:  ";
    cin>>node1->id;
    node1->next=NULL;
    return node1;
}

node* insertnode(node* list,node* newnode)
{
    node* ptr;
    ptr=list;

    if (list==NULL)
    {
        list=newnode;
        cout << "Insert item at first in empty list  \n";
    }
    else if (list -> id>=newnode -> id)
    {
        list->prev=newnode;
        newnode->next=list;
        list=newnode;
        cout << "Insert item at first in none empty list  \n";
    }
    else
    {
        while((ptr->next != NULL)&&(ptr -> id <= newnode -> id)  )
        {
            ptr=ptr->next;
        }

        if ((ptr -> id >= newnode -> id))
        {
            newnode -> next=ptr ;
            newnode->prev=ptr-> prev;
            ptr -> prev->next=newnode;
            ptr -> prev=newnode;
            cout << "Insert item at middle  \n";

        }
        else
        {
            ptr->next=newnode;
            newnode->prev=ptr;
            cout << "Insert item at last  \n";
        }
    }
    return list;
}

node* delnode(node* list,int val)
{
    node* ptr;
    ptr=list;
    if (list==NULL)
    {
        cout << " Empty list \n";
    }
    else if (list -> id == val)
    {
        list = list -> next;
        delete(ptr);
        cout << "Delete first item in none empty list \n";
    }
    else
    {
        while((ptr->next != NULL)&&(ptr -> id < val)  )
        {
            ptr=ptr->next;
        }

        if ((ptr -> next == NULL)&&(ptr -> id == val))
        {
            ptr->prev->next=NULL;
            delete(ptr);
            cout<<"Delete last node";
        }
        else if (ptr -> id == val)
        {

            ptr->prev->next=ptr->next;
            ptr->next->prev=ptr->prev;
            delete(ptr);
            cout << "Delete middle item \n";
        }
        else if (ptr -> next == NULL)
            cout<<"The Item you want delete is not found";
    }
    return list;
}

void PrintList(node* list)
{
    node* ptr;
    ptr=list;
    cout << " \n";
    if (list!=NULL)
    {
        cout << "The List contains : ";
        while(ptr != NULL)
        {
            cout << ptr->id <<" ";
            ptr=ptr->next;
        }
    }
    else
        cout <<"The list is empty...";
    cout << " \n \n";
}


int main()
{

    int val;
    node* MyList=NULL;
    char choice ;

    do{
        cout<<"\na- Add node.\nd- Delete node.\np- Print All.\ne- Exit.\n";
        cout<<"\nEnter Your Choice: ";
        cin>>choice;

        switch(choice)
        {
            case ('a'):
            case ('A'):
            {
                node* newnode=createNode();
                MyList=insertnode(MyList, newnode);
            }
                break;
            case 'd':
            case 'D':
            {
                cout << "Enter value to be delete :";
                cin>>val;
                MyList=delnode(MyList, val);

            }
                break;
            case 'P':
            case 'p':
            {
                PrintList(MyList);
            }
                break;

        }}while(choice!='e');

}
