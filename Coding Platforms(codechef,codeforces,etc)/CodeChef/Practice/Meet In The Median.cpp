//Meet In The Median
//Difficulty Rating:1750
//Problem Link : https://www.codechef.com/submit/SUBMEDIA

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mod 1000000007

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
//cin>>t;
    t=1;
    int c=1;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        vector<int>v(n);
        for(int i=0;i<n;i++)
        {
            cin>>v[i];
        }
        vector<int>temp=v;
        sort(temp.begin(),temp.end());
        int idx=n-1-k/2;
        int l=k/2;
        int h=k/2;
        int m=1;
        if(k%2==0)
            l--;
        int ele=temp[idx];
        vector<int>ans;
        for(auto x:v)
        {
            if((x==ele)&&(m!=0))
            {
                m--;
                ans.pb(x);
            }
            if((x<ele)&&(l!=0))
            {
                l--;
                ans.pb(x);
            }
            if((x>ele)&&(h!=0))
            {
                h--;
                ans.pb(x);
            }
            if(m==0&&l==0&&h==0)
                break;
        }
        cout<<ele<<"\n";
        for(auto it:ans)
            cout<<it<<" ";
        cout<<"\n";
    }

//cout<<"\n";
//cout<<"\n";
    return 0;
}