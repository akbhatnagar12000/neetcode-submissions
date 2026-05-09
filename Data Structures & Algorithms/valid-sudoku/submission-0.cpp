class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        // row validation
        for(int i=0;i<n;i++){
            unordered_set<int>st;
            for(int j=0;j<m;j++){
                if(board[i][j]=='.') continue;
                if(st.find(board[i][j])!=st.end()||board[i][j]>'9'||board[i][j]<'1'){
                    return false;
                }
                st.insert(board[i][j]);
            }
        }

        // col validation
        for(int i=0;i<m;i++){
            unordered_set<int>st;
            for(int j=0;j<n;j++){
                if(board[j][i]=='.') continue;
                if(st.find(board[j][i])!=st.end()||board[j][i]>'9'||board[j][i]<'1'){
                    return false;
                }
                st.insert(board[j][i]);
            }
        }

        // 3x3 cubes
        for(int i=0;i<n;i+=3){
            for(int j=0;j<m;j+=3){
                unordered_set<int>st;
                for(int r=0;r<3;r++){
                    for(int c=0;c<3;c++){
                        if(board[i+r][j+c]=='.') continue;
                        if(st.find(board[i+r][j+c])!=st.end()||board[i+r][j+c]>'9'||board[i+r][j+c]<'1'){
                            return false;
                        }
                        st.insert(board[i+r][j+c]);
                    }
                }
            }
        }

        return true;
    }
};
