#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c=0;
    cin>>a>>b;
    if(a>b)
        c=0;
    else
        while(a<=b)
        {
            a=a*3;
            b=b*2;
            c++;
        }
    cout<<c<<endl;
    return 0;
}
