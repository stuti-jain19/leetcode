class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();
        int half = n / 2;

        int sum = 0;
        int leftQ = 0, rightQ = 0;

        // Left half
        for (int i = 0; i < half; i++) {
            if (num[i] == '?')
                leftQ++;
            else
                sum += num[i] - '0';
        }

        // Right half
        for (int i = half; i < n; i++) {
            if (num[i] == '?')
                rightQ++;
            else
                sum -= num[i] - '0';
        }

        // Odd number of '?' -> Alice wins
        if ((leftQ + rightQ) % 2 == 1)
            return true;

        // Bob can force equality only in this case
        return 2 * sum != 9 * (rightQ - leftQ);
    }
};