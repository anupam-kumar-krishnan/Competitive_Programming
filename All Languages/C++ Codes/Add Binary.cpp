  string addBinary(string a, string b) {
        string s="";
        int n=a.size()-1, m=b.size()-1, carry=0;
        while(n>=0 || m>=0 || carry){
            int sum=(n>=0? (a[n]-'0') : 0) + (m>=0? (b[m]-'0') : 0) + carry;
            carry=(sum>1)? 1:0;
            if(sum>1) sum%=2;
            s+=(sum+'0');
            n--,m--;
        }
        reverse(s.begin(),s.end());
        return s;
    }
