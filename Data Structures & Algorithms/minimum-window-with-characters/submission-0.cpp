class Solution {
public:
    bool contains(vector<int>a, vector<int>b)
    {
        int n = a.size();
        for(int i=0;i<a.size();i++){
            if(b[i] && a[i]<b[i]) return false;
        }
        return true;
    }
    string minWindow(string s, string t) {
        vector<int>sChar(256,0);
        vector<int>tChar(256,0);
        for(auto x:t){
            tChar[x]++;
        }
        int i=0,j=0;
        int ans = INT_MAX;
        int start = -1;
        int n = s.length();
        for(j=0;j<n;j++){
            sChar[s[j]]++;
            while(contains(sChar,tChar)){
                // cout<<i<<" "<<j<<"\n";
                // cout<<ans<<"\n";
                if(ans>j-i+1){
                    ans=j-i+1;
                    start=i;
                }
                sChar[s[i]]--;
                i++;
            }
        }
        if(contains(sChar,tChar)){
            // cout<<"YES\n";
            start=i;
        }
        // cout<<start<<" "<<i<<" "<<j<<ans<<"\n";
        if(start>=0)
            return s.substr(start,min(ans,n));
        else
            return "";
    }
};
