class Solution {
    int n;
    map<pair<int,bool>,int>dp;
    int solveRec(vector<int>&prices, int idx, bool buy){
        if(idx>=n){
            return 0;
        }
        if(dp.find({idx,buy})!=dp.end()){
            return dp[{idx,buy}];
        }
        if(buy){
            return dp[{idx,buy}]=max(solveRec(prices,idx+1,false)-prices[idx],solveRec(prices,idx+1,true));
        }
        else{
            return dp[{idx,buy}]=max(solveRec(prices,idx+2,true)+prices[idx],solveRec(prices,idx+1,false));
        }
    }
public:
    int maxProfit(vector<int>& prices) {
        n = prices.size();
        bool buy = true;
        return solveRec(prices,0,buy);
    }
};
