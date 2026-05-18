class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = 0;

        for (auto x : piles) {
            r = max(r, x);
        }

        int ans = r;

        while (l <= r) {
            int k = l + (r - l) / 2;

            long long hours = 0;

            for (int bananas : piles) {
                hours += (bananas + k - 1) / k; // ceil division
            }

            if (hours <= h) {
                ans = k;
                r = k - 1;
            } else {
                l = k + 1;
            }
        }

        return ans;
    }
};