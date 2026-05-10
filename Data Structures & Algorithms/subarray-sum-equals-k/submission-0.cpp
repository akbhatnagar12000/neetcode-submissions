class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int pre_sum = 0;
        unordered_map<int,int>mp;
        int ans = 0;
        mp[0]=1;
        for(auto x:nums){
            pre_sum+=x;
            ans+=mp[pre_sum-k];
            mp[pre_sum]++;
        }
        return ans;
    }
};