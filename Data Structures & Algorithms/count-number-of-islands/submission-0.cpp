class Solution {
public:
    void dfs(vector<vector<char>>&grid, int x, int y, int n, int m){
        if(x>=n||x<0||y>=m||y<0||grid[x][y]=='0') return;
        grid[x][y]='0';
        dfs(grid,x+1,y,n,m);
        dfs(grid,x,y+1,n,m);
        dfs(grid,x-1,y,n,m);
        dfs(grid,x,y-1,n,m);
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    ans++;
                    dfs(grid,i,j,n,m);
                }
            }
        }
        return ans;
    }
};
