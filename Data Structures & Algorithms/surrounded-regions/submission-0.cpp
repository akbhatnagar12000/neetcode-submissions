class Solution {
public:
    void solve(vector<vector<char>>& board) {
        set<pair<int,int>>st;
        int n = board.size();
        int m = board[0].size();
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            if(board[i][0]=='O'){
                q.push({i,0});
            }
            if(board[i][m-1]=='O'){
                q.push({i,m-1});
            }
        }
        for(int j=0;j<m;j++){
            if(board[0][j]=='O'){
                q.push({0,j});
            }
            if(board[n-1][j]=='O'){
                q.push({n-1,j});
            }
        }
        vector<vector<int>>dir = {{0,-1},{0,1},{-1,0},{1,0}};
        while(!q.empty()){
            auto [x,y]=q.front();
            st.insert({x,y});
            q.pop();
            for(auto d:dir){
                int nx = x+d[0];
                int ny = y+d[1];
                if(nx<0||nx>=n||ny<0||ny>=m||board[nx][ny]=='X') continue;
                board[nx][ny]='X';
                q.push({nx,ny});
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O'){
                    if(st.find({i,j})==st.end()){
                        board[i][j]='X';
                    }
                }
            }
        }
        for(auto x:st){
            board[x.first][x.second]='O';
        }
    }
};
