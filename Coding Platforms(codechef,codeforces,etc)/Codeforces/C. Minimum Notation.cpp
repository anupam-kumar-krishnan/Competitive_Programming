#include <bits/stdc++.h>
using namespace std;
#include <string.h>

#define ll long long
#define f0(i,n)  for(i=0;i<n;i++)
#define f1(i,n)  for(i=1;i<=n;i++)
#define fn(i,n)  for(i=n-1;i>=0;i--)
#define Fo(i,k,n) for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define deb(x)   cout<< x <<endl
#define PI       3.141592653589793238

void ans(){
    int n;
    string str;
    cin>>str;

    char temp = str[str.size()-1];
    for(int i=str.size()-2;i>=0;i--){
        char mins = char(int(str[i])+1);

        if(str[i]=='9'){
            continue;
        }
        else if(temp<str[i]){
            str[i]= mins;
        }else   
            temp=str[i];
    }
    
    sort(str.begin(),str.end());

    cout<<str<<'\n';
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    int t;
    t=1;
    cin>>t;
    while (t--)
    {
        ans();
    }
    return 0;
}