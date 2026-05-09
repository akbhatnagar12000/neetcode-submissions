class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int streak=prices[0];
        int n=prices.size();
        int maxi=prices[0];
        int total=0;
        for(int i=1;i<n;i++){
            if(maxi>prices[i]){
                total+=(maxi-streak);
                streak=prices[i];
                maxi=prices[i];
            }
            else{
                maxi=max(maxi,prices[i]);
            }
        }
        total+=maxi-streak;
        return total;
    }
};