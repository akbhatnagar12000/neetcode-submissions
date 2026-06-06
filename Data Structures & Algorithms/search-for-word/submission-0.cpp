class Solution {
public:
    bool searched(vector<vector<char>>&board, int x, int y, int n, int m, 
    string& word, int idx, vector<vector<bool>>&vis){
        if(idx==word.length()){
            return true;
        }
        if(x<0||x>=n||y<0||y>=m||vis[x][y]||word[idx]!=board[x][y]){
            return false;
        }
        vis[x][y]=true;
        bool ans = searched(board,x+1,y,n,m,word,idx+1,vis);
        ans|=searched(board,x,y+1,n,m,word,idx+1,vis);
        ans|=searched(board,x,y-1,n,m,word,idx+1,vis);
        ans|=searched(board,x-1,y,n,m,word,idx+1,vis);
        vis[x][y]=false;
        return ans;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(searched(board,i,j,n,m,word,0,vis)){
                    return true;
                }
            }
        }
        return false;
    }
};
