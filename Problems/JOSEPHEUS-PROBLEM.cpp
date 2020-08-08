#include <bits/stdc++.h>
using namespace std;

struct node
{
  string data;
  struct node *next;
};
void append(struct node **p, string NAME)
{
  struct node *temp = new struct node;
  temp->data = NAME;
  if (*p == NULL)
  {
    temp->next = temp;
    *p = temp;
    return;
  }
  struct node *t = *p;
  while (t->next != *p)
    t = t->next;
  t->next = temp;
  temp->next = *p;
}
void display(struct node **p)
{
  if (*p == NULL)
  {
    cout << "LIST IS EMPTY";
    return;
  }
  struct node *temp = *p;
  do
  {
    cout << temp->data << ' ';
    temp = temp->next;
  } while (temp != (*p));
}
string deleteNode(struct node **p)
{
  string data;
  struct node *temp = *p;
  if (*p == NULL)
  {
    return "List empty";
  }
  data = temp->data;
  if ((*p)->next == *p)
  {
    free(*p);
    *p = NULL;
  }
  else
  {
    while (temp->next != *p)
      temp = temp->next;
    temp->next = (*p)->next;
    delete *p;
    *p = temp->next;
  }
  return data;
}
//This is my solve function which takes head ponter of 1st node and number inputed by user:
void solve(struct node **p, int num)
{
  if (num == 0)
  {
    return;
  }
  while ((*p)->next != (*p))
  {
    int n = 1;
    while (n < num)
    {
      (*p) = (*p)->next;
      ++n;
    }
    cout << deleteNode(p) << ' ';
  }
}
int main()
{

  struct node *START = NULL;
  int no_of_sol;
  cin >> no_of_sol;
  cout << "Enter names";
  while (no_of_sol--)
  {
    string name;
    cin >> name;
    append(&START, name);
  }
  display(&START);
  cout << "Enter a number";
  int num;
  cin >> num;
  solve(&START, num);
  display(&START);
  return 0;
}