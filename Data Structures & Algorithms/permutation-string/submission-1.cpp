class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s2.length()<s1.length()) return false;

        map<int,int>mp1,mp2;
        for(auto x:s1){
            mp1[x]++;
        }
        int i=0;
        for(;i<s1.length();i++){
            mp2[s2[i]]++;
        }
        if(mp1==mp2) return true;
        int k = s1.length();
        for(;i<s2.length();i++){
            mp2[s2[i-k]]--;
            if(mp2[s2[i-k]]==0){
                mp2.erase(s2[i-k]);
            }
            mp2[s2[i]]++;
            if(mp1==mp2) return true;
        }
        return false;
    }
};
