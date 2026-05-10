class Solution {
public:
    bool isIgnorable(char c){
        return !((c>='a' && c<'z') || (c>='A' && c<='Z') || (c>='0' && c<='9'));
    }
    bool isPalindrome(string s) {
        int i=0,j=s.length()-1;
        while(i<j){
            while(i<j && isIgnorable(s[i]))i++;
            while(i<j && isIgnorable(s[j]))j--;
            if(tolower(s[i])!=tolower(s[j])) return false;
            i++,j--;
        }
        return true;
    }
};
