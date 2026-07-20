class Solution {
public:
    long long canPartition(vector<int>& nums, int target) {
        vector<long long int> dp(target+1, 0);
        dp[0] = 1;
        int n = nums.size();
        for (int num : nums) {
            for (int i = target;i >= num;i--) {
                dp[i] = dp[i] + dp[i - num];
            }
        }
        return (dp[target]);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        long long int sum = 0;
        for (int n : nums) sum += n;
        // S - N = target
        // S + N = sum
        // 2 * S = target + sum
        long long int targ = (sum + target);
        if (targ % 2 != 0) return false;
        targ /= 2;
        return canPartition(nums, targ);
    }
};
