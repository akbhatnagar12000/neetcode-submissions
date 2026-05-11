class Solution {
public:
    int maxArea(vector<int>& heights) {
        int ans = 0;
        int l=0,r=heights.size()-1;
        while(l<=r)
        {
            int width = r-l;
            int height = min(heights[l],heights[r]);
            // cout<<height<<" "<<width<<"\n";
            ans = max(ans,height*width);
            if(heights[l]<=heights[r]){
                l++;
            }
            else{
                r--;
            }
        }
        return ans;
    }
};
