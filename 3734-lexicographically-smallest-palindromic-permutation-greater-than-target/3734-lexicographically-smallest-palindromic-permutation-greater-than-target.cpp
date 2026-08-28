class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.size();
        vector<int> cnt(26, 0);

        for (char c : s)
            cnt[c - 'a']++;

        int odd = 0, mid = -1;
        for (int i = 0; i < 26; i++) {
            if (cnt[i] % 2) {
                odd++;
                mid = i;
            }
        }

        if (odd > 1)
            return "";

        vector<int> halfCnt(26);
        for (int i = 0; i < 26; i++)
            halfCnt[i] = cnt[i] / 2;

        int m = n / 2;

        auto build = [&](const string& half) {
            string res = half;
            if (n % 2)
                res += char('a' + mid);
            string rev = half;
            reverse(rev.begin(), rev.end());
            res += rev;
            return res;
        };

        
        vector<int> rem = halfCnt;
        bool possible = true;

        for (int i = 0; i < m; i++) {
            int x = target[i] - 'a';
            if (--rem[x] < 0) {
                possible = false;
                break;
            }
        }

        string ans = "";

    
        if (possible) {
            string half = target.substr(0, m);
            string p = build(half);

            if (p > target)
                ans = p;
        }

        
        for (int pos = m - 1; pos >= 0; pos--) {
            vector<int> cur = halfCnt;
            bool ok = true;

            for (int i = 0; i < pos; i++) {
                int x = target[i] - 'a';
                if (--cur[x] < 0) {
                    ok = false;
                    break;
                }
            }

            if (!ok)
                continue;

            int x = target[pos] - 'a';

            for (int c = x + 1; c < 26; c++) {
                if (cur[c] == 0)
                    continue;

                string half = target.substr(0, pos);
                half += char('a' + c);

                cur[c]--;

                for (int j = 0; j < 26; j++)
                    half += string(cur[j], char('a' + j));

                string p = build(half);

                if (ans.empty() || p < ans)
                    ans = p;

                return ans;
            }
        }

        return ans;
    }
};