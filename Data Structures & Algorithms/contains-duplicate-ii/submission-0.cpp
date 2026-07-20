class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> ump;
        int n = nums.size();
        int l = 0;
        int r = 1;
        ump.insert({nums[0], 1});
        while (r < n) {
            while (r < n && r-l <= k) {
                if (ump.find(nums[r]) != ump.end()) {
                    return true;
                } else {
                    ump[nums[r]] = 1;
                }
                r++;
            }
            ump.erase(nums[l]);
            l++;
        }
        return false;
    }
};