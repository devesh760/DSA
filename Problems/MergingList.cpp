// Q .Create a new sorted linked list by merging two sorted linkedlist in linear time

#include <iostream>
using namespace std;
class SinglyLinkedList
{
    struct node
    {
        int data;
        node *next;
        node(int d)
        {
            data = d;
            next = NULL;
        }
    };
    struct node *start;

public:
    SinglyLinkedList()
    {
        start = NULL;
    }
    void appendatLast(int);
    void deleteThisNode(int data);
    void display();
    void displayUsingRecursion();
    struct node *search(int);
    void mergeTwoList(SinglyLinkedList, SinglyLinkedList);
};
void SinglyLinkedList::displayUsingRecursion()
{
    if (start == NULL)
        return;
    static struct node *p = start;
    if (p != NULL)
    {
        cout << p->data << ' ';
        p = p->next;
        displayUsingRecursion();
    }
}
void SinglyLinkedList::appendatLast(int data)
{
    struct node *p = new struct node(data);
    if (start == NULL)
    {
        start = p;
        return;
    }
    struct node *temp = start;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = p;
}
void SinglyLinkedList::mergeTwoList(SinglyLinkedList a, SinglyLinkedList b)
{
    if (a.start == NULL && b.start == NULL)
    {
        cout << "Both Lists Are empty!";
        return;
    }
    node *t1 = a.start;
    node *t2 = b.start;
    while (t1 != NULL && t2 != NULL)
    {
        if (t1->data < t2->data)
        {
            appendatLast(t1->data);
            t1 = t1->next;
        }
        else
        {
            appendatLast(t2->data);
            t2 = t2->next;
        }
    }
    while (t1 != NULL)
    {
        appendatLast(t1->data);
        t1 = t1->next;
    }
    while (t2 != NULL)
    {
        appendatLast(t2->data);
        t2 = t2->next;
    }
}
int main()
{
    SinglyLinkedList a, b;
    a.appendatLast(10);
    a.appendatLast(20);
    a.appendatLast(30);
    a.appendatLast(40);
    b.appendatLast(5);
    b.appendatLast(15);
    b.appendatLast(22);
    b.appendatLast(25);
    b.appendatLast(50);
    SinglyLinkedList c;
    c.mergeTwoList(a, b);
    c.displayUsingRecursion();
}
