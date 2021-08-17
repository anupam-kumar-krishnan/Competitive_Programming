#include<bits/stdc++.h>
using namespace std;

class Solution{
	public:

	int kthSmallest(int arr[],int l, int r, int k){
	sort(arr,arr+r);

	return arr[k-1];
	}
};

int main()
{
	int t;
	  cin>>t;

	while(t--)
	{
	  int number_of_elements;
	  cin>>number_of_elements;

	  int a[number_of_elements];
	  for(int i=0;i<number_of_elements;i++)
		cin>>a[i];

	  int k;
	  cin>>k;
	  Solution ob;
	  cout<<ob.kthSmallest(a, 0, number_of_elements-1, k)<<endl;
	}
	return 0;
}
------------------------------------------------------------------------------------

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
        
        int arr[n];
        
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        int k;
        cin>>k;
        priority_queue<int,vector<int>,greater<int>> p;
        
        for(int i=0;i<n;i++)
        {
            p.push(arr[i]);
        }
        int ans,i=1;
        while(!p.empty())
        {
            if(i==k)
            {
                ans=p.top();
                break;
            }
            i++;
            p.pop();
        }
        cout<< ans<< "\n";
    }
}
