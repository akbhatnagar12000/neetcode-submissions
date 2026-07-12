class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        reverse(digits.begin(),digits.end());
        int carry = 1;
        int n = digits.size();
        for(int i=0;i<n;i++){
            int sum = carry+digits[i];
            carry=sum/10;
            digits[i]=sum%10;
        }
        while(carry){
            digits.push_back(carry%10);
            carry=carry/10;
        }
        reverse(digits.begin(),digits.end());
        return digits;
    }
};
