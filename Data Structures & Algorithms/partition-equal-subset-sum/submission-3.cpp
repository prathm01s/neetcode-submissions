class Solution {
public:
    bool canPartition(vector<int>& nums) {
        long long sum = 0;
        for (int n : nums) sum += n;
        if (sum % 2 != 0) return false;
        int target = sum / 2;
        vector<int> dp(target+1, 0);
        dp[0] = 1;
        int n = nums.size();
        for (int num : nums) {
            for (int i = target;i >= num;i--) {
                dp[i] = dp[i] || dp[i - num];
            }
        }
        return (dp[target]);
    }
};
