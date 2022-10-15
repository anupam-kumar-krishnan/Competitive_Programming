class Solution {
public:
    int longestValidParentheses(string s) {
        stack<pair<char,int>> st;
        int size=s.length();
        vector<int> v(size,0);
        int count=0,maxi=0;
        for(int i=0;i<size;i++){
            if(!st.empty()&&st.top().first=='('&&s[i]==')'){
                v[i]=1;v[st.top().second]=1;
                st.pop();
            }
            else    st.push({s[i],i});
        }
        for(auto x:v){
            if(x)   count++;
            else    count=0;
            maxi=max(count,maxi);
        }
        return maxi;
    }
};
