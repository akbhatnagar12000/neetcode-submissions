class Solution {
    map<pair<int,int>,bool>mp;
    bool solveRec(vector<int>&nums, int idx, int sum){
        if(sum==0){
            return true;
        }
        if(idx<0){
            return false;
        }
        if(mp.find({sum,idx})!=mp.end()){
            return mp[{sum,idx}];
        }
        if(nums[idx]<=sum){
            return mp[{sum,idx}]=solveRec(nums,idx-1,sum-nums[idx])|solveRec(nums,idx-1,sum);
        }
        return mp[{sum,idx}]=solveRec(nums,idx-1,sum);
    }
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto x:nums){
            sum+=x;
        }
        if(sum%2) return false;
        sum/=2;
        int n = nums.size();
        return solveRec(nums,n-1,sum);
    }
};
