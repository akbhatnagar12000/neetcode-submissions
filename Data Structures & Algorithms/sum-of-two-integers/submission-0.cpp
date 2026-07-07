class Solution {
public:
    int getSum(int a, int b) {
        while(b!=0){
            unsigned int carry = ((unsigned int)(a) & (unsigned int)(b))<<1;
            a=a^b;
            b=(int)carry;
        }
        return a;
    }
};
