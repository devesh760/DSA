#include <iostream>
using namespace std;
class post
{
    struct stack
    {
        char arr[10];
        int tos;
    };
    struct stack *p;
    char postfix[20];
    char infix[20];
public:
    void get()
    {
        cout<<"Enter a infix:";
        cin>>infix;
    }
    void show()
    {
        cout<<postfix<<endl;
    }
    post()
    {
        p=new struct stack;
        p->tos=-1;
    }
    void push(struct stack *,char);
    char pop(struct stack *);
    bool isoperand(char);
    bool isempty(struct stack);
    bool pecd(char,char);
    void convert(char[],char[]);
};
void post::push(struct stack *p,char x)
{
   p->tos++;
   p->arr[p->tos]=x;
}
char post::pop(struct stack*p)
{
    char x;
    x=p->arr[p->tos];
    p->tos--;
    return x;
}
bool post::isoperand(char ch)
{
    return ((ch>='0' && ch<='9') || (ch>='a' && ch<='z') || (ch>='A' && ch<='Z'));
}
bool post::isempty(struct stack p)
{
    return (p.tos == -1);
}
bool post::pecd(char ch1,char ch2)
{
    if(ch2=='$')
        return  false;
    else if(ch1=='$')
        return true;
    else if(ch2=='*' || ch2=='/' || ch2=='%')
        return false;
    else if(ch1=='*' || ch1=='/' || ch1=='%')
        return true;
    else
        return false;
}
int main()
{
    post n;
    n.get();
    n.convert();
    n.show()
}
void post::convert(char infix[],char postfix[])
{
    struct stack s;
    int i,j=0;
    char ch;
    int ans;
    s.tos=-1;

    for(i=0;infix[i]!='\0';i++)
    {
        ch=infix[i];
        if(isoperand(ch))
        {
            postfix[i]=ch;
            j++;
        }
        else
           {
                while(!isempty(s))
                {

                }


           }
    }
}
