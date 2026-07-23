class Solution {
    vector<vector<int>>dp;
    int solveRec(vector<int>&coins,int amount,int idx){
        if(amount==0){
            return 1;
        }
        if(idx<0) return 0;
        if(dp[amount][idx]!=-1){
            return dp[amount][idx];
        }
        if(amount>=coins[idx]){
            return dp[amount][idx]=solveRec(coins,amount-coins[idx],idx)+solveRec(coins,amount,idx-1);
        }
        return dp[amount][idx]=solveRec(coins,amount,idx-1);
    }
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        dp=vector<vector<int>>(amount+1,vector<int>(n+1,-1));
        return solveRec(coins,amount,n-1);
    }
};
