class Solution {
    int n,m;
    vector<vector<int>>dp;
    vector<vector<int>> directions = {{-1, 0}, {1, 0},
                                      {0, -1}, {0, 1}};
    int solveRec(vector<vector<int>>&matrix, int x, int y, int prevVal){
        if(x<0||x>=n||y<0||y>=m||matrix[x][y]<=prevVal){
            return 0;
        }
        if(dp[x][y]!=-1){
            return dp[x][y];
        }
        int res = 1;
        for(auto d:directions){
            res = max(res,1+solveRec(matrix,x+d[0],y+d[1],matrix[x][y]));
        }
        return dp[x][y]=res;
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        n = matrix.size();
        m = matrix[0].size();
        dp=vector<vector<int>>(n,vector<int>(m,-1));
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans = max(ans,solveRec(matrix,i,j,INT_MIN));
            }
        }
        return ans;
    }
};
