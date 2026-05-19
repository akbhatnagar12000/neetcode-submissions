class Solution {
public:
    bool search(vector<int>& arr, int target) {
        int l = 0, r=arr.size()-1;
        while(l<=r){
            int m = l+(r-l)/2;
            if(arr[m]==target){
                return true;
            }
            while(l<m && r>m && arr[l]==arr[m] && arr[r]==arr[m]){
                l++,r--;
            }
            if(arr[m]>=arr[l]){
                if(arr[l]<=target && arr[m]>=target){
                    r=m-1;
                }
                else{
                    l=m+1;
                }
            }
            else{
                if(arr[m]<=target && arr[r]>=target){
                    l=m+1;
                }
                else{
                    r=m-1;
                }
            }
        }
        return false;
    }
};