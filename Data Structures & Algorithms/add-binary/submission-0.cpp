class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        int carry=0;
        int i=0,j=0;
        string res="";
        while(i<a.length() && j<b.length()){
            int x = a[i]-'0';
            int y = b[j]-'0';
            int sum = x+y+carry;
            carry=sum/2;
            sum=sum%2;
            res.push_back(sum+'0');
            i++,j++;
        }
        while(i<a.length()){
            int x = a[i]-'0';
            int sum = x+carry;
            carry=sum/2;
            sum=sum%2;
            res.push_back(sum+'0');
            i++;
        }
        while(j<b.length()){
            int y = b[j]-'0';
            int sum = y+carry;
            carry=sum/2;
            sum=sum%2;
            res.push_back(sum+'0');
            j++;
        }
        while(carry){
            res.push_back((carry)%2+'0');
            carry=carry/2;
        }
        reverse(res.begin(),res.end());
        return res;
    }
};