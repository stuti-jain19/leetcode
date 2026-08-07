class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,0);
        int EvenIndex = 0;
        int OddIndex = 1;
        for(int i=0; i<n; i++){
            if(nums[i] %2 == 0){
                ans[EvenIndex] = nums[i];
                EvenIndex += 2;
            }
            else {
                ans[OddIndex] = nums[i];
                OddIndex += 2;
            }
        }
        return ans;

        
    }
};