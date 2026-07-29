class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.length();
        vector<bool>dp(n,false);
        dp[0]=true;
        int reachableCount = 0;
        for (int i = 1; i < n; ++i) {
            if (i >= minJump && dp[i - minJump]) {
                reachableCount++;
            }
            if (i > maxJump && dp[i - maxJump - 1]) {
                reachableCount--;
            }
            // If s[i] is '0' and reachableCount > 0, then dp[i] = true
            if(s[i]=='0' && reachableCount>0){
                dp[i]=true;
            }
        }
        return dp[n-1];
    }
};