class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
       vector<vector<pair<int,int>>>graph(n);
       for(auto x:times){
         graph[x[0]-1].push_back({x[1]-1,x[2]});
       }
       int ans = INT_MIN;
       priority_queue<pair<int,int>,vector<pair<int,int>>,
       greater<pair<int,int>>>pq;
       vector<int>dist(n,INT_MAX);
       dist[k-1]=0;
       pq.push({0,k-1});
       while(!pq.empty()){
            auto p = pq.top();
            pq.pop();
            int d = p.first;
            int x = p.second;
            if(dist[x]<d){
                continue;
            }
            for(auto v:graph[x]){
                if(d+v.second<dist[v.first]){
                    dist[v.first]=d+v.second;
                    pq.push({d+v.second,v.first});
                }
            }
       }
       for(auto x:dist){
            if(x==INT_MAX) return -1;
            ans=max(ans,x);
       }
       return ans;
    }
};
