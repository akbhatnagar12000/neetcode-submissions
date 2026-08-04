class Solution {
    map<pair<int,int>, int> dp;

    int solve(string &a, string &b, int i, int j) {

        if(i < 0) return j + 1;
        if(j < 0) return i + 1;

        if(dp.count({i,j}))
            return dp[{i,j}];

        if(a[i] == b[j])
            return dp[{i,j}] = solve(a, b, i-1, j-1);

        return dp[{i,j}] = 1 + min({
            solve(a, b, i-1, j),    // Delete
            solve(a, b, i, j-1),    // Insert
            solve(a, b, i-1, j-1)   // Replace
        });
    }

public:
    int minDistance(string word1, string word2) {
        return solve(word1, word2, word1.size()-1, word2.size()-1);
    }
};