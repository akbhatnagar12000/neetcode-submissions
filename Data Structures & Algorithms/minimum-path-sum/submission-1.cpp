class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<>>pq;
        pq.push({grid[0][0],0,0});
        while(!pq.empty()){
            auto p = pq.top();
            pq.pop();
            int s = get<0>(p);
            int x = get<1>(p);
            int y = get<2>(p);
            if(x==n-1 && y==m-1){
                return s;
            }
            if(x+1<n){
                pq.push({s+grid[x+1][y],x+1,y});
            }
            if(y+1<m){
                pq.push({s+grid[x][y+1],x,y+1});
            }
        }
        return -1;
    }
};