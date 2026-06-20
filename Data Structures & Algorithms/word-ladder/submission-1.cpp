class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>st(wordList.begin(),wordList.end());
        if(st.find(endWord)==st.end()){
            return 0;
        }
        if(beginWord==endWord){
            return 1;
        }

        queue<string>q;
        int moves = 0;
        q.push(beginWord);
        while(!q.empty()){
            ++moves;
            int sz = q.size();
            for(int i=0;i<sz;i++){
                auto s = q.front();
                q.pop();
                if(s==endWord){
                    return moves;
                }
                for(int i=0;i<s.size();i++){
                    char ch = s[i];
                    for(int c=0;c<26;c++){
                        if(c+'a'!=ch){
                            s[i]=c+'a';
                            if(st.find(s)!=st.end()){
                                q.push(s);
                                st.erase(s);
                            }
                            s[i]=ch;
                        }
                    }
                }
            }
        }
        return 0;
    }
};
