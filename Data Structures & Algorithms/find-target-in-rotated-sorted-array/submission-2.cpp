class Solution {
public:
    int search(vector<int>& arr, int target) {
        int l = 0, r=arr.size()-1;
        while(l<=r){
            int m = l+(r-l)/2;
            if(arr[m]==target){
                return m;
            }
            else if(arr[m]>=arr[l]){
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
        return -1;
    }
};
