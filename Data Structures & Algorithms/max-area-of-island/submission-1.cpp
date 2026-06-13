class Solution {
public:
    void dfs(vector<vector<int>>&grid, int x, int y, int n, int m, int& res){
        if(x>=n||x<0||y>=m||y<0||!grid[x][y]) return;
        res++;
        grid[x][y]=0;
        dfs(grid,x+1,y,n,m,res);
        dfs(grid,x,y+1,n,m,res);
        dfs(grid,x-1,y,n,m,res);
        dfs(grid,x,y-1,n,m,res);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]){
                    int res = 0;
                    dfs(grid,i,j,n,m,res);
                    ans=max(res,ans);
                }
            }
        }
        return ans;
    }
};
