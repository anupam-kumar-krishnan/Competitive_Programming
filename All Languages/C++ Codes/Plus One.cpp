    vector<int> plusOne(vector<int>& digits) {
        int idx=0,carry=0,flag=false;
        reverse(digits.begin(),digits.end());
        while(carry>0 || digits.size()>idx)
        {
            if(digits.size()==idx){
                digits.resize(digits.size()+1);
            }
            if(!flag){
                int num=digits[idx]+1+carry;
                digits[idx]=num%10;
                carry=num/10;
                flag=true;
                idx++;
                continue;
            }
            int num=digits[idx]+carry;
            digits[idx]=num%10;
            carry=num/10;
                    
            idx++;
        }
        reverse(digits.begin(),digits.end());
        return digits;
    }
