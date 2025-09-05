#include<iostream>
using namespace std;

class Linkedlist
{
public:
    int data;
    Linkedlist *next;

    Linkedlist(int val):data(val),next(nullptr){}

};

Linkedlist* removeNthNodeFromEnd(Linkedlist *head,int n)
{
    if(!head)
        return head;

    Linkedlist *slow = head;
    Linkedlist *fast = head;
    
    while(n--)
        fast = fast->next;
    
    //If the n is same as length of list thn we can return the heads next
    if(!fast)
        return head->next;
    
    while (fast->next)
    {
        fast = fast->next;
        slow = slow->next;
    }
    slow->next = slow->next->next;
    return head;
    
}

void printList(Linkedlist *head)
{
    while(head)
    {
        cout<<head->data<<"-> ";
        head = head->next;
    }
    cout<<"nullptr"<<endl;
}


int main()
{
    Linkedlist *head = new Linkedlist(1);
    head->next = new Linkedlist(2);
    head->next->next = new Linkedlist(3);
    head->next->next->next = new Linkedlist(4);
    head->next->next->next->next = new Linkedlist(5);
    cout<<"Before remove node the list is "<<endl;
    printList(head);
    removeNthNodeFromEnd(head,2);
    cout<<"After remove node the list is"<<endl;
    printList(head);

    return 0;
    
}