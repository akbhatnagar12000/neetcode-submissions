class Solution {
    map<pair<int,int>,int>dp;
    int solveRec(string& text1, string& text2, int n, int m){
        if(n<=0||m<=0){
            return 0;
        }
        if(dp.find({n,m})!=dp.end()){
            return dp[{n,m}];
        }
        if(text1[n-1]==text2[m-1]){
            return dp[{n,m}]=max({1+solveRec(text1,text2,n-1,m-1),solveRec(text1,text2,n-1,m)
            ,solveRec(text1,text2,n,m-1)});
        }
        return dp[{n,m}]=max(solveRec(text1,text2,n-1,m),solveRec(text1,text2,n,m-1));
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();
        return solveRec(text1,text2,n,m);
    }
};
