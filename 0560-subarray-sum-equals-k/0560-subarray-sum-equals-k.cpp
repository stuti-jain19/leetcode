class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        map<int,int>mpp;
        mpp[0] = 1;
        int Presum = 0, cnt = 0;
        for(int i=0; i<n; i++){
            Presum += nums[i];
            int remove = Presum - k;
            cnt += mpp[remove];
            mpp[Presum] += 1;
        }
        return cnt;

    }
};