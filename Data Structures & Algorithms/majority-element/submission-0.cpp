class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 1;
        int maj = nums[0];
        int n = nums.size();
        for(int i=1;i<n;i++){
            if(nums[i]==maj){
                count++;
            }
            else{
                count--;
            }
            if(count == 0){
                maj=nums[i];
                count = 1;
            }
        }
        count = 0;
        for(int i=0;i<n;i++){
            if(nums[i]==maj){
                count++;
            }
        }
        return count>n/2?maj:-1;
    }
};