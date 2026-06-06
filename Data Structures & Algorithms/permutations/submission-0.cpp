class Solution {
public:
    void solveRec(int idx, int n, vector<int>&nums, vector<vector<int>>&res){
        if(idx>=n){
            res.push_back(nums);
            return;
        }
        for(int i=idx;i<n;i++){
            swap(nums[i],nums[idx]);
            solveRec(idx+1,n,nums,res);
            swap(nums[i],nums[idx]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>res;
        int n = nums.size();
        solveRec(0,n,nums,res);
        return res;
    }
};
