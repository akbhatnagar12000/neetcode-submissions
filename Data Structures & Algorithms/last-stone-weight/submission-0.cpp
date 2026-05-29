class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pq;
        for(auto x:stones){
            pq.push(x);
        }
        while(pq.size()>1){
            auto x = pq.top();
            pq.pop();
            auto y = pq.top();
            pq.pop();
            x-=y;
            if(x){
                pq.push(x);
            }
        }
        return pq.size()==0?0:pq.top();
    }
};
