/*******
Binary search Tree postorder,inorder,preorder,search,creation,deletetion in c 
Iterative Code                        ******/


#include <bits/stdc++.h>
using namespace std;
struct Bst
{
    int data;
    struct Bst *left;
    struct Bst *right;
    int x;
};
struct stack1
{
    struct Bst *arr[5];
    int tos;
};
void push(struct stack1 *p, struct Bst *n)
{
    p->tos++;
    p->arr[p->tos] = n;
}
struct Bst *pop(struct stack1 *p)
{
    struct Bst *n;
    n = p->arr[p->tos];
    p->tos--;
    return n;
}
void postorder(struct Bst *p)
{
    if (p == NULL)
    {
        cout << "List Is Empty";
        return;
    }
    struct stack1 s;
    s.tos = -1;
    while (p != NULL || s.tos != -1)
    {
        while (p != NULL)
        {
            push(&s, p);
            if (p->right != NULL)
                push(&s, p->right);
            p = p->left;
        }
        p = pop(&s);
        if (p->x > 0)
        {
            cout << p->data << ' ';
            p = NULL;
        }
        else
            p->x = 1;
    }
}

void preorder(struct Bst *p)
{
    if (p == NULL)
    {
        cout << "Empty Tree";
        return;
    }
    struct stack1 s;
    s.tos = -1;
    while (p != NULL || s.tos != -1)
    {
        while (p != NULL)
        {
            cout << p->data << ' ';
            if (p->right != NULL)
                push(&s, p->right);
            p = p->left;
        }
        p = pop(&s);
    }
}
struct Bst *Find(struct Bst *, int);
void append(struct Bst **pr, int data)
{
    struct Bst *p, *temp;
    p = new struct Bst;
    p->data = data;
    p->left = p->right = NULL;
    if (*pr == NULL)
    {
        p->x = 1;
        *pr = p;
        return;
    }
    temp = *pr;
    while (temp != NULL)
    {
        if (temp->data > data)
        {
            if (temp->left == NULL)
            {
                temp->left = p;
                p->x = 1;
                break;
            }
            temp = temp->left;
        }
        else
        {
            if (temp->right == NULL)
            {
                temp->right = p;
                p->x = -1;
                break;
            }
            temp = temp->right;
        }
    }
}
void inorder(struct Bst *p)
{
    if (p == NULL)
    {
        cout << "Tree Is Empty";
        return;
    }
    struct stack1 s;
    s.tos = -1;
    while (p != NULL || s.tos != -1)
    {
        while (p != NULL)
        {
            push(&s, p);
            p = p->left;
        }
        p = pop(&s);
        cout << p->data << ' ';
        p = p->right;
    }
}

int search1(struct Bst *root, struct Bst **p, struct Bst **c, int x)
{
    struct Bst *prev = NULL;
    while (root != NULL)
    {
        if (root->data == x)
        {
            *p = prev;
            *c = root;
            return 1;
        }
        prev = root;
        if (root->data > x)
            root = root->left;
        else
            root = root->right;
    }
    return 0;
}
void del_node(struct Bst **root, int x)
{
    if (*root == NULL)
    {
        cout << "Tree is empty";
        return;
    }
    struct Bst *child, *par;
    int ans = search1(*root, &par, &child, x);
    if (ans == 0)
    {
        cout << "Node Not Found";
        return;
    }
    if (child->left != NULL && child->right != NULL)
    {
        struct Bst *c = child->right;
        par = child;
        while (c->left != NULL)
        {
            par = c;
            c = c->left;
        }
        child->data = c->data;
        child = c;
    }
    if (child->left == NULL && child->right == NULL)
    {
        if (par == NULL)
            *root = NULL;
        else if (par->left == child)
            par->left = NULL;
        else
            par->right = NULL;
        delete child;
    }
    else if (child->left != NULL && child->right == NULL)
    {
        if (par == NULL)
            *root = child->left;
        else if (par->left == child)
            par->left = child->left;
        else
            par->right = child->left;
        delete child;
    }
    else if (child->left == NULL && child->right != NULL)
    {
        if (par == NULL)
            *root = child->right;
        else if (par->left == child)
            par->left = child->right;
        else
            par->right = child->right;
        delete child;
    }
}
int main()
{
    struct Bst *root = NULL;
    append(&root, 40);
    append(&root, 50);
    append(&root, 60);
    append(&root, 42);
    append(&root, 10);
    del_node(&root, 50);
    append(&root, 70);
    inorder(root);
    cout << '\n';
    preorder(root);
    cout << '\n';
    postorder(root);
}
