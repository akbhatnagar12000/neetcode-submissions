class Solution {
    vector<string>res;
    string temp;
    unordered_set<string>st;
public:
    void solveRec(string &s , int idx){
        if(idx==s.length()){
            res.push_back(temp);
            return;
        }
        string prev = temp;
        string sub = "";
        for(int i=idx;i<s.length();i++){
            sub.push_back(s[i]);
            if(st.find(sub)!=st.end()){
                if(temp.empty()){
                    temp=sub;
                }
                else{
                    temp+=" ";
                    temp+=sub;
                }
                solveRec(s,i+1);
                temp = prev;
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for(auto x:wordDict){
            st.insert(x);
        }   
        solveRec(s,0);
        return res;
    }
};