class Solution {
public:
    struct State {
        long long score = 0;
        vector<int> indices;
    };

    bool better(const State& a, const State& b) {
        if (a.score != b.score)
            return a.score > b.score;

        return lexicographical_compare(
            a.indices.begin(), a.indices.end(),
            b.indices.begin(), b.indices.end()
        );
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();

        vector<array<long long, 3>> a(n);

        for (int i = 0; i < n; i++) {
            a[i] = {intervals[i][1], intervals[i][0], i};
        }

        sort(a.begin(), a.end());

        vector<long long> ends(n);
        for (int i = 0; i < n; i++)
            ends[i] = a[i][0];

        vector<array<State, 5>> dp(n + 1);

        for (int i = 1; i <= n; i++) {
            int l = a[i - 1][1];
            long long weight = intervals[a[i - 1][2]][2];
            int idx = a[i - 1][2];

            int p = lower_bound(ends.begin(), ends.begin() + (i - 1), l) - ends.begin();

            for (int k = 0; k <= 4; k++) {
                dp[i][k] = dp[i - 1][k];

                if (k > 0) {
                    State take = dp[p][k - 1];
                    take.score += weight;
                    take.indices.push_back(idx);

                    sort(take.indices.begin(), take.indices.end());

                    if (better(take, dp[i][k]))
                        dp[i][k] = take;
                }
            }
        }

        return dp[n][4].indices;
    }
};