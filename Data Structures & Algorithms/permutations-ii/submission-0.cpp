class Solution {
    set<vector<int>>st;
public:
    void solveRec(int idx, int n, vector<int>&nums){
        if(idx>=n){
            st.insert(nums);
            return;
        }
        for(int i=idx;i<n;i++){
            swap(nums[i],nums[idx]);
            solveRec(idx+1,n,nums);
            swap(nums[i],nums[idx]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());   
        vector<vector<int>>res;
        int n = nums.size();
        solveRec(0,n,nums);
        for(auto x:st){
            res.push_back(x);
        }
        return res;
    }
};