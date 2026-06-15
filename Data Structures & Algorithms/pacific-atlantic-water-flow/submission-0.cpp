class Solution {
    vector<pair<int, int>> directions = {{1, 0}, {-1, 0},
                                         {0, 1}, {0, -1}};
    void bfs(queue<pair<int,int>>&q, vector<vector<bool>>&ocean,
    vector<vector<int>>&heights){
        while(!q.empty()){
            auto [r,c] = q.front();q.pop();
            ocean[r][c]=true;
            for(auto [dr,dc]:directions){
                int nr = r+dr, nc=c+dc;
                if(nr>=0 && nr<heights.size() && nc>=0 && nc<heights[0].size()
                &&heights[nr][nc]>=heights[r][c] && !ocean[nr][nc]){
                    q.push({nr,nc});
                }
            }
        }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int ROWS = heights.size(), COLS = heights[0].size();
        vector<vector<bool>>pac(ROWS, vector<bool>(COLS,false));   
        vector<vector<bool>>alt(ROWS, vector<bool>(COLS,false));

        queue<pair<int,int>>pacQueue,altQueue;
        for(int c=0;c<COLS;c++){
            pacQueue.push({0,c});
            altQueue.push({ROWS-1,c});
        } 
        for(int r=0;r<ROWS;r++){
            pacQueue.push({r,0});
            altQueue.push({r,COLS-1});
        }
        bfs(pacQueue,pac,heights);
        bfs(altQueue,alt,heights);
        vector<vector<int>>res;
        for(int r=0;r<ROWS;r++){
            for(int c=0;c<COLS;c++){
                if(pac[r][c] && alt[r][c]){
                    res.push_back({r,c});
                }
            }
        }
        return res;
    }
};
