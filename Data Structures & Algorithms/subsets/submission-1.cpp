class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        set<vector<int>>st;
        int n = nums.size();
        for(int i=0;i<(1<<n);i++){
            vector<int>sub_res;
            for(int j=0;j<n;j++){
                if(i&(1<<j)){
                    sub_res.push_back(nums[j]);
                }
            }
            st.insert(sub_res);
        }
        vector<vector<int>>res;
        for(auto x:st){
            res.push_back(x);
        }
        return res;
    }
};
