class Solution {
    unordered_map<int,int>dp;
    int solveRec(vector<int>&nums, int st, int en){
        if(st>en){
            return 0;
        }
        if(dp.find(en)!=dp.end()){
            return dp[en];
        }
        return dp[en]=max(solveRec(nums,st,en-2)+nums[en],solveRec(nums,st,en-1));
    }
public:
    int robrec(vector<int>& nums,int st, int en) {
        dp.clear();
        return solveRec(nums,st,en);
    }
    int rob(vector<int>& nums){
        int n = nums.size();
        if(n==1){
            return nums[0];
        }
        // solve like two linear problem
        // [1,....,n-1] -> excludes first house
        // [0,....,n-2] -> includes first house
        return max(robrec(nums,1,n-1),robrec(nums,0,n-2));
    }
};
