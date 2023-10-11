class Solution {
public:
    bool isValid(string s) {
        int a=0,b=0,c=0;
        stack<char>st;
        for(int i=0;i<s.size();i++){
            if(st.size()==0)st.push(s[i]);
            else {
                if(s[i]=='}'){
                    if(st.top()!='{')return false;
                    st.pop();
                }
                else if(s[i]==']'){
                    if(st.top()!='[')return false;
                    st.pop();
                }
                else if(s[i]==')'){
                    if(st.top()!='(')return false;
                    st.pop();
                }
                else st.push(s[i]);
            }
        }
        if(st.size())return false;
        return true;
    }
};
