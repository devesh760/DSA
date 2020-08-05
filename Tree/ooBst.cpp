#include <bits/stdc++.h>
using namespace std;
class Node
{
    int data;
    Node *left;
    Node *right;

public:
    Node *root;
    Node(int data)
    {
        root = NULL;
        left = right = NULL;
        this->data = data;
    }
    void createNode(int);
    Node *Find(int);
};
void Node::createNode(int data)
{
    Node *temp = new Node(data);
    if (root == NULL)
       {
           root = temp;
       }
    Node *t = root;
    while(t!=NULL)
}
int main()
{
    return 0;
}
