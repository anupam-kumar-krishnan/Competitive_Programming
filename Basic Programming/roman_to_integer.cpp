#include<iostream>
using namespace std;

class Solution 
{
  public:
      int romanToInt(string s)
      {
        int sum=0;
        for (int i=0;i<s.size();i++)
        {
          if (s[i]=='I'&&s[i+1]=='V')
          {
            sum+=4;
            i++;
            continue;
          }
           else if(s[i]=='I'&&s[i+1]=='X')
           {
             sum+=9;
             i++;
             continue;
           }
            else if (s[i]=='X'&& s[i+1]=='L')
            {
              sum+=40;
              i++;
              continue;
            }
            else if (s[i]=='X' && s[i+1]=='C')
            {
              sum+=90;
              i++;
              continue;
            }
            else if (s[i]=='C' && s[i+1]=='D')
            {
              sum+=400;
              i++;
              continue;
            }
            else if (s[i]=='C' && s[i+1]=='M')
            {
              sum+=900;
              i++;
              continue;
            }
            else
            {
                if(s[i]=='I') sum+=1;
                else if  (s[i]=='V') sum+=5;
                else if (s[i]=='X') sum+=10;
                else if (s[i]=='L') sum+=50;
                else if (s[i]=='C') sum+=100;
                else if (s[i]=='D') sum+=500;
                else if (s[i]=='M') sum+=1000;
            }
        }
         return sum;
    }
};

int main()
{
  Solution object;
  int ans;
  ans=object.romanToInt("CLXVII");
  cout<<"Ans is "<<ans;
  return 0;
}
  
