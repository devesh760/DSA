#include <bits/stdc++.h>

using namespace std;

struct queue1
{
    int data;
    struct queue1 *next;
};

void insert(struct queue1 **front, struct queyu **rear, int data)
{
    struct queue1 *temp = (struct queue1 *)malloc(sizeof(struct queue1));
    temp->data = data;
    temp->next = NULL;
    if (temp == NULL)
    {
        cout << "Queue is Overflowed";
        return;
    }
    if (*p == NULL)
        *front = temp;
    else
        *rear->next = temp;
    *rear = temp;
}

int remove(struct queue1 **front, struct queue1 **rear, int data)
{
    if (*front == NULL)
    {
        cout << "Queue is Underflowed";
        return -1;
    }
    int data = (*front)->data;
    if ((*front) == *(rear))
    {
        *front = *rear = NULL;
        delete *front;
    }
    else
    {
        struct queue1 *temp = (*front);
        *front = (*front)->next;
        delete temp;
    }
    return data;
}
int main()
{
    struct queue1 *START = NULL;
    cout << remove(&START);
    insert(&START, 10);
    insert(&START, 11);
    return 0;
}