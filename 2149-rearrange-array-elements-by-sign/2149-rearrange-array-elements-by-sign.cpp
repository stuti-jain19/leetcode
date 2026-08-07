class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,0);
        int PosIndex = 0;
        int NegIndex = 1;
        for(int i=0; i<n; i++){
            if(nums[i] < 0){
                ans[NegIndex] = nums[i];
                NegIndex += 2;
            }
            else if(nums[i] > 0){
                ans[PosIndex] = nums[i];
                PosIndex += 2;
            }
        }
        return ans;
    }
};