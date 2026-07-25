class Solution {
    map<tuple<int,int,int>,bool>dp;
   bool solveRec(string& s1, int i1, string& s2, int i2, string &s3, int i3)
   {
        if(i1<0&&i2<0){
            if(i3<0)
                return true;
            else
                return false;
        }
        if(i3<0){
            return false;
        }
        if(dp.find({i1,i2,i3})!=dp.end()){
            return dp[{i1,i2,i3}];
        }
       bool ans = false;
        if (i1 >= 0 && s1[i1] == s3[i3])
            ans |= solveRec(s1, i1 - 1, s2, i2, s3, i3 - 1);

        if (i2 >= 0 && s2[i2] == s3[i3])
            ans |= solveRec(s1, i1, s2, i2 - 1, s3, i3 - 1);

        return dp[{i1, i2, i3}] = ans;
   }
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n1=s1.length();
        int n2=s2.length();
        int n3=s3.length();
        return solveRec(s1,n1-1,s2,n2-1,s3,n3-1);
    }
};
