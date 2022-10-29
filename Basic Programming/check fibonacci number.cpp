/*We have to check whether given number is a part of fibonacci series or not. Return true if it is a member of series else return false*/
#include<iostream>
using namespace std;
bool checkMember(int n){
int a=0,b=1,sum,i=1;
    if(n==0 && n==1)
    {
        return 1;
    }
 while(i<n)
 {
     sum=a+b;
     a=b;
     b=sum;
     i++;
     
if(sum==n)
     {
         return 1;
        break;
     } }  
    if(sum !=n)
    {
         return 0;
         
     }
}
int main(){

  int n; 
  cin >> n ;
  if(checkMember(n)){
    cout << "true" << endl;
  }else{
    cout << "false" << endl;
  }

}

