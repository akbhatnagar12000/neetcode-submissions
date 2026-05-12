class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<int>st;
        int ans=0;
        int i=0;
        for(int j=0;j<s.length();j++){
            while(st.find(s[j])!=st.end()){
                st.erase(s[i]);
                i++;
            }
            st.insert(s[j]);
            ans=max(ans,(int)st.size());
        }
        return ans;
    }
};
