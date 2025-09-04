#include<iostream>
using namespace std;

class Linkedlist
{
public:
    int data;
    Linkedlist *next;
    Linkedlist(int val):data(val),next(nullptr){}

};

void reorderList(Linkedlist *head)
{
    if (!head || !head->next)
    return;

    // Find the middle of the list
    Linkedlist *slow = head;
    Linkedlist *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Split the list into two halves
    Linkedlist *secondHalf = slow->next;
    slow->next = nullptr;

    // Reverse the second half
    Linkedlist *prev = nullptr;
    Linkedlist *current = secondHalf;
    while (current) {
        Linkedlist *nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }
    Linkedlist *reversedSecondHalf = prev;

    // Merge the two halves
    Linkedlist *firstHalf = head;
    Linkedlist *secondHalfPtr = reversedSecondHalf;

    while (secondHalfPtr) {
        Linkedlist *firstNext = firstHalf->next;
        Linkedlist *secondNext = secondHalfPtr->next;

        firstHalf->next = secondHalfPtr;
        secondHalfPtr->next = firstNext;

        firstHalf = firstNext;
        secondHalfPtr = secondNext;
    }

}

void printList(Linkedlist *head)
{
    while(head)
    {
        cout<<head->data<<" -> ";
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
    cout<<"Printing list before reorder"<<endl;
    printList(head);
    reorderList(head);
    cout<<"Printing list after reorder"<<endl;
    printList(head);


    return 0;

}