class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int num1 = -1, num2 = -1, cnt1 = 0, cnt2 = 0;

        for(auto x:nums){
            if(x==num1){
                cnt1++;
            }
            else if(x==num2){
                cnt2++;
            }
            else if(cnt1==0){
                cnt1=1;
                num1=x;
            }
            else if(cnt2==0){
                cnt2=1;
                num2=x;
            }
            else{
                cnt1--;
                cnt2--;
            }
        }

        cnt1=cnt2=0;
        for(auto x:nums){
            if(x==num1) cnt1++;
            else if(x==num2) cnt2++;
        }
        vector<int>res;
        if(cnt1>n/3) res.push_back(num1);
        if(cnt2>n/3) res.push_back(num2);
        return res;
    }
};