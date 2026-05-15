class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int>st;
        int sum = 0;
        for(auto x:operations){
            if(x!="D" && x!="+" && x!="C"){
                st.push(stoi(x));
                sum+=stoi(x);
            }
            else{
                if(x=="+"){
                    auto x = st.top();
                    st.pop();
                    auto y = st.top();
                    st.pop();
                    int sum1 = x+y;
                    st.push(y);
                    st.push(x);
                    st.push(sum1);
                    sum+=sum1;
                }
                else if(x=="D"){
                    auto x = st.top();
                    st.pop();
                    st.push(x);
                    st.push(2*x);
                    sum+=2*x;
                }
                else{
                    sum-=st.top();
                    st.pop();
                }
            }
        }
        return sum;
    }
};