class Solution {
    struct Point{
        int x,y;
    };
    struct DSU{
        map<pair<int,int>,pair<int,int>>parent;
        map<pair<int,int>,int>rank;
        DSU(vector<vector<int>>&points){
            for(auto p:points){
                parent[{p[0],p[1]}]={p[0],p[1]};
                rank[{p[0],p[1]}]=0;
            }
        }
        pair<int,int>findPar(pair<int,int>p){
            if(parent[p]==p) return p;
            return parent[p]=findPar(parent[p]);
        }
        void unite(pair<int,int>p1,pair<int,int>p2){
            p1 = findPar(p1);
            p2 = findPar(p2);
            if(rank[p1]<=rank[p2]){
                parent[p1]=p2;
                if(rank[p1]==rank[p2]){
                    rank[p2]++;
                }
            }
            else{
                parent[p2]=p1;
            }
        }
    };
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        DSU dsu(points);
        int n = points.size();
        priority_queue<vector<pair<int,int>>,vector<vector<pair<int,int>>>,
        greater<vector<pair<int,int>>>>pq;

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int d = abs(points[i][0]-points[j][0]) + abs(points[i][1]-points[j][1]);
                pair<int,int>dist = {d,-1};
                pair<int,int>p1 = {points[i][0],points[i][1]};
                pair<int,int>p2 = {points[j][0],points[j][1]};
                pq.push({dist,p1,p2});
            }
        }
        // n-1 because we need n-1 connection to connect n points
        int ans=0;
        int edgeUsed=0;
        while(edgeUsed<n-1)
        {
            auto p = pq.top();
            pq.pop();
            if(dsu.findPar(p[1])!=dsu.findPar(p[2])){
                auto dist = p[0];
                ans+=dist.first;
                dsu.unite(p[1],p[2]);
                edgeUsed++;
            }
        }
        return ans;
    }
};
