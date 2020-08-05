#include <bits/stdc++.h>

using namespace std;

struct doubly
{
    int data;
    struct doubly *prev;
    struct doubly *next;
};

void append(struct doubly **p, int data)
{
    struct doubly *temp = (struct doubly *)malloc(sizeof(struct doubly));
    temp->data = data;
    temp->next = NULL;
    if (*p == NULL)
    {
        *p = temp;
        temp->prev = NULL;
        return;
    }
    struct doubly *t = (*p);
    while (t->next != NULL)
        t = t->next;
    t->next = temp;
    temp->prev = t;
}
void display(struct doubly *p)
{
    if (p == NULL)
    {
        cout << "List is Empty";
        return;
    }
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
}
void deleteFirstNode(struct doubly **p)
{
    if (*p == NULL)
    {
        cout << "List is empty";
        return;
    }
    if ((*p)->next == NULL)
    {
        free(*p);
        *p = NULL;
        return;
    }
    *p = (*p)->next;
    free((*p)->prev);
    (*p)->prev = NULL;
}
void deleteLastNode(struct doubly **p)
{
    if (*p == NULL)
    {
        cout << "List is Empty";
        return;
    }
    if ((*p)->next == NULL)
    {
        free(*p);
        *p = NULL;
        return;
    }
    struct doubly *temp = *p;
    while (temp->next != NULL)
        temp = temp->next;
    temp->prev->next = NULL;
    free(temp);
}
void deleteNode(struct doubly **p, int data)
{
    if (*p == NULL)
    {
        cout << "List is empty ";
        return;
    }
    if ((*p)->data == data)
    {
        (*p) = (*p)->next;
        delete (*p)->prev;
        (*p)->prev = NULL;
        return;
    }
    struct doubly *temp = *p;
    while (temp != NULL && temp->data != data)
        temp = temp->next;
    if (temp == NULL)
    {
        cout << "Node not found";
    }
    else
    {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;
    }
}
int main()
{
    struct doubly *START = NULL;
    append(&START, 13);
    append(&START, 14);
    append(&START, 15);
    deleteLastNode(&START);
    display(START);
    return 0;
}