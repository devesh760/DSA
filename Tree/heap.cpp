//Implementation of binary max heap in c++ oops
#include <iostream>
#include <climits>
using namespace std;
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
class maxHeap
{
    int *harr;
    int capacity;
    int cur_size;

public:
    maxHeap()
    {
        int cap;
        cout << "Enter Size Of Heap:";
        cin >> cap;
        capacity = cap;
        harr = new int[cap];
        cur_size = 0;
    }
    maxHeap(int cap)
    {
        capacity = cap;
        harr = new int[cap];
        cur_size = 0;
    }
    void insertKey(int);
    void deleteKey(int);
    void display();
    int search(int);
    void heapify();
    int size()
    {
        return cur_size;
    }
};

int maxHeap::search(int data)
{
    for (int i = 1; i < cur_size; ++i)
    {
        if (harr[i] == data)
            return i;
    }
    return -1;
}
void maxHeap::insertKey(int data)
{
    cur_size++;
    int par, ptr;
    ptr = cur_size;
    while (ptr > 1)
    {
        par = ptr / 2;
        if (harr[par] >= data)
        {
            harr[ptr] = data;
            return;
        }
        harr[ptr] = harr[par];
        ptr = par;
    }
    harr[1] = data;
}
void maxHeap::heapify()
{
    int i = 1;
    while (2 * i < cur_size)
    {
        int a = 2 * i + 1 > cur_size ? 0 : harr[2 * i + 1];
        if (harr[2 * i] == max(harr[2 * i], a) &&
            harr[2 * i] == max(harr[i], harr[2 * i]))
        {
            swap(&harr[2 * i], &harr[i]);
        }
        else if (a == max(harr[2 * i], a) &&
                 a == max(harr[i], a))
        {
            swap(&harr[i], &harr[2 * i + 1]);
        }
        ++i;
    }
}
void maxHeap::deleteKey(int data)
{
    int index = search(data);
    if (index == -1)
    {
        cout << "Data Not Found:";
        return;
    }
    harr[index] = harr[cur_size];
    cur_size--;
    heapify();
}
void maxHeap::display()
{
    for (int i = 1; i <= cur_size; ++i)
    {
        cout << harr[i] << ' ';
    }
}
int main()
{
    maxHeap obj(10);
    obj.insertKey(100);
    obj.insertKey(40);
    obj.insertKey(45);
    obj.insertKey(30);
    obj.insertKey(15);
    obj.insertKey(20);
    obj.insertKey(25);
    obj.insertKey(10);
    obj.insertKey(5);
    obj.deleteKey(15);
    obj.display();
}