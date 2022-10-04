class Solution {
public:
    int reverse(int n) {
        int a=0;
        while(n!=0)
        {
            int rem=n%10;
            if(a>INT_MAX/10 || a<INT_MIN/10){
                return 0;
            }
            a=(a*10)+rem;
            n/=10;
        }
        return a;
    }
};