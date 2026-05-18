class Solution {
public:
    int mySqrt(int x) {
        long long l=1,r=x;
        while(l<=r){
            long long m = l+(r-l)/2;
            if(m*m==(long long)x){
                return m;
            }
            else if(m*m>(long long)x){
                r=m-1;
            }
            else{
                l=m+1;
            }
        }
        return r;
    }
};