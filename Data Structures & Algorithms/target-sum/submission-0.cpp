class Solution {
    map<pair<int,int>,int>dp;
    int solveRec(vector<int>& nums, int idx, int target){
        if(idx<0){
            if(target==0){
                return 1;
            }
            return 0;
        }
        if(dp.find({idx,target})!=dp.end()){
            return dp[{idx,target}];
        }
        return dp[{idx,target}]=solveRec(nums,idx-1,target-nums[idx]) + solveRec(nums,idx-1,target+nums[idx]);
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        return solveRec(nums,n-1,target);
    }
};
