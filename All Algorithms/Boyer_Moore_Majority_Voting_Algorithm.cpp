#include<bits/stdc++.h>
using namespace std;
#define ll long long 
 int majorityElement(int a[], int size)
    {
        
        // your code here
        //morres voting algorithm
          int count=1;
       int majority=a[0];
       for(int i=1;i<size;i++){
           if(a[i]==majority) count++;
           else count--;
           if(count==0){
               count=1; 
               majority=a[i];}
       }
       count=0;
       for(int i=0;i<size;i++){
           if(a[i]==majority) count++;
       }
       if(count>size/2) return majority;
       return -1;
       
   }
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    cout<<majorityElement(a,n)<<endl;
    return 0;
}
//Time complexity : O(N)
//Space Complexity :O(1)