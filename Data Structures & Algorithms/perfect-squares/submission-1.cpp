class Solution {
private:
    unordered_map<int, int> memo;

public:
    int numSquares(int n) {
        memo[0] = 1;
        return dfs(n);
    }

    int dfs(int n) {
        if(n<=0){
            return 0;
        }
        
        if(memo.find(n)!=memo.end()){
            return memo[n];
        }

        int res = INT_MAX;
        for (int i=sqrt(n);i>=1;i--) {
            int sub_res=INT_MAX;
            sub_res = 1+dfs(n-i*i);
            res=min(sub_res,res);
        }

        memo[n] = res;
        return res;
    }
};