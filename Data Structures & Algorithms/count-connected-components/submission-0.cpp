class Solution {
public:
    void dfs(vector<vector<int>>&graph,int u,vector<bool>&vis){
        vis[u]=true;
        for(auto v:graph[u]){
            if(!vis[v]){
                dfs(graph,v,vis);
            }
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>>graph(n);
        for(auto e:edges){
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        int comp = 0;
        vector<bool>vis(n,false);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                comp++;
                dfs(graph,i,vis);
            }
        }
        return comp;
    }
};
