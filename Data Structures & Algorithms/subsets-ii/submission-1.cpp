class Solution {
    set<vector<int>>st;
    vector<int>temp;
public:
    void solveRec(int idx, vector<int>&nums){
        if(idx<0){
            st.insert(temp);
            return;
        }
        temp.push_back(nums[idx]);
        solveRec(idx-1,nums);
        temp.pop_back();
        solveRec(idx-1,nums);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>res;
        int n = nums.size();
        solveRec(n-1,nums);
        for(auto x:st){
            res.push_back(x);
        }
        return res;
    }
};
