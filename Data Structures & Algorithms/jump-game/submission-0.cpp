class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReach = nums[0];
        for(int i=1;i<nums.size();i++){
            if(maxReach<i){
                return false;
            }
            maxReach=max(maxReach,nums[i]+i);
        }
        return true;
    }
};
