class Solution {
    set<multiset<int>>st;
    multiset<int>temp;
public:
    void solveRec(int idx, vector<int>&nums){
        if(idx<0){
            st.insert(temp);
            return;
        }
        auto it = temp.insert(nums[idx]);
        solveRec(idx-1,nums);
        temp.erase(it);
        solveRec(idx-1,nums);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>res;
        int n = nums.size();
        solveRec(n-1,nums);
        for(auto x:st){
            vector<int>sub_res;
            for(auto y:x){
                sub_res.push_back(y);
            }
            res.push_back(sub_res);
        }
        return res;
    }
};
