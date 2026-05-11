class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int>leftWall(n,0);
        vector<int>rightWall(n,0);
        leftWall[0]=height[0];
        for(int i=1;i<n;i++){
            leftWall[i]=max(height[i],leftWall[i-1]);
        }
        rightWall[n-1]=height[n-1];
        for(int i=n-2;i>=0;i--){
            rightWall[i]=max(height[i],rightWall[i+1]);
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            ans+=min(rightWall[i],leftWall[i])-height[i];
        }
        return ans;
    }
};
