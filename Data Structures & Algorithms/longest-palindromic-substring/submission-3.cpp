class Solution {
public:
    string longestPalindrome(string s) {
        int len = 1;
        int n = s.length();
        if(n==1){
            return s;
        }
        string res="";
        res.push_back(s[0]);
        for(int i=0;i<n;i++){

            //case1: ith letter at center
            int left = i-1;
            int right = i+1;
            int count = 0;
            bool expand=false;
            while(left>=0 && right<n && s[left]==s[right]){
                left--;
                right++;
                count++;
                expand=true;
            }
            if(expand){
                if(len<2*count+1){
                    res=s.substr(left+1,2*count+1);
                }
                len=max(len,2*count+1);
            }
        
            //case2: i=left
            left=i;
            right=i+1;
            count=0;
            expand=false;
            while(left>=0 && right<n && s[left]==s[right]){
                left--;
                right++;
                count++;
                expand=true;
            }
            if(expand){
                if(len<2*count){
                    res=s.substr(left+1,2*count);
                }
                len=max(len,2*count);
            }
            //case3: i=right
            left=i-1;
            right=i;
            count=0;
            expand=false;
            while(left>=0 && right<n && s[left]==s[right]){
                left--;
                right++;
                count++;
                expand=true;
            }
            if(expand){
                if(len<2*count){
                    res=s.substr(left+1,2*count);
                }
                len=max(len,2*count);
            }
        }
        // cout<<len<<"\n";
        return res;
    }
};
