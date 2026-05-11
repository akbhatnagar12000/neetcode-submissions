class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        for(int j=0;j<nums.size();j++){
            if(mp.find(nums[j])!=mp.end()){
                if(abs(j-mp[nums[j]])<=k)
                    return true;
            }
            mp[nums[j]]=j;
        }
        return false;
    }
};