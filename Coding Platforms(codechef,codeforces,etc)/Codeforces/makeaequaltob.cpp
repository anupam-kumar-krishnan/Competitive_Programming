#include<iostream>
#include<vector>
using namespace std;

int main(){
    int t;cin>> t;
    while(t--){
        int n;cin >> n;

        vector<int> a(n),b(n);
        int c = 0 , d = 0;
        for(int i=0;i<n;++i){
            cin>>a[i];
            if(a[i]) c++;
        }

        int mismattch = 0;
        for(int i=0;i<n;++i){
            cin>>b[i];
            if(b[i]) d++;
            if(a[i]!=b[i]) mismattch++;
        }

        int mn = abs(c-d);
        if(mn ==0) mismattch?cout<<"1\n":cout<<"0\n";
        else cout<<min(mismattch,mn+1)<<'\n';

    }
    return 0;
}