class Solution {
    map<pair<int,int>,int>dp;
    int solveRec(vector<vector<int>>& obstacleGrid,int x, int y, int m, int n){
        if(x==m-1 && y==n-1){
            return 1;
        }
        if(x>=m || y>=n || obstacleGrid[x][y]){
            return 0;
        }
        if(dp.find({x,y})!=dp.end()){
            return dp[{x,y}];
        }
        int ans = 0;
        ans+=solveRec(obstacleGrid,x+1,y,m,n);
        ans+=solveRec(obstacleGrid,x,y+1,m,n);
        return dp[{x,y}]=ans;
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if(m==1 && n==1){
            return obstacleGrid[0][0]==1?0:1;
        }
        return solveRec(obstacleGrid,0,0,m,n);
    }
};