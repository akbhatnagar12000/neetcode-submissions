class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        // cout<<"[";
        // for(auto interval:intervals){
        //     cout<<"["<<interval[0]<<","<<interval[1]<<"],";
        // }
        // cout<<"]\n";
        int end = intervals[0][1];
        int count = 0;
        for(int i=1;i<intervals.size();i++){
            if(end>intervals[i][0]){
                // cout<<intervals[i][0]<<" "<<intervals[i][1]<<"\n";
                count++;
                end=min(end,intervals[i][1]); // so that we have more room!
            }
            else{
                end=intervals[i][1];
            }
        }
        return count;
    }
};
