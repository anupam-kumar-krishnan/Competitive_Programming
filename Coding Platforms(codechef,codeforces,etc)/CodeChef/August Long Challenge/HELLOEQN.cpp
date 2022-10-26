#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    int x;
	    cin>>x;
	    int f=1;
	    for(int i=1;i*i<=x;i++){
	                int j=abs(((2*i)-x)/(2+i));
         
                  if(j==0)continue;
	               
	               int y=(2*i)+(2*j)+(i*j);
	               if(y==x){
	                   cout<<"YES"<<endl;
	                   f=0;
	                   break;
	               }
	           }
	           
	    
	    if(f)  cout<<"NO"<<endl;
	}
	return 0;
}