class Solution {
public:
    void Merge(vector<int>&nums,int l,int m, int r)
    {
        int n1=m-l+1;
        int n2=r-m;
        vector<int>a(n1,0);
        vector<int>b(n2,0);
        for(int i=0;i<n1;i++){
            a[i]=nums[l+i];
        }
        for(int i=0;i<n2;i++){
            b[i]=nums[m+1+i];
        }
        int k=l,i=0,j=0;
        while(i<n1&&j<n2){
            if(a[i]<=b[j]){
                nums[k++]=a[i++];
            }
            else{
                nums[k++]=b[j++];
            }
        }
        while(i<n1){
            nums[k++]=a[i++];
        }
        while(j<n2){
            nums[k++]=b[j++];
        }
    }
    void MergeSort(vector<int>&nums, int l , int r){
        if(l<r){
            int m = l+(r-l)/2;
            MergeSort(nums,l,m);
            MergeSort(nums,m+1,r);
            Merge(nums,l,m,r);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        MergeSort(nums,0,n-1);
        return nums;
    }
};