class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        int i=0,j=n-1;
        while(i<j){
            for(int z=0;z<n;z++){
                swap(matrix[z][i],matrix[z][j]);
            }
                i++,j--;
        }
    }
};
