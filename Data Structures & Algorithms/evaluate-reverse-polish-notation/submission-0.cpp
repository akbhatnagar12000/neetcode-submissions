class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        for(auto t:tokens){
            if(t!="+" && t!="-" && t!="*" && t!="/"){
                st.push(stoi(t));
            }
            else{
                auto y = st.top();
                st.pop();
                auto x = st.top();
                st.pop();
                if(t=="+"){
                    int res = x+y;
                    st.push(res);
                }
                else if(t=="-"){
                    int res = x-y;
                    st.push(res);
                }
                else if(t=="*"){
                    int res = x*y;
                    st.push(res);
                }
                else{
                    int res = x/y;
                    st.push(res);
                }
            }
        }
        return st.top();
    }
};
