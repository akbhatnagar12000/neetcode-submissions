class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char,int>mps,mpt;
        for(auto x:s){
            mps[x]++;
        }
        for(auto x:t){
            mpt[x]++;
        }
        return mps==mpt;
    }
};
