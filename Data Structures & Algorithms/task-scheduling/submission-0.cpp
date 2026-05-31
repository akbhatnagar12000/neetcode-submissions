class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>freq(26,0);
        for(auto x:tasks){
            freq[x-'A']++;
        }

        int maxFreq = *max_element(freq.begin(),freq.end());

        int countMax = 0;
        for(auto x:freq){
            if(x==maxFreq){
                countMax++;
            }
        }
        int sz = tasks.size();
        return max(sz,(maxFreq-1)*(n+1)+countMax);
    }
};
