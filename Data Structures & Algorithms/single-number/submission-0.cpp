class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int xort = 0;
        for(auto x:nums){
            xort = xort^x;
        }
        return xort;
    }
};
