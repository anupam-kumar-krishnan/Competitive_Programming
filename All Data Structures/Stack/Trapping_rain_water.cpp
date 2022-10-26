//Problem Link: https://leetcode.com/problems/trapping-rain-water/

//Solution
#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        stack<int> st;
        int maxWater = 0;
            
        for(int i=0; i<n; i++)
        {
            //one of the possible container
            while(!st.empty() && height[i] > height[st.top()])
            {
                int curr = st.top(); 
                st.pop();
                //no block on left side hence no container
                if(st.empty())
                    break;                
        
                int d = i-st.top()-1;
                int h = min(height[i],height[st.top()]) - height[curr];
                
                maxWater += d*h;
            }    
            st.push(i);
        }
        return maxWater;
    }   
};