#include <bits/stdc++.h>
using namespace std;
struct node
{
    int val;
    node *next;
};
node *createnode()
{
    node* node1=new node ();
    puts("Enter the value you want to add");
    cin>>node1->val;
    return node1;
}
node* order (node* list,node* newnode)
{
    node* ptr1;
    node* ptr2;
    ptr1=NULL;
    ptr2=list;
    if(list == NULL)
    {
        list=newnode;
        cout<<"Insert item at an empty list"<<endl;
    }
    else if (list->val >= newnode->val)
    {
        newnode->next=list;
        list=newnode;
        cout<<"Insert first item at non empty list "<<endl;
    }
    else
    {
        while((ptr2!=NULL)&&(newnode->val >ptr2->val))
        {
            ptr1=ptr2;
            ptr2=ptr2->next;
        }
        if(ptr2==NULL)
        {
            ptr1->next=newnode;
            newnode->next=NULL;
            cout<<"Insert item at last in none empty list "<<endl;
        }
        else
        {
            newnode->next=ptr2;
            ptr1->next=newnode;
            cout<<"Insert item at middle "<<endl;
        }
    }
    return list;
}
node* del (node* list ,int x)
{
    node* ptr1;
    node* ptr2;
    ptr1=NULL;
    ptr2=list;
    bool test = false;
    if(list ==NULL)
    {
        cout<<"The list is empty"<<endl;
    }
    else if(ptr2->val==x)
    {
        list=ptr2->next;
        delete(ptr2);
        cout<<"Item deleted successfully "<<endl;
        test=true;
    }
    else
    {
        while (ptr2!=NULL)
        {
            ptr1=ptr2;
            ptr2=ptr2->next;
            if(ptr2->val==x)
            {
                ptr1->next=ptr2->next;
                delete(ptr2);
                cout<<"Item deleted successfully "<<endl;
                 test=true;
                 break;
            }
        }
    }
    if(test==false)
    {
        cout<<"The Item you want to delete is not found"<<endl;
    }
    return list;
}

void print (node* list)
{
    node*ptr=list;
    if (list !=NULL)
    {
        cout<<"The list contains "<<endl;
        while (ptr!=NULL)
        {
            cout <<ptr->val<<" ";
			ptr=ptr->next;
        }
    }
    else
    {
        cout<<"The list is empty "<<endl;
    }
    puts("");
}

int main()
{
     int val ;
     char choice ;
     node* MyList =NULL;
     while(true)
     {
        cout<<"a- Add node.\nd- Delete node.\np- Print All.\ne- Exit.";
        cout<<"\nEnter Your Choice: "<<endl;
        cin>>choice;
        switch(choice)
        {
          case ('a'):
          case ('A'):
           {
		      node* newnode=createnode();
              MyList=order(MyList, newnode);
	       }
           break;
          case 'd':
          case 'D':
           {
              cout << "Enter value to be delete :";
		      cin>>val;
		      MyList=del(MyList, val);
	       }
         	break;
          case 'P':
          case 'p':
	       {
	     	print(MyList);
	       }
           break;
          case 'e':
          case 'E':
            {
                return 0;
            }
            break;
           default : cout<<"choose a valid operation "<<endl;
           }
        }
    return 0;
}
