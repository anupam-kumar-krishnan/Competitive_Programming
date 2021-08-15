#include<bits/stdc++.h>
using namespace std;

  
#include<bits/stc++.h>
using namespace std;

class Solution {
public:
    int doUnion(int a[],int n; int b[], int m){
     set<int> s;
     
	for(int i=0;i<n;i++)
       		s.insert(a[i]);

     	for(int i=0;i<n;i++)
        	s.insert(b[i]);

   return s.size() ;
	}	
};


int main(){
	int t;
	cin>>t;

	while(t--){
		int n;
		cin>>n;
		int a[n],i;

		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		rotate(a,n);

		for(int i=0;i<n;i++){
			cout<<a[i];
		cout<<endl;
		}

		
	}
	return 0;
}
