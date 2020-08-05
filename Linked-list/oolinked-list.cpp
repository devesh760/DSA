#include <bits/stdc++.h>
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
};
void SinglyLinkedList::displayUsingRecursion()
{
    if (start == NULL)
    {
        cout << "List is Empty!";
        return;
    }
    static struct node *p =start;
    if (p!=NULL)
    {
        cout << p->data << ' ';
        p=p->next;
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
SinglyLinkedList::node *SinglyLinkedList::search(int data)
{
    struct node *t = start;
    while (t != NULL && t->data != data)
        t = t->next;
    return t;
}
void SinglyLinkedList::deleteThisNode(int data)
{
    if (start == NULL)
    {
        cout << "Linked list is empty!";
        return;
    }
    if (start->data == data)
    {
        start = start->next;
        delete start;
        return;
    }
    struct node *temp = start;
    struct node *prev;
    while (temp != NULL && temp->data != data)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
    {
        cout << "Node not found!";
    }
    else
    {
        prev->next = temp->next;
        delete temp;
    }
}
void SinglyLinkedList::display()
{
    if (start == NULL)
    {
        cout << "List is empty!";
        return;
    }
    struct node *t = start;
    while (t != NULL)
    {
        cout << t->data << ' ';
        t = t->next;
    }
}
int main()
{
    SinglyLinkedList list;
    list.appendatLast(13);
    list.appendatLast(14);
    list.appendatLast(15);
    list.deleteThisNode(15);
    list.displayUsingRecursion();
    return 0;
}
