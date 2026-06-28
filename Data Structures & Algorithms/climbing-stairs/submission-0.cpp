class Solution {
    unordered_map<int,int>mp;
public:
    int climbStairs(int n) {
        if(n<=1) return 1;
        if(mp.find(n)!=mp.end()){
            return mp[n];
        }
        return mp[n]=climbStairs(n-1)+climbStairs(n-2);
    }
};
