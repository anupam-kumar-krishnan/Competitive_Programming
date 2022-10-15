class Solution {
public:
    int solve(int n,vector<string>&w,unordered_map<char,int>&m,vector<int>&score){
         if(n<0) return 0;
         bool flag=true;
         int sr=0;
         for(auto x:w[n]){
             if(!m[x]) flag=false;
                 m[x]--;sr+=score[x-'a'];
         }
         int a=0,b=0;
         if(flag) a=sr+solve(n-1,w,m,score);
         for(auto x:w[n]) m[x]++;
         b=solve(n-1,w,m,score);
         return max(a,b);    
    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        unordered_map<char,int>m;
        for(auto x: letters) m[x]++;
        return solve(words.size()-1,words,m,score);
    }
};
