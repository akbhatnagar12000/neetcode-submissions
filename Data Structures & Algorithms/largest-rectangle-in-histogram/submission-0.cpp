class Solution {
public:
    vector<int>prevSmaller(vector<int>&heights){
        int n = heights.size();
        vector<int>prevSmall(n,-1);
        stack<int>st;
        for(int i=0;i<n;i++){
            if(st.empty()){
                st.push(i);
            }
            else{
                while(!st.empty() && heights[st.top()]>=heights[i]){
                    st.pop();
                }
                if(st.empty()){
                    prevSmall[i]=-1;
                }
                else{
                    prevSmall[i]=st.top();
                }
                st.push(i);
            }
        }
        return prevSmall;
    }
    vector<int>nextSmaller(vector<int>&heights){
        int n = heights.size();
        vector<int>nextSmall(n,n);
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            if(st.empty()){
                st.push(i);
            }
            else{
                while(!st.empty() && heights[st.top()]>=heights[i]){
                    st.pop();
                }
                if(st.empty()){
                    nextSmall[i]=n;
                }
                else{
                    nextSmall[i]=st.top();
                }
                st.push(i);
            }
        }
        return nextSmall;
    }
    int largestRectangleArea(vector<int>& heights) {
        vector<int>prevSmall = prevSmaller(heights);
        vector<int>nextSmall = nextSmaller(heights);
        int ans = 0;
        int n = heights.size();
        for(int i=0;i<n;i++){
            ans=max(ans,(nextSmall[i]-prevSmall[i]-1)*heights[i]);
        }
        return ans;
    }
};
