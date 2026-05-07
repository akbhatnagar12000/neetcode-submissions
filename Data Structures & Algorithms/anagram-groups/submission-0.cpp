class Solution {
public:
    bool areAnagrams(string &a, string &b){
        map<char,int>mpa,mpb;
        for(auto x:a){
            mpa[x]++;
        }
        for(auto x:b){
            mpb[x]++;
        }
        return mpa==mpb;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>res;
        int n = strs.size();
        vector<bool>processed(n,false);
        for(int i=0;i<n;i++){
            if(processed[i]){
                continue;
            }
            vector<string>sub_res;
            sub_res.push_back(strs[i]);
            processed[i]=true;
            for(int j=i+1;j<n;j++){
                if(areAnagrams(strs[i],strs[j])){
                    sub_res.push_back(strs[j]);
                    processed[j]=true;
                }
            }
            res.push_back(sub_res);
        }
        return res;
    }
};
