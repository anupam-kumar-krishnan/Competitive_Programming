#include<bits/stdc++.h>
using namespace std;
int main()
{
   int a,b;
   
   cout<<"Enter two numbers: ";
   cin>>a>>b;
   
   cout<<"Before Swapping: "<<endl;
   cout<<a<<" "<<b<<endl;
   
   int temp;
   temp=a;
   a=b;
   b=temp;
   
   cout<<"After Swapping: "<<endl;
   cout<<a<<" "<<b;
}
