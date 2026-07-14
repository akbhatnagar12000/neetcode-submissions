class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = nums[0];
        int sub_max = nums[0];
        int sub_min = nums[0];
        for(int i=1;i<nums.size();i++){
            int s_max=sub_max;
            int s_min=sub_min;
            sub_max=max({nums[i],s_max*nums[i],s_min*nums[i]});
            sub_min=min({nums[i],s_max*nums[i],s_min*nums[i]});
            ans=max(ans,sub_max);
        }
        return ans;
    }
};
