#include <iostream>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int result=0;
        while(n!=0){
            if(n%2==0){
                n = n/2;
            }
            else{
                result++;
                n = n/2;
            }
        }
        cout<<result-1<<endl;
    }
	return 0;
}