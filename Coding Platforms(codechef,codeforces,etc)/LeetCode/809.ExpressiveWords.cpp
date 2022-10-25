class Solution
{
public:
    int expressiveWords(string S, vector<string> &words)
    {
        int res = 0;
        for (auto &W : words)
            if (check(S, W))
                res++;
        return res;
    }

    bool check(string S, string W)
    {
        int n = S.size(), m = W.size(), j = 0;
        for (int i = 0; i < n; i++)
            if (j < m && S[i] == W[j])
                j++;
            else if (i > 1 && S[i - 2] == S[i - 1] && S[i - 1] == S[i])
                ;
            else if (0 < i && i < n - 1 && S[i - 1] == S[i] && S[i] == S[i + 1])
                ;
            else
                return false;
        return j == m;
    }
};