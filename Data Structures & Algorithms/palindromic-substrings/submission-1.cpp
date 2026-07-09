class Solution {
public:
    int countSubstrings(string s) {
        int len = 1;
        int n = s.length();
        if(n==1){
            return 1;
        }
        int ans=n;
        set<pair<int,int>>st;
        string res="";
        res.push_back(s[0]);
        for(int i=0;i<n;i++){

            //case1: ith letter at center
            int left = i-1;
            int right = i+1;
            while(left>=0 && right<n && s[left]==s[right]){
                st.insert({left,right});
                left--;
                right++;
            }
        
            //case2: i=left
            left=i;
            right=i+1;
            while(left>=0 && right<n && s[left]==s[right]){
                st.insert({left,right});
                left--;
                right++;
            }
            //case3: i=right
            left=i-1;
            right=i;
            while(left>=0 && right<n && s[left]==s[right]){
                st.insert({left,right});
                left--;
                right++;
            }
        }
        return ans+st.size();
    }
};
