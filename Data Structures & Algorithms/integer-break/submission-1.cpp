class Solution {
private:
    unordered_map<int, int> memo;

public:
    int integerBreak(int n) {
        memo[0] = 1;
        bool first = true;
        return dfs(n,first);
    }

    int dfs(int n,bool& first) {
        if(n<=0){
            return 1;
        }
        
        if(memo.find(n)!=memo.end()){
            return memo[n];
        }

        int res = INT_MIN;
        if(first)
        {
            first = false;
            for (int i=n-1;i>=1;i--) {
                int sub_res=INT_MIN;
                sub_res = i*dfs(n-i,first);
                res=max(sub_res,res);
            }
        }
        else
        {
            for (int i=n;i>=1;i--) {
                int sub_res=INT_MIN;
                sub_res = i*dfs(n-i,first);
                res=max(sub_res,res);
            }
        }

        memo[n] = res;
        return res;
    }
};