class Solution {
public:
    bool dfs(int idx, vector<int>& nums,
             vector<int>& sides, int target, int k) {

        if (idx == nums.size()) {
            for(auto x:sides){
                if(x!=target){
                    return false;
                }
            }
            return true;
        }

        for (int i = 0; i < k; i++) {
            if (sides[i] + nums[idx] > target)
                continue;

            sides[i] += nums[idx];

            if (dfs(idx + 1, nums, sides, target, k))
                return true;

            sides[i] -= nums[idx];

            // pruning
            if (sides[i] == 0)
                break;
        }

        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int s = 0;
        for(auto x:nums){
            s+=x;
        }   
        if(s%k){
            return false;
        }
        sort(nums.begin(),nums.end());
        int target = s/k;

        if (nums[0] > target)
            return false;

        vector<int> sides(k, 0);

        return dfs(0, nums, sides, target, k);
    }
};