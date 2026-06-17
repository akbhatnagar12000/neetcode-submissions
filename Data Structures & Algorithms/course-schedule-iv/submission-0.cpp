class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<bool>> pre(numCourses, vector<bool>(numCourses,false));
        for(auto &p: prerequisites)
            pre[p[0]][p[1]] = true;

        // Floyd - Warshall
        for(int k=0;k<numCourses;k++)
            for(int i=0;i<numCourses;i++)
                for(int j=0;j<numCourses;j++)
                    pre[i][j] = pre[i][j] | (pre[i][k] && pre[k][j]);

        vector<bool>res;
        for(auto q:queries){
            res.push_back(pre[q[0]][q[1]]);
        }
        return res;
    }
};