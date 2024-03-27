//************************************//
#include<iostream>
#include<bits/stdc++.h>
#define ll long long
#define new '\n' 
#define fo(a) for( ll int i=0;i<a;i++)
#define mp make_pair
#define even(num) if ((num & 1) == 0)
const int M=1e9+7;
using namespace std;
//*************************************//
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
    
    int t;
    cin>>t;
    while (t--)
    {
        string s1,s2;
        cin>>s1>>s2;
        int count=0,count1=0;
        int n1=s1.size();
        int n2=s2.size();
        fo(s1.size()){
            if(s1[i]=='X'){
                count++;
            }
        }
        fo(s2.size()){
            if(s2[i]=='X'){
                count1++;
            }
        }
        if(s1==s2){
            cout<<"="<<new;
        }
        else if (s1[n1-1]<s2[n2-1])
        {
            cout<<">"<<new;
        }
        else if (s1[n1-1]>s2[n2-1])
        {
            cout<<"<"<<new;
        }
        else if(s1[n1-1]=='S'){
           if (s1[n1-1]==s2[n2-1] && count>count1)
        {
            cout<<"<"<<new;
        }
        else if(s1[n1-1]==s2[n2-1] && count<count1){
            cout<<">"<<new;
        }
        }
        else if(s1[n1-1]=='L'){
           if (s1[n1-1]==s2[n2-1] && count>count1)
        {
            cout<<">"<<new;
        }
        else if(s1[n1-1]==s2[n2-1] && count<count1){
            cout<<"<"<<new;
        }
        }
          
        
 
    }
    
 
return 0;
//************************************//
}
