class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        unordered_set<char>st;
        int i=0;
        int sz = INT_MAX;
        for(auto x:strs){
            int s = x.length();
            sz=min(sz,s);
        }
        int n = strs.size();
        int len = 0;
        while(i<sz){
            st.insert(strs[0][i]);
            for(int j=1;j<n;j++){
                if(st.find(strs[j][i])==st.end()){
                    if(len==0) return "";
                    return strs[0].substr(0,len);
                }
            }
            len++;
            i++;
            st.clear();
        }
        return strs[0].substr(0,sz);
    }
};