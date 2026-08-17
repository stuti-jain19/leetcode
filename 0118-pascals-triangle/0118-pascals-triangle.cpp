class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;

        for (int i = 0; i < numRows; i++) {
            vector<int> row;
            long long val = 1;

            row.push_back(1);

            for (int col = 1; col <= i; col++) {
                val = val * (i - col + 1) / col;
                row.push_back(val);
            }

            ans.push_back(row);
        }

        return ans;
    }
};