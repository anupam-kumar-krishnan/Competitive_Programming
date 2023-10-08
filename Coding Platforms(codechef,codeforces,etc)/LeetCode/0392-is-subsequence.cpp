class Solution {
   public:
   bool isSubsequence(string t, string s) {
      if(s == t)
      return true;
      int n = s.size();
      int m = t.size();
      int j = 0;
      for(int i = 0; i < n; i++){
         if(t[j] == s[i])
         j++;
         if(j == t.size())
         return true;
      }
      return false;
   }
};
