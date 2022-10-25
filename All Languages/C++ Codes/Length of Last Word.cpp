  int lengthOfLastWord(string s) {
        int count=0, i=s.size();
        while(s[--i]==' ');
        while(i>=0 && s[i--]!=' ')
            count++;     
        return count;
 }
