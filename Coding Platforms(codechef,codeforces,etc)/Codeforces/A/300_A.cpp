#include <bits/stdc++.h>
#define ll long long
const ll N = 1e5+10;
const ll M = 1e7+7;
ll arr[N];
ll P[M];
using namespace std;
int main (){
    ll test;
    cin>>test;
    while(test--){
       string s1;
       cin>>s1;
       stack<char>st;
       //cout<<s1[0]<<endl;
       //st.push(s1[0]);
       ll ans=1;
       for (int i = 0; i < s1.length(); i++)
       {
           if (st.size()==0)
           {
               st.push(s1[i]);
           }
         
           else if (st.top()=='B'&&s1[i]=='B')
          {
              st.pop();
              //ans--;
          }
           else if (st.top()=='A'&&s1[i]=='B')
          {
              st.pop();
              //ans--;
          } 
          else
          {
            st.push(s1[i]);
            //ans++;
          }
          
          
       }
       
       if (st.empty())
       {
           cout<<0<<endl;
       }
       else
       {
          cout<<st.size()<<endl;
       }
       
       
 
       
    }
    return 0;
}
