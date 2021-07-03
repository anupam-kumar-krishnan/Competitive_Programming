#include<bits/stdc++.h>
using namespace std;
int main()
{
   int a,b,c;
   cout<<"Enter three numbers a,b and c: ";
   cin>>a>>b>>c;
   
   if(b>a && b>c)
   cout<<b;
   else if(c>a && c>b)
   cout<<c;
   else
   cout<<a;
}
