class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = -1;

        for (int x = 0; x <= 50; x++) {
            int count = 0;

            // Check every subarray of size k
            for (int i = 0; i <= n - k; i++) {
                bool found = false;

                // Check if x exists in this subarray
                for (int j = i; j < i + k; j++) {
                    if (nums[j] == x) {
                        found = true;
                        break;
                    }
                }

                if (found)
                    count++;
            }

            // x appears in exactly one subarray
            if (count == 1)
                ans = x;
        }

        return ans;
    }
};