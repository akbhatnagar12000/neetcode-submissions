class Solution {
public:
    long long minEnd(int n, int x) {
        long long ans = x;
        long long k = n - 1;

        for (int b = 0; b < 63; b++) {
            if ((x & (1LL << b)) == 0) {   // free bit
                if (k & 1)
                    ans |= (1LL << b);
                k >>= 1;
                if (k == 0) break;
            }
        }

        return ans;
    }
};