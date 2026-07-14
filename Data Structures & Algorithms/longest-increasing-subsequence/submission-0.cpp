class Solution {
    map<pair<int,int>,int>dp;
    int solveRec(vector<int>&nums,int idx, int limit){
        if(idx<0){
            return 0;
        }
        if(dp.find({idx,limit})!=dp.end()){
            return dp[{idx,limit}];
        }
        if(nums[idx]<limit){
            return dp[{idx,limit}]=max(solveRec(nums,idx-1,limit),1+solveRec(nums,idx-1,nums[idx]));
        }
        return dp[{idx,limit}]=solveRec(nums,idx-1,limit);
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        return solveRec(nums,n-1,1001);
    }
};
