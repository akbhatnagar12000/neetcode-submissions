class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int fresh = 0;
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2)
                    q.push({i,j});
                else if(grid[i][j]==1){
                    fresh++;
                }
            }
        }
        if(fresh==0) return 0;
        vector<vector<int>>dir = {{-1,0},{1,0},{0,-1},{0,1}};
        int timer = 0;
        while(!q.empty()){
            int sz = q.size();
            for(int i=0;i<sz;i++)
            {
                auto [x,y] = q.front();
                q.pop();
                for(int i=0;i<4;i++){
                    int nx = x+dir[i][0];
                    int ny = y+dir[i][1];

                    if(nx<0||nx>=n||ny<0||ny>=m){
                        continue;
                    }
                    if(!grid[nx][ny] || grid[nx][ny]==2){
                        continue;
                    }
                    if(grid[nx][ny]==1){
                        grid[nx][ny]=2;
                        q.push({nx,ny});
                    }
                }
            }
            timer++;
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        return timer-1;
    }
};
