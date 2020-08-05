#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node *left, *right;
    bool lth, rth;
    node(int x)
    {
        data = x;
        left = right = NULL;
        lth = rth = true;
    }
};
void insert_node(struct node **root, int x)
{
    struct node *p = new struct node(x);
    if (*root == NULL)
    {
        *root = p;
        p->lth = p->rth = false;
        return;
    }
    struct node *temp, *prev;
    temp = *root;
    while (temp != NULL)
    {
        prev = temp;
        if (temp->data > x)
        {
            if (temp->lth)
                temp = NULL;
            else
                temp = temp->left;
        }
        else
        {
            if (temp->rth)
                temp = NULL;
            else
                temp = temp->right;
        }
    }
    if (prev->data > x)
    {
        if (prev->lth)
        {
            prev->lth = false;
            p->left = prev->left;
            prev->left = p;
            p->right = prev;
        }
        else
        {
            prev->left = p;
            p->right = prev;
            p->lth = false;
        }
    }
    else
    {
        if (prev->rth)
        {
            prev->rth = false;
            p->right = prev->right;
            prev->right = p;
            p->left = prev;
        }
        else
        {
            prev->right = p;
            p->left = prev;
            p->rth = false;
        }
    }
}
struct node *leftmost(struct node *p)
{
    if (p == NULL)
        return NULL;
    while (p->left != NULL && !p->lth)
        p = p->left;
    return p;
}
void inorder(struct node *p)
{
    if (p == NULL)
    {
        cout << "Tree is Empty";
        return;
    }
    p = leftmost(p);
    while (p != NULL)
    {
        cout << p->data << ' ';
        if (p->rth)
            p = p->right;
        else
            p = leftmost(p->right);
    }
}
int main()
{
    struct node *root = NULL;
    insert_node(&root, 40);
    insert_node(&root, 20);
    insert_node(&root, 50);
    insert_node(&root, 3);
    insert_node(&root, 25);
    insert_node(&root, 45);
    insert_node(&root, 60);
    insert_node(&root, 2);
    inorder(root);
    return 0;
}