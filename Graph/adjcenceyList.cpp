#include <bits/stdc++.h>
using namespace std;
struct edge
{
    char data;
    struct edge *next;
};
struct node
{
    struct node *next;
    char data;
    struct edge *enext;
};
void insertvertex(struct node **, char);
void insertedge(struct node *, char, char);
struct node *findvertex(struct node *, char);
void display(struct node *);
void delete_edge(struct node *, char, char);
void delete_node(struct node **, char);
int main()
{
    struct node *start = NULL;
    char src, dest, vert;
    int choice;
    do
    {
        cout << "\nSelect an option: ";
        cout << "\n1.Add vertex";
        cout << "\n2.Insert edge";
        cout << "\n3.Delete vertex";
        cout << "\n4.Delete Edge";
        cout << "\n5.Display";
        cout << "\n6.Quit";
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            cout << "Enter vertex: ";
            cin >> vert;
            insertvertex(&start, vert);
            break;
        case 2:
            cout << "Enter source and target";
            cin >> src >> dest;
            insertedge(start, src, dest);
            break;
        case 3:
            cout << "Enter a vertex:";
            cin >> vert;
            delete_node(&start, vert);
            break;
        case 4:
            cout << "Enter Source And Target:";
            cin >> src >> dest;
            delete_edge(start, src, dest);
            break;
        case 5:
            display(start);
            break;
        case 6:
            exit(0);
            break;
        default:
            cout << "Wrong choice!Try Again";
        }
    } while (1);
    return 0;
}
void insertvertex(struct node **p, char data)
{
    struct node *temp = new struct node;
    temp->next = NULL;
    temp->enext = NULL;
    temp->data = data;
    if ((*p) == NULL)
    {
        (*p) = temp;
        return;
    }
    struct node *t = (*p);
    while (t->next != NULL)
        t = t->next;
    t->next = temp;
}
struct node *findvertex(struct node *p, char ch)
{
    while (p != NULL && p->data != ch)
        p = p->next;
    return p;
}
void insertedge(struct node *start, char src, char tgt)
{
    if (start == NULL)
    {
        cout << "Graph is Empty!";
        return;
    }
    if (!findvertex(start, tgt))
    {
        cout << "Target vertex not found!";
        return;
    }
    struct node *p = findvertex(start, src);
    if (!p)
    {
        cout << "Source vertex not found";
        return;
    }
    struct edge *newedge = new struct edge;
    newedge->data = tgt;
    newedge->next = NULL;
    struct edge *temp = p->enext;
    if (temp == NULL)
    {
        p->enext = newedge;
        return;
    }
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newedge;
}
void display(struct node *p)
{
    if (p == NULL)
    {
        cout << "Graph is Empty!";
        return;
    }
    struct edge *t;
    while (p != NULL)
    {
        cout << p->data << ' ';
        t = p->enext;
        while (t != NULL)
        {
            cout << '\t' << t->data;
            t = t->next;
        }
        cout << '\n';
        p = p->next;
    }
}
void delete_edge(struct node *p, char src, char dest)
{
    if (p == NULL)
    {
        cout << "Graph is Empty";
        return;
    }
    struct node *source = findvertex(p, src);
    if (!source)
    {
        cout << "Source vertex node find";
        return;
    }
    if (!findvertex(p, dest))
    {
        cout << "Destination vertex not found";
        return;
    }
    struct edge *temp = temp = source->enext;
    if (temp->data == dest)
    {
        source->enext = temp->next;
        delete temp;
        return;
    }
    struct edge *prev;
    while (temp != NULL && temp->data != dest)
    {
        prev = temp;
        temp = temp->next;
    }
    if (!temp)
        return;
    prev->next = temp->next;
    delete temp;
}
struct node *findvertex_ex(struct node *start, struct node **prev, char ch)
{
    while (start != NULL && start->data != ch)
    {
        *prev = start;
        start = start->next;
    }
    return start;
}
void delete_node(struct node **start, char ch)
{
    if (*start == NULL)
    {
        cout << "Graph is empty!";
        return;
    }
    struct node *prev_vertex = NULL;
    struct node *vertex = findvertex_ex(*start, &prev_vertex, ch);
    if (!vertex)
    {
        cout << "Vertex to be deleted is not found!";
        return;
    }
    // struct node *t = *start;
    // while (t != NULL)
    // {
    //     delete_edge(*start, t->data, ch);
    //     t = t->next;
    // }

    struct edge *temp = vertex->enext;
    vertex->enext = NULL;
    struct edge *prev;
    while (temp != NULL)
    {
        prev = temp;
        temp = temp->next;
        delete prev;
    }
    if (!prev_vertex)
        *start = vertex->next;
    else
        prev_vertex->next = vertex->next;
    delete vertex;
    vertex = *start;
    while (vertex != NULL)
    {
        temp = vertex->enext;
        if (temp->data == ch)
        {
            vertex->enext = temp->next;
            delete temp;
        }
        while (temp != NULL && temp->data != ch)
        {
            prev = temp;
            temp = temp->next;
        }
        if (temp)
        {
            prev->next = temp->next;
            delete temp;
        }
        vertex = vertex->next;
    }
}