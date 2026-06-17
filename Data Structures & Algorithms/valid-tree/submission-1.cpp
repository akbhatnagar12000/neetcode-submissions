class Solution {
public:
    bool isCycle(vector<vector<int>>&graph,int u,vector<bool>&vis,int p){
        vis[u]=true;
        for(auto v:graph[u]){
            if(!vis[v]){
                if(isCycle(graph,v,vis,u)){
                    return true;
                }
            }
            else if(v!=p){
                return true;
            }
        }
        return false;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>>graph(n);
        for(auto e:edges){
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        vector<bool>vis(n,false);
        int iteration = 0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                if(isCycle(graph,i,vis,-1)){
                    return false;
                }
                ++iteration;
            }
        }
        if(iteration>1) return false;
        return true;
    }
};
