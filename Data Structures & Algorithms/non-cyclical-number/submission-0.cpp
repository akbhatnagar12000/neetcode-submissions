class Solution {
public:
    bool isHappy(int n) {
        set<int>seen;
        seen.insert(n);
        while(n!=1){
            int d = 0;
            while(n){
                int r = n%10;
                d+=r*r;
                n=n/10;
            }
            n=d;
            if(seen.find(n)!=seen.end() && n!=1){
                return false;
            }
            seen.insert(n);
        }
        return true;
    }
};
