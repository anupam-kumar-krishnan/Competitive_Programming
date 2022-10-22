#include<iostream> 
#include<vector>
#include<string>
using namespace std;

vector<string> getKeypad(string s, string code[]){  // 678
    if(s.length() == 0){
        vector<string> base;
        base.push_back("");
        return base;
    }
    char ch = s[0];  //6
    string res = s.substr(1); // 78

    vector<string> rres = getKeypad(res, code);  // 6 word for 78
    vector<string> ans; // 24 word for 678
    string codeforch = code[ch-'0'];
    for(int i = 0; i < codeforch.length(); i++){
        char chcode = codeforch[i];
        for(int i = 0; i < rres.size(); i++){
            ans.push_back(chcode + rres[i]);
        }
    }
    return ans; 
}

int main(){
    string code[] = {".;", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tu", "vwx", "yz"};
    string s;
    cin >> s;
    vector<string> ans = getKeypad(s, code);
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i]<<" ";
    }
    return 0;
}