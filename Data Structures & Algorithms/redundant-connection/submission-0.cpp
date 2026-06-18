class Solution {
    struct DSU{
        vector<int>parent;
        vector<int>rank;
        DSU(int n){
            for(int i=0;i<n;i++){
                parent.push_back(i);
                rank.push_back(0);
            }
        }
        int findPar(int x){
            if(parent[x]==x) return x;
            return parent[x]=findPar(parent[x]);
        }
        void unite(int x, int y){
            x = findPar(x);
            y = findPar(y);
            if(rank[x]<=rank[y]){
                parent[x]=y;
                if(rank[x]==rank[y]){
                    rank[y]++;
                }
            }
            else{
                parent[y]=x;
            }
        }
    };
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        DSU dsu(101);
        vector<int>res;
        for(auto e:edges){
            int u = e[0];
            int v = e[1];
            if(dsu.findPar(u)==dsu.findPar(v)){
                res.push_back(u);
                res.push_back(v);
                return res;
            }
            dsu.unite(u,v);
        }
        return res;
    }
};
