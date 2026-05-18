class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int lrow=0,rrow=n-1;
        while(lrow<=rrow){
            int mrow = lrow + (rrow-lrow)/2;
            if(target>=matrix[mrow][0] && target<=matrix[mrow][m-1]){
                int lcol = 0, rcol = m-1;
                while(lcol<=rcol){
                    int mcol = lcol + (rcol-lcol)/2;
                    if(matrix[mrow][mcol]==target){
                        return true;
                    }
                    else if(matrix[mrow][mcol]>target){
                        rcol=mcol-1;
                    }
                    else{
                        lcol=mcol+1;
                    }
                }
                return false;
            }
            else if(target<matrix[mrow][0]){
                rrow=mrow-1;
            }
            else{
                lrow=mrow+1;
            }
        }
        return false;
    }
};
