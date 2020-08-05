#include <bits/stdc++.h>

using namespace std;
struct stack1
{
    int data;
    struct stack1 *next;
};

void push(struct stack1 **p, int data)
{
    struct stack1 *temp = (struct stack1 *)malloc(sizeof(struct stack1));
    if (temp == NULL)
    {
        cout << "Stack overflowed";
        return;
    }
    temp->next = *p;
    temp->data = data;
    *p = temp;
}

int pop(struct stack1 **p)
{
    if (*p == NULL)
    {
        cout << "Stack underflowed";
        return -1;
    }
    int data;
    struct stack1 *temp = *p;
    data = (*p)->data;
    *p = (*p)->next;
    free(temp);
    return data;
}

int main()
{
    struct stack1 *tos = NULL;
    push(&tos, 10);
    int d = pop(&tos);
    cout << d;
    return 0;
}
