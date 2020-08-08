#include <bits/stdc++.h>
using namespace std;
void TOH(int n,char s,char u,char d)
{
    static int c;
      if(n>0)
      {
            TOH(n-1,s,d,u);
             cout << ++c << ". Move from "<<s<<" to "<< d<<'\n';
             TOH(n-1,u,s,d);
      }
}
void showtime(long long n)
{
      if(n<60)
      {
          cout << n << "sec";
          return;
      }
    long double a = n/60.0;
    if(a<60)
    {
          cout << a << "min";
          return;
    }
    a = a/60.0;
    if(a<60)
    {
          cout << a << "hrs";
    }
}
int main()
{
    int n;
    cin >> n;
    system("cls");
    system("color a");
    clock_t  s;
    double time_taken=0;
    s = clock();
     TOH(n,'A','B','C');
     s = clock() -s;
     time_taken = (double)s/CLOCKS_PER_SEC;
     cout << "\n\nTIME TAKEN BY CPU: " << time_taken <<"sec" << '\n';
     cout << "HUMAN TIME(considering 1move/sec): "; showtime(pow(2,n)-1);
     fflush(stdin);
     getchar();
}