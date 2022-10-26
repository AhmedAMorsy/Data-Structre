#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
} ;

node* createNode()
{
    node* node1 = new node();
    cout<<"\nEnter the value:  ";
    cin>>node1->data;
    node1->next=NULL;
    return node1;
}

node* insertnode(node* list,node* newnode)
{
    node* ptr1;
    node* ptr2;
    ptr1=NULL;
    ptr2=list;

    if (list==NULL)
    {
        list=newnode;
        cout << "Insert item at first in empty list  \n";
    }
    else if (list->data>=newnode -> data)
    {
        newnode->next=list;
        list=newnode;
        cout << "Insert item at first in none empty list  \n";
    }
    else
    {
        while((ptr2 != NULL)&&(ptr2 -> data <= newnode -> data)  )
        {
            ptr1=ptr2;
            ptr2=ptr2->next;
        }

        if (ptr2 == NULL)
        {
            ptr1->next=newnode;
            cout << "Insert item at last  \n";
        }
        else
        {
            newnode->next=ptr2;
            ptr1->next=newnode;
            cout << "Insert item at middle  \n";
        }
    }
    return list;
}

node* delnode(node* list,int val)
{
    node* ptr1;node* ptr2; ptr1=NULL; ptr2=list;

    if (list==NULL)
    {
        cout << " Empty list \n";
    }
    else if (list -> data == val)
    {
        ptr1 = list ;
        list = list -> next;
        delete(ptr1);
        cout << "Delete first item in none empty list \n";
    }
    else
    {
        while((ptr2 != NULL)&&(ptr2 -> data < val))
        {
            ptr1=ptr2;
            ptr2=ptr2->next;
        }

        if ((ptr2 == NULL)||(ptr2 -> data > val))
        {

            cout << " The Item you want to delete is not found \n";
        }
        else
        {

            ptr1->next=ptr2->next;
            delete(ptr2);

            cout << "Delete middle or last item \n";
        }
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
            cout << " " << ptr->data ;
            ptr=ptr->next;
        }

    }
    else
        cout <<"The list is empty...";
    cout << " \n \n";
}




int main ()
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
