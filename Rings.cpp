#include <iostream>
typedef long long ll;
using namespace std;
int main()
{
   ll t;
   cin>>t;
   while(t--)
   {
       ll n,i,f=0,f1=0;
       cin>>n;
       string s;
       cin>>s;
       for( i=0;i<n;i++)
       {
           if(s[i]=='0'&&i>=n/2){
           f=1;
           break;
           }
           if(s[i]=='0'&&i<n/2)
           {
           f1=1;
           break;
           }
       }
       if(f==1)
       {
          cout<<1<<" "<<i+1<<" "<<1<<" "<<i<<endl; 
       }
       if(f1==1)
       {
          cout<<i+2<<" "<<n<<" "<<i+1<<" "<<n<<endl; 
       }
       if(f1==0&&f==0)
       {
         cout<<1<<" "<<n-1<<" "<<2<<" "<<n<<endl;  
       }
   }
    
}