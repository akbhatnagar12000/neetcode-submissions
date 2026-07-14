class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int d = log2(right);
        long long num = pow(2,d);
        if(num>left && right>num){
            return 0;
        }
        else{
            int ans = left;
            for(int i=left+1;i<=right;i++){
                ans=ans&i;
            }
            return ans;
        }
    }
};