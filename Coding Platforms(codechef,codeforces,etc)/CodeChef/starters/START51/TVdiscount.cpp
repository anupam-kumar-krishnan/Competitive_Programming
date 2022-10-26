#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t,a,b,c,d;
	cin>>t;
	while(t--){
	    cin>>a>>b>>c>>d;
	    if(a-c>b-d)
	    cout<<"second"<<endl;
	    else if(b-d>a-c)
	    cout<<"first"<<endl;
	    else 
	    cout<<"any"<<endl;
	}
	return 0;
}