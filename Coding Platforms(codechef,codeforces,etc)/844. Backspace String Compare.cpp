class Solution {
public:
    bool backspaceCompare(string s, string t) {
        
        string a=""; 
        string b="";
        
        for(char c : s)  
        {
            if(c == '#' && a.length())
            {
                a.pop_back();
            }
            else if(c != '#') 
            {
                a.push_back(c);
            }
        }
        
        for(char c : t)  
        {
            if(c == '#' && b.length())
            {
                b.pop_back();
            }
            else if(c != '#')
            {
                b.push_back(c);
            }
        }
           
        
        if(a == b)
            return true;
        else
            return false;
        
    }
};
