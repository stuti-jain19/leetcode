class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {

        int n1 = nums1.size();
        int n2 = nums2.size();

        vector<int> insertedArray;
        vector<int> vis(n2, 0);

        for (int i = 0; i < n1; i++) {

            bool alreadyPresent = false;

            for (int x : insertedArray) {
                if (x == nums1[i]) {
                    alreadyPresent = true;
                    break;
                }
            }

            if (alreadyPresent) continue;

            for (int j = 0; j < n2; j++) {

                if (nums1[i] == nums2[j] && vis[j] == 0) {
                    insertedArray.push_back(nums1[i]);
                    vis[j] = 1;
                    break;
                }
            }
        }

        return insertedArray;
    }
};
