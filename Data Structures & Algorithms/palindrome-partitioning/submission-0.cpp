class Solution {
    vector<string>temp;
    vector<vector<string>>res;
public:
    bool isPalindrome(string &s){
        int i=0,j=s.length()-1;
        while(i<j){
            if(s[i]!=s[j]){
                return false;
            }
            i++,j--;
        }
        return true;
    }
    void solveRec(string&s, int idx){
        if(idx==s.length()){
            res.push_back(temp);
            return;
        }
        string left = "";
        for(int i=idx;i<s.length();i++){
            left.push_back(s[i]);
            if(isPalindrome(left)){
                temp.push_back(left);
                solveRec(s,i+1);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        solveRec(s,0);
        return res;
    }
};
