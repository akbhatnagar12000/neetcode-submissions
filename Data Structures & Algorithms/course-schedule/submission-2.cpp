class Solution {
public:
    bool hasCycle(vector<vector<int>>&graph, int u, vector<bool>&vis,
    vector<bool>&recStack){
        vis[u]=true;
        recStack[u]=true;
        for(auto x:graph[u]){
            if(!vis[x]){
                if(hasCycle(graph,x,vis,recStack)){
                    return true;
                }
            }
            else{
                if(recStack[x]) // back-edge
                    return true;
            }
        }
        recStack[u]=false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>graph(numCourses);
        for(auto p:prerequisites){
            graph[p[1]].push_back(p[0]); //pre-requisite -> course
        }
        vector<bool>vis(numCourses,false);
        vector<bool>recStack(numCourses,false); // need to track nodes in current recusion stack
        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                if(hasCycle(graph,i,vis,recStack)){
                    return false;
                }
            }
        }
        return true;
    }
};
