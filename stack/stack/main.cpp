//A generic class for simple stack operation in c++
#include <iostream>

using namespace std;
template <typename X,int Y>class stack
{
    X arr[Y];
    int tos;
public:
    stack()
    {
         tos = -1;
    }
    void push(stack *p,X a)
    {
        if (p->tos == Y )
        {
            cout << "Stack overflowed";
            return;
        }
        p->tos ++ ;
        p->arr[p->tos] = a;
    }
    X pop(stack *p)
    {
        X a;
        if(p->tos <0)
        {
            cout << " Stack underflowed";
            return -1;
        }
       a = p->arr[p->tos];
       p->tos -- ;
       return a;
    }

};
