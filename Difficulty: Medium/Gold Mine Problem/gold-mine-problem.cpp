class Solution {
  public:
    int maxGold(vector<vector<int>>& mat) {
        // code here
                int m = mat.size();         // number of rows
        int n = mat[0].size();      // number of columns

        vector<vector<int>> dp(m, vector<int>(n, 0));

        // Fill the last column with mat values
        for (int i = 0; i < m; i++) {
            dp[i][n - 1] = mat[i][n - 1];
        }

        // Fill the rest of the dp table from right to left
        for (int j = n - 2; j >= 0; j--) {
            for (int i = 0; i < m; i++) {
                int right = dp[i][j + 1];
                int upRight = (i > 0) ? dp[i - 1][j + 1] : 0;
                int downRight = (i < m - 1) ? dp[i + 1][j + 1] : 0;

                dp[i][j] = mat[i][j] + max({right, upRight, downRight});
            }
        }

        // The answer is the maximum value in the first column
        int maxGold = 0;
        for (int i = 0; i < m; i++) {
            maxGold = max(maxGold, dp[i][0]);
        }

        return maxGold;

    }
};