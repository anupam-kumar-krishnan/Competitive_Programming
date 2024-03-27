#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
     int n;
     cin >> n;
     set<int> s1, s2;
     set<int> s3;
     for (int i = 1; i <= n; i++)
     {
          s3.insert(i);
     }
     int x;
     cin >> x;
     for (int i = 0; i < x; i++)
     {
          int a;
          cin >> a;
          s1.insert(a);
          //    int b=i+1;
          //    s3.insert(b);
     }
     cin >> x;
     for (int i = 0; i < x; i++)
     {
          int b;
          cin >> b;
          s1.insert(b);
     }
     // cout<<s1.size();
     // cout<<s2.size();
 
     /*for(auto i:s2){
         cout<<i<<" ";
     }*/
 
     // s1.merge(s2);
     // s1.erase(0);
 
     set<int>::iterator it;
     if (s1 == s3)
     {
          cout << "I become the guy." << endl;
     }
     else
     {
          cout << "Oh, my keyboard!" << endl;
     }
     /*for(auto i:s1){
      cout<<i<<" ";
     }*/
     return 0;
}
