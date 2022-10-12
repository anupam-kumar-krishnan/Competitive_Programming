#include <bits/stdc++.h>
using namespace std;
float sate_array(float arr[],int no_elements,int no_rotations,int ch)
{ int i,j=1;float z;
 if(no_elements==0)
cout<<"Empty array cannot rotate"<<endl;
 else
{switch(ch)
{ case 1:
 while(j<=no_rotations)
 {
   z=arr[0];
for(i=0;i<no_elements-1;i++)
 arr[i]=arr[i+1];
arr[no_elements-1]=z;
 j++;
 }
 break;
case 2:
 while(j<=no_rotations)
  {
z=arr[no_elements-1];
for(i=no_elements-2;i>=0;i--)
 arr[i+1]=arr[i];
arr[0]=z;
j++;
  }
  }
    }
}
int main()
{
    float arr[100];
    int s,size,ch;
    cout<<"Enter the size of the array : ";
    cin>>size;
    cout<<"Enter the elements of the array : "<<endl;
    for(int i=0;i<size;i++)
    cin>>arr[i];
    cout<<"Enter the the number of rotations you want in the array : ";
    cin>>s;   
    cout<<"Press 1 for left rotation and 2 for right rotation : ";
    cin>>ch;
    sate_array(arr,size,s,ch);
	cout<<"Resultant Array after "<<s<<" rotations is : "<<endl;
    for(int i=0;i<size;i++)
    cout<<arr[i]<<endl;
    return 0;
}