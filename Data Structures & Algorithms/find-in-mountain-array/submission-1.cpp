/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int l = 1;
        int r = mountainArr.length()-2;
        int peak = -1;
        while(l<=r){
            int m = l+(r-l)/2;
            int left = mountainArr.get(m-1);
            int mid = mountainArr.get(m);
            int right = mountainArr.get(m+1);
            if(mid>left && mid>right){
                peak=m;
                break;
            }
            else if(mid>left && mid<right){
                l=m+1;
            }
            else{
                r=m-1;
            }
        }

        // search left of peak
        l = 0, r = peak;
        while(l<=r){
            int m = l+(r-l)/2;
            int mid = mountainArr.get(m);
            if(mid==target){
                return m;
            }
            else if(mid>target){
                r=m-1;
            }
            else{
                l=m+1;
            }
        }

        // search right of peak
        l=peak, r = mountainArr.length()-1;
        while(l<=r){
            int m = l+(r-l)/2;
            int mid = mountainArr.get(m);
            if(mid==target){
                return m;
            }
            else if(mid>target){
                l=m+1;
            }
            else{
                r=m-1;
            }
        }
        return -1;
    }
};