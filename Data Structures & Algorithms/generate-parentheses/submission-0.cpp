class Solution {
    string s;
    set<string>st;
public:
    void solveRec(int open, int close, int n){
        if(open<close){
            return;
        }
        if(s.length()>=2*n){
            if(open==close)
                st.insert(s);
            return;
        }
        s.push_back('(');
        solveRec(open+1,close,n);
        s.push_back(')');
        solveRec(open+1,close+1,n);
        s.pop_back();
        s.pop_back();
        s.push_back(')');
        solveRec(open,close+1,n);
        s.pop_back();
    }
    vector<string> generateParenthesis(int n) {
        solveRec(0,0,n);
        vector<string>res;
        for(auto x:st){
            res.push_back(x);
        }
        return res;
    }
};
