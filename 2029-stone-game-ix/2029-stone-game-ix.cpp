class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
         int cnt[3] = {0, 0, 0};

        for (int x : stones)
            cnt[x % 3]++;

        auto check = [&](int a, int b) {
            if (cnt[a] == 0)
                return false;

            int x = cnt[a] - 1;
            int y = cnt[b];
            int moves = 1 + 2 * min(x, y) + cnt[0];

            if (x > y) {
                x--;
                moves++;
            }

            return moves % 2 == 1 && x != y;
        };

        return check(1, 2) || check(2, 1);
    }
};