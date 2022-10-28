#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int arr[3];
        cin>>arr[0]>>arr[1]>>arr[2];
        cout<<*max_element(arr,arr+3)-*min_element(arr,arr+3)<<endl;
    }
return 0;
}