class Solution {
public:
vector<int> findMissingElements(vector<int>& nums) {
    int mn = *min_element(nums.begin(), nums.end());
    int mx = *max_element(nums.begin(), nums.end());
    vector<int> hash(mx + 1, 0);
    for(int i = 0; i < nums.size(); i++) {
            hash[nums[i]]++;
        }
    vector<int> missing;
    for(int i = mn; i <= mx; i++) {
        if(hash[i] == 0)
            missing.push_back(i);
        }

        return missing;
    }
};