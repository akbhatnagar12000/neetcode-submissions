class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>>best(n,vector<int>(m,INT_MAX));
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        pq.push({0,0,0}); // effort, x,y;
        vector<vector<int>>dir={{-1,0},{1,0},{0,-1},{0,1}};
        while(!pq.empty()){
            auto p = pq.top();
            pq.pop();
            int currEffort = p[0];
            int x = p[1];
            int y = p[2];

            if(x==n-1 && y==m-1){
                return currEffort;
            }

            if(currEffort>best[x][y]) continue; // essential!
            
            for(auto d:dir){
                int nx = x+d[0];
                int ny = y+d[1];
                if(nx<0||nx>=n||ny<0||ny>=m) continue;
                int newEffort = max(currEffort,abs(heights[x][y]-heights[nx][ny]));
                if(newEffort<best[nx][ny]){
                    best[nx][ny]=newEffort;
                    pq.push({newEffort,nx,ny});
                }
            }
        }
        return 0;
    }
};