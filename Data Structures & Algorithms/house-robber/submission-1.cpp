class Solution {
    unordered_map<int,int>dp;
    int solveRec(vector<int>&nums, int idx){
        if(idx<0){
            return 0;
        }
        if(dp.find(idx)!=dp.end()){
            return dp[idx];
        }
        return dp[idx]=max(solveRec(nums,idx-2)+nums[idx],solveRec(nums,idx-1));
    }
public:
    int rob(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        return solveRec(nums,n-1);
    }
};
