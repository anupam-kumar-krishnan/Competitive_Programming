#include<iostream>
using namespace std;

int main(){
    int num;
    cout<<"Enter the first number: ";
    cin>>num;

    cout<<"Factors of "<<num<<": ";
    for(int i=1;i<=num;i++){
        if(num%i==0){
            cout<<i<<" ";
        }
    }
    
    return 0;
}

