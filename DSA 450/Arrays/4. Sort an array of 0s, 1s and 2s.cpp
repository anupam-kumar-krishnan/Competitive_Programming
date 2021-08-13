 int maxSubarraySum(int a[], int n){
        
        long long maxh = 0, maxf = INT_MIN;
        
        for(int i=0;i<n;i++) 
            {
                maxh+=a[i];               
                maxf=max(maxh,maxf);                 
                if(maxh<0)
                    maxh=0;
            }
     
            return maxf; 
    }
