class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int left=0,mid=0,right=n-1;
        while(mid<=right){
            switch(nums[mid]){
                case 0:
                    swap(nums[left],nums[mid]);
                    left++;
                    mid++;
                    break;
                case 1:
                    mid++;
                    break;
                case 2:
                    swap(nums[mid],nums[right]);
                    right--;
            }
        }
    }
};