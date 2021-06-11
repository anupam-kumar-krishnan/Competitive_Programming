#include <iostream>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
        int xa,xb,Xa,Xb;
        cin>>xa>>xb>>Xa>>Xb;
        int d=Xa/xa+Xb/xb;
        cout<<d<<endl;
    }
	// your code goes here
	return 0;
}
