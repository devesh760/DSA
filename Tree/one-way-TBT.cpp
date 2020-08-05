#include <bits/stdc++.h>
using namespace std;
#define deb(x) cout << #x << ' ' << x;
struct node
{
    int data;
    struct node *left;
    struct node *right;
    bool th;
    node(int d)
    {
        data = d;
        th = true;
        left = right = NULL;
    }
};
void insert_node(struct node **root, int x)
{
    struct node *p = new struct node(x);
    if (*root == NULL)
    {
        *root = p;
        p->th = false;
        return;
    }
    struct node *temp, *prev;
    temp = *root;
    while (temp != NULL)
    {
        prev = temp;
        if (temp->data > x)
            temp = temp->left;
        else
        {
            if (temp->th)
                temp = NULL;
            else
                temp = temp->right;
        }
    }
    if (prev->data > x)
    {
        p->right = prev;
        prev->left = p;
    }
    else
    {
        if (prev->th)
        {
            p->right = prev->right;
            prev->right = p;
            prev->th = false;
        }
        else
        {
            prev->right = p;
            p->th = false;
        }
    }
}
struct node *leftmost(struct node *p)
{
    if (p == NULL)
        return NULL;
    while (p->left != NULL)
        p = p->left;
    return p;
}
void inorder(struct node *p)
{
    struct node *temp;
    if (p == NULL)
    {
        cout << "Tree Is Empty";
        return;
    }
    temp = leftmost(p);
    while (temp != NULL)
    {
        cout << temp->data << ' ' << temp->th << '\n';
        if (temp->th)
            temp = temp->right;
        else
            temp = leftmost(temp->right);
    }
}
void preorder(struct node *p)
{
    if (p == NULL)
    {
        cout << "Tree is Empty";
        return;
    }
    struct node *prev;
    while (p != NULL)
    {
        while (p != NULL)
        {
            prev = p;
            cout << p->data << ' ';
            p = p->left;
        }
        p = prev;
        while (p->th)
            p = p->right;
        p = p->right;
    }
}
int main()
{
    struct node *root = NULL;
    insert_node(&root, 40);
    insert_node(&root, 20);
    insert_node(&root, 50);
    insert_node(&root, 3);
    insert_node(&root, 45);
    insert_node(&root, 2);
    insert_node(&root, 4);
    insert_node(&root, 5);
    insert_node(&root, 60);
    insert_node(&root, 30);
    inorder(root);
    preorder(root);
    return 0;
}
