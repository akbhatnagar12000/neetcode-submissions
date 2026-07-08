class Solution {
    map<pair<int,int>,int>mp;
public:
    int solveRec(vector<int>&coins, int idx, int amount){
        if(idx<0){
            return INT_MAX;
        }
        if(amount==0){
            return 0;
        }
        if(mp.find({idx,amount})!=mp.end()){
            return mp[{idx,amount}];
        }
        int left = solveRec(coins,idx-1,amount);
        if(coins[idx]<=amount){
            int pick1 = solveRec(coins,idx,amount-coins[idx]);
            int pick2 = solveRec(coins,idx-1,amount-coins[idx]);
            if(pick1!=INT_MAX){
                pick1++;
            }
            if(pick2!=INT_MAX){
                pick2++;
            }
            return mp[{idx,amount}] = min({left,pick1,pick2});
        }
        return mp[{idx,amount}] = left;
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        int ans = solveRec(coins,n-1,amount);
        return ans==INT_MAX?-1:ans;
    }
};
