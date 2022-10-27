#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    int x,y;
      cin>>x>>y;
       int m=max(x,y);
       int n=min(x,y);

     
       if(x==y){
        cout<<"YES"<<endl;
       }
       else{

	    int f=1;
      while(n<m){
        n*=2; 
        if(n==m){
          cout<<"YES"<<endl;
            f=0;
        }
      }
      if(f) cout<<"NO"<<endl;
	   
       }
         
            
	
	}
	return 0;
}