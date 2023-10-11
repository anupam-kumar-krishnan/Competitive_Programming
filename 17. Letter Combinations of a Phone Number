class Solution {
public:
    vector<string>solve(string digits,string*arr){
        if(digits.size()==0){
            vector<string>bs;
            bs.push_back("");
            return bs;
        }
      
        char c=digits[0];
        string a=arr[c-'0'];
         string smallinput=digits.substr(1);
        vector<string>rest=solve(smallinput,arr);
        vector<string>res;
        for(auto x:rest){
           for(auto x1:a){
               res.push_back(x1+x);
           } 
        }
        return res;
    }
    vector<string>ans;
    void solve2(string digits,string *arr,int i,string com){
        if(i==digits.size()){
         ans.push_back(com);
         return;
        }
         char c=digits[i];
        string a=arr[c-'0'];
        for(int k=0;k<a.size();k++){
            solve2(digits,arr,i+1,com+a[k]);
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string>a;
        if(digits.size()==0)
            return a;
        string arr[]={"0","0","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
      //  vector<string>ans=solve(digits,arr);
      solve2(digits,arr,0,"");
        return ans;
    }
};
