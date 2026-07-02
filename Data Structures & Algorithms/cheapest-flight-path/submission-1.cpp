class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        priority_queue<
        tuple<int,int,int>,
        vector<tuple<int,int,int>>,
        greater<tuple<int,int,int>>
        > pq;
        pq.push({0,src,0});
        vector<vector<pair<int,int>>>graph(n);
        for(auto f:flights){
            graph[f[0]].push_back({f[1],f[2]});
        }
        while(!pq.empty()){
            auto p = pq.top();
            pq.pop();
            int cost = get<0>(p);
            int st = get<1>(p);
            int left = get<2>(p);
            if(st==dst){
                return cost;
            }
            for(auto d:graph[st]){
                int to = d.first;
                int cst = d.second;
                if(left<k+1){
                    pq.push({cost+cst,to,left+1});
                }
            }
        }
        return -1;
    }
};
