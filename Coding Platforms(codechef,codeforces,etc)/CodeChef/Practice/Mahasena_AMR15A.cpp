#include<bits/stdc++.h>
using namespace std;
int main(){
        int i,n,arr[100],count_even=0,count_odd=0;
        cin>>n;     
        for(i=0;i<n;i++){ 
            cin>>arr[i];
            if(arr[i]%2==0){
                count_even++;
            }
            else{
                count_odd++;
            }
        }
        if(count_even>count_odd)
        {
            cout<<"READY FOR BATTLE";
        }
        else {cout<<"NOT READY";}
    return 0;
}