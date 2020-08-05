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
    struct node* search(struct node **,int);
};
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
SinglyLinkedList::node* SinglyLinkedList::search(SinglyLinkedList::node **prev,int data)
{
    struct node *t=start;
    while(t!=NULL && t->data!=data)
    {
     *prev=t;
     t=t->next;
    }
    return t;
}
void SinglyLinkedList::deleteThisNode(int data)
{
    struct node *prev;
    struct node *node_to_be_deleted = search(&prev,data);
    if(node_to_be_deleted == NULL)
    {
        cout <<"List Is Empty!";
    }
    else if(node_to_be_deleted->next == NULL)
    {
        
    }
    else{

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
    list.deleteAtLast();
    list.display();
    return 0;
}