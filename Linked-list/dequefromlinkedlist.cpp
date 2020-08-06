#include <iostream>
using namespace std;
class deque {
private:
    struct node {
        int data;
        node *next;
        node *prev;
        node(int da) {
            data = da;
            next=prev=NULL;
        }
    };
    node *start;
    node *end;
public:
    deque() {
        start = end = NULL;
    }
    void push_back(int);
    void pop_back();
    void push_front(int);
    void pop_front();
    void display();
    int front()
    {
        return start->data;
    }
    int back()
    {
        return end->data;
    }
};
void deque::display() {
    if (start == NULL)
    {
        cout << "queue is empty!";
        return;
    }
    node *temp = start;
    while (temp!=NULL)
    {
        cout << temp->data << ' ';
        temp=temp->next;
    }

}
void deque::push_back(int data) {
    node *new_node = new node(data);
    if (start == NULL) {
        start = end = new_node;
        return;
    }
    end->next = new_node;
    new_node->prev=end;
    end=new_node;
}
void deque::pop_back() {
    if (start==NULL) {
        cout << "List is empty!";
        return;
    }
    if (start==end) {
        delete start;
        start = end = NULL;
        return;
    }
    node *temp = end->prev;
    delete end;
    end = temp;
    end->next=NULL;
}
void deque::push_front(int data) {
    node *new_node = new node(data);
    if (start == NULL)
    {
        start = end = new_node;
        return;
    }
    new_node->next = start;
    start->prev = new_node;
    start = new_node;
}
void deque::pop_front() {
    if (start==NULL) {
        cout << "List is empty!";
        return;
    }
    if (start == end) {
        delete start;
        start = end = NULL;
        return;
    }
    node *temp = start->next;
    temp->prev = NULL;
    delete start;
    start = temp;
}
int main()
{
    deque obj;
    obj.push_back(10);
    obj.push_back(11);
    obj.push_back(12);
    obj.push_back(13);
    obj.pop_front();
    obj.display();
    // cout << obj.front();
    // cout << obj.back();
}
