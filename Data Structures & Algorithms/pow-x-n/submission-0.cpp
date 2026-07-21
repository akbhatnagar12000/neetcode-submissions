class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1.0;
        int d = abs(n);
        for(int i=1;i<=d;i++){
            ans=ans*x;
        }
        if(n<0){
            ans=1.0/ans;
        }
        return ans;
    }
};
