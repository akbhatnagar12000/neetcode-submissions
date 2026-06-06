class Solution {
public:
    void solveRec(vector<int>&nums, int idx, int target, set<vector<int>>&st,
    vector<int>&temp)
    {
        if(target==0){
            st.insert(temp);
            return;
        }
        if(idx<0){
            return;
        }  
        if(nums[idx]<=target){
            temp.push_back(nums[idx]);
            solveRec(nums,idx,target-nums[idx],st,temp);
            solveRec(nums,idx-1,target-nums[idx],st,temp);
            temp.pop_back();
            solveRec(nums,idx-1,target,st,temp);
        }
        else{
            solveRec(nums,idx-1,target,st,temp);
        }
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        set<vector<int>>st;
        vector<int>temp;
        int n = nums.size();
        solveRec(nums,n-1,target,st,temp);
        vector<vector<int>>res;
        for(auto x:st){
            res.push_back(x);
        }
        return res;
    }
};
