class Solution {
public:
    int strStr(string haystack, string needle) {
        string str=haystack;
        string sub_str=needle;
        int index=str.find(sub_str);
        return index;
        return -1;
    }
};