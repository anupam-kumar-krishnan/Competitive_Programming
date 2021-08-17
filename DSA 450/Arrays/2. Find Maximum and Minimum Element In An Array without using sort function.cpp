//Method - 1
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n = 6;
    int arr[n] = { 1000, 11, 445, 1, 330, 3000 };
    sort(arr,arr+n);
     
  
    cout<<"Sorted Array: "<<endl;
    
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout<<endl;
    
    cout<<"Maximum and Minimum: "<<endl;    
      cout<<arr[0]<<"     "<<arr[n-1];      
    return 0;
}

//Method 2
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int A[n];
    for(int i=0;i<n;i++){
        cin>>A[i];
    }
    int maximum_element=INT_MIN;
    int minimum_element=INT_MAX;
    
    for(int i=0;i<n;i++){
        if(A[i]>maximum_element)
        maximum_element=A[i];
        if(A[i]<minimum_element)
        minimum_element=A[i];
    }
    
    cout<<"Maximum Element: "<<maximum_element<<endl;
    cout<<"Minimum Element: "<<minimum_element;
}
