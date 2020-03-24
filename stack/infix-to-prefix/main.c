#include<stdio.h>
#include<string.h>
struct stack
{
    char arr[10];
    int tos;
};
void push(struct stack *,char);
char pop(struct stack *);
int isoperand(char);
int isempty(struct stack);
int precdence(char,char);
void convert(char[],char[]);

int main()
{
     char postfix[20];
     char infix[20];
     printf("Enter an infix:");
     scanf("%s",infix);
     convert(infix,postfix);
     printf("%s",postfix);
     return 0;
}
void convert(char infix[],char postfix[])
{
     int i,j=0;
     char ch;
     struct stack s;
     int ans;
     s.tos=-1;
     for(i=strlen(infix)-1;i>0;i--)
     {
         ch=infix[i];
         if(isoperand(ch)==1)
         {
             postfix[j]=ch;
             j++;
         }
         else
         {
              while(isempty(s)==0)
              {
                  ans=precdence(ch,s.arr[s.tos]);
                  if(ans==1 )
                    break;
                  else
                  {
                      postfix[j]=pop(&s);
                      j++;
                  }
              }
              push(&s,ch);
         }
     }
              while(isempty(s)==0)
              {
                  postfix[j]=pop(&s);
                  j++;
              }
              postfix[j]='\0';
              strrev(postfix);

}
int isoperand(char ch)
{
    return ((ch>='0' && ch<='9') || (ch>='a' && ch<='z') || (ch>='A' && ch<='Z'));
}
int precdence(char ch1,char ch2)
{
   if(ch1=='$' && ch2=='$')
    return 1;
   if(ch2=='$')
    return 0;
   else if(ch1 == '$')
    return 1;
   else if((ch2== '/' || ch2 == '%' || ch2 == '*') &&(ch1=='/' || ch1=='*' || ch1=='%'))
    return 1;
   else if(ch2== '/' || ch2 == '%' || ch2 == '*')
    return 0;
   else if(ch1=='/' || ch1=='*' || ch1=='%')
    return 1;
   else if((ch1=='+' || ch1=='-') && (ch2=='+' || ch2=='-'))
    return 1;
   else
    return 0;
}
int isempty(struct stack S)
{
    return (S.tos == -1);
}
char pop(struct stack *p)
{
    char ch;
    ch=p->arr[p->tos];
    p->tos--;
    return ch;
}
void push(struct stack *p,char ch)
{
    p->tos++;
    p->arr[p->tos]=ch;
}
