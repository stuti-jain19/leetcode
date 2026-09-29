class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        if ((m + n - 1) % 2 == 1) return false;
        if (grid[0][0] == ')' || grid[m-1][n-1] == '(') return false;

        const int K = 128;
        vector<vector<bitset<K>>> dp(m, vector<bitset<K>>(n));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                bitset<K> cur;
                if (i == 0 && j == 0) {
                    cur.set(0);
                } else {
                    if (i > 0) cur |= dp[i-1][j];
                    if (j > 0) cur |= dp[i][j-1];
                }
                if (grid[i][j] == '(') {
                    cur <<= 1;
                } else {
                    cur >>= 1;
                }
                dp[i][j] = cur;
            }
        }
        return dp[m-1][n-1][0];
    }
};