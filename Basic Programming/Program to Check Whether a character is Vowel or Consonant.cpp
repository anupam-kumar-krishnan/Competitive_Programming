#include<bits/stdc++.h>
using namespace std;
int main()
{
   char x;
   cin>>x;
   char lowercase,uppercase;
   lowercase = (x=='a' || x=='e' || x=='i' || x=='o' || x=='u');
   uppercase = (x=='A' || x=='E' || x=='I' || x=='O' || x=='U');
   
   if(!isalpha(x))
   cout<<"Not a character";
   else if(lowercase || uppercase)
   cout<<"VOVWEL";
   else
   cout<<"CONSONANT";
}
