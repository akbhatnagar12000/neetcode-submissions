class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int l = *max_element(nums.begin(), nums.end());
        int r = accumulate(nums.begin(), nums.end(), 0);

        int ans = r;

        while (l <= r) {
            int m = l + (r - l) / 2;

            int parts = 1;
            int currSum = 0;

            for (int x : nums) {
                if (currSum + x <= m) {
                    currSum += x;
                } else {
                    parts++;
                    currSum = x;
                }
            }

            if (parts <= k) {
                ans = m;
                r = m - 1;
            } else {
                l = m + 1;
            }
        }

        return ans;
    }
};