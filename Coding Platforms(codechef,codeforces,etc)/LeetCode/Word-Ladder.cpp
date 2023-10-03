class Solution {
public:
    int ladderLength(string startWord, string targetWord, vector<string>& wordList){
        queue<pair<string,int>>q;
        q.push({startWord,1});
        unordered_set<string>s(wordList.begin(),wordList.end());
        s.erase(startWord);
        while(!q.empty()){
            string word=q.front().first;
            int steps=q.front().second;
            q.pop();
            if(word==targetWord) return steps;
            for(int i=0;i<word.size();i++){
                char original=word[i];
                for(char j='a'; j<='z';j++){
                    word[i]=j;  
                    if(s.find(word)!=s.end()){
                        s.erase(word);
                        q.push({word,steps+1});
                    }
                }
                word[i]=original;
            }
        }
        return 0;
        
    }
};
