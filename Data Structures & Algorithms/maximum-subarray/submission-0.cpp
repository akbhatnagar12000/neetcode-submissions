class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sub_res=nums[0];
        int res=nums[0];
        for(int i=1;i<nums.size();i++){
            sub_res=max(sub_res+nums[i],nums[i]);
            res=max(res,sub_res);
        }
        return res;
    }
};
