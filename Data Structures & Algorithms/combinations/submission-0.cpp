class Solution {
    vector<int>temp;
public:
    void solveRec(int x, int n, int k,vector<vector<int>>&res){
        if(k==0){
            res.push_back(temp);
            return;
        }
        if(x>n){
            return;
        }
        temp.push_back(x);
        solveRec(x+1,n,k-1,res);
        temp.pop_back();
        solveRec(x+1,n,k,res);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>res;
        solveRec(1,n,k,res);
        return res;
    }
};