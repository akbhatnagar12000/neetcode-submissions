class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        set<tuple<int,int,int>> s;
        sort(nums.begin(), nums.end());

        int n = nums.size();

        for(int i = 0; i < n; i++) {

            if(i > 0 && nums[i] == nums[i-1]) {
                continue;
            }

            int left = i + 1;
            int right = n - 1;

            while(left < right) {

                int sum = nums[i] + nums[left] + nums[right];

                if(sum == 0) {
                    s.insert({nums[i], nums[left], nums[right]});
                    left++;
                    right--;
                }
                else if(sum > 0) {
                    right--;
                }
                else {
                    left++;
                }
            }
        }

        vector<vector<int>> res;

        for(auto x : s) {
            res.push_back({
                get<0>(x),
                get<1>(x),
                get<2>(x)
            });
        }

        return res;
    }
};