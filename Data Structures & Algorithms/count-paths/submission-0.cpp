class Solution {
    map<pair<int,int>,int>dp;
    int solveRec(int x, int y, int m, int n){
        if(x==m-1 && y==n-1){
            return 1;
        }
        if(x>=m || y>=n){
            return 0;
        }
        if(dp.find({x,y})!=dp.end()){
            return dp[{x,y}];
        }
        int ans = 0;
        ans+=solveRec(x+1,y,m,n);
        ans+=solveRec(x,y+1,m,n);
        return dp[{x,y}]=ans;
    }
public:
    int uniquePaths(int m, int n) {
        return solveRec(0,0,m,n);
    }
};
