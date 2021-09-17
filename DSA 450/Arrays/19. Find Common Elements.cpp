class Solution
{
    public:
        vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
        {
            int i = 0, j = 0, k = 0;
            
            vector <int> res;
            int last = INT_MIN;
            while (i < n1 and j < n2 and k < n3)
            {
                if (A[i] == B[j] and A[i] == C[k] and A[i] != last) 
                {
                    res.push_back (A[i]);
                    last = A[i];
                    i++;
                    j++;
                    k++;
                }
                else if (min ({A[i], B[j], C[k]}) == A[i]) i++;
                else if (min ({A[i], B[j], C[k]}) == B[j]) j++;
                else k++;
            }
            return res;
        }

};
