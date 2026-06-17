class Solution {
public:
    bool isCycle(vector<vector<int>>&graph, int u, vector<bool>&vis,
    vector<bool>&recStack, vector<int>&res){
        vis[u]=true;
        recStack[u]=true;
        for(auto v:graph[u]){
            if(!vis[v]){
                if(isCycle(graph,v,vis,recStack,res)){
                    return true;
                }
            }
            else if(recStack[v]){
                return true;
            }
        }
        recStack[u]=false;
        res.push_back(u);
        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>graph(numCourses);
        for(auto p:prerequisites){
            graph[p[0]].push_back(p[1]);
        }
        vector<int>res;
        vector<bool>vis(numCourses,false);
        vector<bool>recStack(numCourses,false);
        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                if(isCycle(graph,i,vis,recStack,res)){
                    return {};
                }
            }
        }
        return res;
    }
};
