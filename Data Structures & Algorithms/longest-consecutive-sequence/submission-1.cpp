class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int>st;
        for(auto x:nums){
            st.insert(x);
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            if(st.find(nums[i]-1)!=st.end()) continue;
            int count = 1;
            int curr = nums[i]+1;
            while(st.find(curr)!=st.end()){
                count++;
                curr++;
            }
            ans=max(ans,count);
        }
        return ans;
    }
};
