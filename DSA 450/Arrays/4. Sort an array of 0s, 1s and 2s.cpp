#include<bits/stdc++.h>
using namespace std;

  
class Solution {
public:
    void sort012(vector<int>& nums) {
       int lo = 0; 
        int hi = nums.size() - 1; 
        int mid = 0; 

        while (mid <= hi) { 
            switch (nums[mid]) { 

            // If the element is 0 
            case 0: 
                swap(nums[lo++], nums[mid++]); 
                break; 

            // If the element is 1 . 
            case 1: 
                mid++; 
                break; 

            // If the element is 2 
            case 2: 
                swap(nums[mid], nums[hi--]); 
                break; 
            }
        }
    }
};


int main(){
	int t;
	cin>>t;

	while(t--){
		int n;
		cin>>n;
		int a[n];

		for(int i=0;i<n;i++){
			cin>>a[i];
		}

		Solution.ob;
		ob.sort012(a,n);

		for(int i=0;i<n;i++){
			cout<<a[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
