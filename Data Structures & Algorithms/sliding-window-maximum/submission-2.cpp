class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>dq;
        vector<int>res;
        for(int i=0;i<nums.size();i++){
            // clearing previous window
            while(!dq.empty() && dq.front()<=i-k){
                dq.pop_front();
            }

            // try to fit this element
            while(!dq.empty() && nums[dq.back()]<=nums[i]){
                dq.pop_back();
            }
            dq.push_back(i);

            if(i>=k-1)
            // get the max element which is at front of deque!
            res.push_back(nums[dq.front()]);
        }
        return res;
    }
};
