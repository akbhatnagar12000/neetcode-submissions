class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        unordered_set<int>st;
        unordered_map<int,int>trusted;
        for(auto x:trust){
            st.insert(x[0]);
            trusted[x[1]]++;
        }
        if(st.size()==n) return -1;
        for(int i=1;i<=n;i++){
            if(st.find(i)==st.end() && trusted.find(i)!=trusted.end() && trusted[i]==n-1){
                return i;
            }
        }
        return -1;
    }
};