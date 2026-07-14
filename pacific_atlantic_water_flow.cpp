class Solution {
public:
    int m, n;
    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& visited,
             int row, int col) {

        visited[row][col] = true;
        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};
        for (int i = 0; i < 4; i++) {
            int nr = row + dr[i];
            int nc = col + dc[i];

            if (nr >= 0 && nr < m && nc >= 0 && nc < n && !visited[nr][nc] && heights[nr][nc] >= heights[row][col]) {
                dfs(heights, visited, nr, nc);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size();
        n = heights[0].size();
        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));
        for (int j = 0; j < n; j++) {
            dfs(heights, pacific, 0, j);
        }

        for (int i = 0; i < m; i++) {
            dfs(heights, pacific, i, 0);
        }

        for (int j = 0; j < n; j++) {
            dfs(heights, atlantic, m - 1, j);
        }

        for (int i = 0; i < m; i++) {
            dfs(heights, atlantic, i, n - 1);
        }

        vector<vector<int>> ans;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pacific[i][j] && atlantic[i][j]) {
                    ans.push_back({i, j});
                }
            }
        }

        return ans;
    }
};
