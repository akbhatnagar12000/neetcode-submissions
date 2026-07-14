class Solution {
    unordered_map<int,bool>dp;
    bool solveRec(string &s, int idx, unordered_set<string>&st){
        if(idx>=s.length()){
            return true;
        }
        if(dp.find(idx)!=dp.end()){
            return dp[idx];
        }
        string res="";
        for(int i=idx;i<s.length();i++){
            res.push_back(s[i]);
            if(st.find(res)!=st.end() && solveRec(s,i+1,st)){
                return dp[idx]=true;
            }
        }
        return dp[idx]=false;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>st(wordDict.begin(),wordDict.end());
        return solveRec(s,0,st);
    }
};
