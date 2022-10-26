/*We have to take number of rows from user and then print the following pattern for n rows:
   for n=4
    ...1
    ..232
    .34543
    4567654 where . represent spaces */
    //Code:
    #include <iostream>
using namespace std;

int main() {
    int i,j,n,k,w=1,a=1;
    cin>>n;
    for(i=1;i<=2*n;i++)
    {
        while(w<n)
        {
        for(k=1;k<=n-w;k++)
        {
            cout<<" ";
        }
            w++;
            break;
        }
        for(j=1;j<=i;j++)
        {   if(j==1)
           {
           cout<<a;
            }
            else if(a<i && j<=((i/2)+1))
            {
                cout<<++a;
            }
            else
            {
                cout<<--a;
            }
        }
        a=a+1;
        i=i+1;
        cout<<endl;
    }
}
