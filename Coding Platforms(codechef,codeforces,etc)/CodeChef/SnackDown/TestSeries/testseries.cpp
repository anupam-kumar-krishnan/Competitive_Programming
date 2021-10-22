#include <iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    for(int i = 0;i<n;i++)
    {
        int R1,R2,R3,R4,R5;
        int India=0,England=0;
        cin>>R1>>R2>>R3>>R4>>R5;
        if(R1 == 1)
        {
            India++;
        }
        else if(R1 == 2)
        {
            England++;
        }
        if(R2 == 1)
        {
            India++;
        }
        else if(R2 == 2)
        {
            England++;
        }
        if(R3 == 1)
        {
            India++;
        }
        else if(R3 == 2)
        {
            England++;
        }
        if(R4 == 1)
        {
            India++;
        }
        else if(R4 == 2)
        {
            England++;
        }
        if(R5 == 1)
        {
            India++;
        }
        else if(R5 == 2)
        {
            England++;
        }
        if(India>England)
        {
            cout<<"INDIA"<<endl;
        } 
        else if(England>India)
        {
            cout<<"ENGLAND"<<endl;
        }
        else
        {
            cout<<"DRAW"<<endl;
        }
    }
	return 0;
}
