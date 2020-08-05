#include <bits/stdc++.h>

using namespace std;
struct node
{
  int data;
  struct node *next;
};
void append(struct node **pos, int data)
{
  struct node *temp, *t;
  temp = new struct node;
  temp->data = data;
  if (*pos == NULL)
  {
    *pos = temp;
    temp->next = *pos;
    return;
  }
  t = *pos;
  while (t->next != *pos)
    t = t->next;
  t->next = temp;
  temp->next = *pos;
}
void display(struct node *p)
{
  struct node *temp = p;
  if (p == NULL)
  {
    std::cout << "List is Empty";
    return;
  }
  do
  {
    std::cout << temp->data << std::endl;
    temp = temp->next;
  } while (temp != p);
}
void deleteFirstnode(struct node **p)
{
  struct node *temp = *p;
  if (*p == NULL)
  {
    cout << "List is empty";
    return;
  }
  if ((*p)->next == *p)
  {
    free(p);
    p = NULL;
    return;
  }
  while (temp->next != *p)
    temp = temp->next;
  temp->next = (*p)->next;
  delete *p;
  *p = temp->next;
}
void deleteLastNode(struct node **p)
{
  if (*p == NULL)
  {
    std::cout << "List is Empty";
    return;
  }
  if ((*p)->next == *p)
  {
    delete *p;
    (*p) = NULL;
  }
  struct node *temp = *p;
  while (temp->next->next != *p)
    temp = temp->next;
  delete temp->next;
  temp->next = *p;
}
void deleteNode(struct node **head, int data)
{
  if ((*head) == NULL)
  {
    cout << "List is Empty";
    return;
  }
  if ((*head)->data == data)
  {
    delete *head;
    *head = NULL;
    cout << "Node deleted 1";
  }
  struct node *temp = *head;
  struct node *prev;
  while (temp->data != data && temp != *head)
  {
    prev = temp;
    temp = temp->next;
  }
  if (temp->next == *head)
  {
    cout << "Node not found";
  }
  else
  {
    prev->next = temp->next;
    delete temp->next;
    cout << "Node deleted";
  }
}

int main()
{
  struct node *START = NULL;
  append(&START, 12);
  append(&START, 13);
  append(&START, 15);
  append(&START, 16);
  append(&START, 17);
  append(&START, 18);
  append(&START, 19);
  display(START);
  return 0;
}
