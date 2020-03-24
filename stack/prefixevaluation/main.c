#include<stdio.h>
#include<math.h>
#include<string.h>
struct stack
{
    float arr[10];
    int tos;
};
float pop(struct stack *);
void push(struct stack*,float);
int isoperand(char);
float evaluate(float,float,char);
float solve(char[]);
int main()
{
    char postfix[20];
    printf("Enter a postfix:");
    scanf("%s",postfix);
    printf("%f",solve(postfix));
    return 0;
}
float solve(char postfix[])
{
     struct stack s;
     char ch;
     float result,op1,op2;
     int i;
     s.tos=-1;
     for(i=strlen(postfix)-1;i>=0;i--)
     {
         ch=postfix[i];
         if(isoperand(ch)==1)
         {
             push(&s,(float)(ch-48));
         }
         else
         {
             op1=pop(&s);
             op2=pop(&s);
             result=evaluate(op1,op2,ch);
             push(&s,result);
         }
     }
     result=pop(&s);
     return result;
}
float pop(struct stack *p)
{
    if(p->tos<-1)
    {
        printf("stack underflowed");
        return -1;
    }
    int x;
    x=p->arr[p->tos];
    p->tos--;
    return x;
}
void push(struct stack *p,float x)
{
    if(p->tos>9)
    {
        printf("Stack overflowed");
        return;
    }
    p->tos++;
    p->arr[p->tos]=x;
}
int isoperand(char ch)
{
    return (ch>='0' && ch<='9');
}
float evaluate(float op1,float op2,char operato)
{
    switch(operato)
    {
        case '+': return (op1+op2);
        case '-': return (op1-op2);
        case '/': return (op1/op2);
        case '*': return (op1*op2);
        case '%': return (fmod(op1,op2));
        case '$': return (pow(op1,op2));
        default: return 0;
    }
}
