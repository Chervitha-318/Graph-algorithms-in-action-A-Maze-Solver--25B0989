class Solution {
public:
    int m, n;
    int originalColor;

    void dfs(vector<vector<int>>& image, int row, int col, int newColor) {

        if (row < 0 || row >= m || col < 0 || col >= n)
            return;

        if (image[row][col] != originalColor)
            return;

        image[row][col] = newColor;

        dfs(image, row - 1, col, newColor);
        dfs(image, row + 1, col, newColor);
        dfs(image, row, col - 1, newColor);
        dfs(image, row, col + 1, newColor);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image,
                                  int sr, int sc, int color) {

        m = image.size();
        n = image[0].size();

        originalColor = image[sr][sc];
        if (originalColor == color)
            return image;

        dfs(image, sr, sc, color);

        return image;
    }
};
