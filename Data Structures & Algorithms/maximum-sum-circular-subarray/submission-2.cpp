class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int total = 0;
        for(auto x:nums){
            total+=x;
        }
        int sub_res = nums[0];
        int res = nums[0];
        for(int i=1;i<nums.size();i++){
            sub_res=min(nums[i],sub_res+nums[i]);
            res=min(res,sub_res);
        }
        int maxRes=nums[0];
        sub_res=nums[0];
        for(int i=1;i<nums.size();i++){
            sub_res=max(sub_res+nums[i],nums[i]);
            maxRes=max(sub_res,maxRes);
        }
        if(total!=res)
            return max(maxRes,total-res);
        else
            return maxRes;
    }
};