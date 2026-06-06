class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;

    void dfs(vector<int>& nums, int start, int target) {
        if (target == 0) {
            ans.push_back(temp);
            return;
        }

        for (int i = start; i < nums.size(); i++) {
            if (i > start && nums[i] == nums[i - 1])
                continue;          // skip duplicates

            if (nums[i] > target)
                break;

            temp.push_back(nums[i]);
            dfs(nums, i + 1, target - nums[i]);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        dfs(nums, 0, target);
        return ans;
    }
};