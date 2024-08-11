/*approach
  dfs
  we know that the base will be 2 meaning definitely
  we need to change 2 islands but whether it will become
  1 or not is to be chosen. so we change the grid cell to 0
  if it was a 1 and run a dfs to find no of islands left 
  at any grid after changing it to 0 we get no of islands 
  greater than 1 then we need to delete 1 island to make it
  disconnected. else if there is only one whole island then
  we by default or by base case delete 2 islands to make it disconnected*/
class Solution {
private:
    void dfs(vector<vector<int>>& grid, int i, int j, int n, int m,vector<vector<bool>>& visited) {
        if (i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == 0 || visited[i][j]) {
            return;
        }
        visited[i][j] = 1;
        dfs(grid, i + 1, j, n, m,visited);
        dfs(grid, i - 1, j, n, m,visited);
        dfs(grid, i, j + 1, n, m,visited);
        dfs(grid, i, j - 1, n, m,visited);
    }
    int countIslands(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>>visited(n,vector<bool>(m,0));
        int islandCount = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    ++islandCount;
                    dfs(grid, i, j, n, m,visited);
                }
            }
        }
        return islandCount;
    }

public:
    int minDays(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if ((n == 1 && m == 2) || (m == 1 && n == 2)) return 2;
        if (n == 1 || m == 1) return 1;
        if (countIslands(grid) != 1) {
            return 0;
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1) {
                    grid[i][j] = 0; 
                    if (countIslands(grid) != 1) {
                        return 1;
                    }
                    grid[i][j] = 1; 
                }
            }
        }
        return 2;
    }
};
