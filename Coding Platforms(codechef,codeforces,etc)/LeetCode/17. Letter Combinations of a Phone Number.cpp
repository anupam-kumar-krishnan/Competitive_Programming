class Solution
{
public:
    vector<string> v = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> ans;
    void combinations(string digits, string s, int k)
    {
        if (s.length() == digits.length())
        {
            ans.push_back(s);
            return;
        }
        int number = digits[k] - '0';
        for (int i = 0; i < v[number].length(); i++)
        {
            char key = v[number][i];

            s.push_back(key);
            cout << s << endl;
            combinations(digits, s, k + 1);
            s.pop_back();
        }
    }
    vector<string> letterCombinations(string digits)
    {
        string s = "";
        combinations(digits, s, 0);
        if (digits.length() == 0)
        {
            return {};
        }
        return ans;
    }
};