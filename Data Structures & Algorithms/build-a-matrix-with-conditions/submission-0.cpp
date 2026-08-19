class Solution {
public:
    vector<int> topoSort(int k, vector<vector<int>>& conditions) {
        vector<vector<int>> graph(k + 1);
        vector<int> indegree(k + 1, 0);

        for (auto &c : conditions) {
            int u = c[0];
            int v = c[1];

            graph[u].push_back(v);
            indegree[v]++;
        }

        queue<int> q;

        for (int i = 1; i <= k; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> order;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            order.push_back(u);

            for (int v : graph[u]) {
                indegree[v]--;

                if (indegree[v] == 0) {
                    q.push(v);
                }
            }
        }

        // Cycle exists
        if (order.size() != k) {
            return {};
        }

        return order;
    }

    vector<vector<int>> buildMatrix(
        int k,
        vector<vector<int>>& rowConditions,
        vector<vector<int>>& colConditions
    ) {
        // Topological order for rows
        vector<int> rowOrder = topoSort(k, rowConditions);

        // Topological order for columns
        vector<int> colOrder = topoSort(k, colConditions);

        // If either graph has a cycle
        if (rowOrder.empty() || colOrder.empty()) {
            return {};
        }

        // row[x] = row where number x should be placed
        // col[x] = column where number x should be placed
        vector<int> row(k + 1);
        vector<int> col(k + 1);

        for (int i = 0; i < k; i++) {
            row[rowOrder[i]] = i;
            col[colOrder[i]] = i;
        }

        vector<vector<int>> ans(k, vector<int>(k, 0));

        // Place every number exactly once
        for (int x = 1; x <= k; x++) {
            ans[row[x]][col[x]] = x;
        }

        return ans;
    }
};