class Solution {
public:
    bool isMatch(char a, char b){
        return ((a=='(' && b==')') || (a=='[' && b==']') || (a=='{' && b=='}'));
    }
    bool isValid(string s) {
        stack<char>st;
        for(auto x:s){
            if(st.empty() || x=='(' || x=='[' || x=='{'){
                st.push(x);
            }
            else{
                if(!st.empty()){
                    if(isMatch(st.top(),x)) st.pop();
                    else return false;
                }
                else{
                    return false;
                }
            }
        }
        return st.empty();
    }
};
