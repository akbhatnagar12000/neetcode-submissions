class Solution {
public:
    int dfs(vector<vector<int>>& grid, int x, int y) {
        int n = grid.size();
        int m = grid[0].size();

        if (x < 0 || x >= n || y < 0 || y >= m)
            return 1;          // boundary contributes 1

        if (grid[x][y] == 0)
            return 1;          // water contributes 1

        if (grid[x][y] == -1)
            return 0;          // already visited

        grid[x][y] = -1;

        return dfs(grid, x + 1, y) +
               dfs(grid, x - 1, y) +
               dfs(grid, x, y + 1) +
               dfs(grid, x, y - 1);
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1)
                    return dfs(grid, i, j);
            }
        }
        return 0;
    }
};