class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        for(auto x:nums){
            mp[x]++;
        }
        vector<int> res;
        set<pair<int,int>>st;
        for(auto x:mp){
            st.insert({x.second,x.first});
        }
        auto it = st.rbegin();
        while(k--){
            res.push_back(it->second);
            it++;
        }
        return res;
    }
};
