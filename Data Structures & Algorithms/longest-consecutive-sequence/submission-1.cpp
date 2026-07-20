class Solution {
public:
    void add_to_ump(unordered_map<int, int>& ump, int& lcs, int& t) {
                if (ump.find(t) != ump.end()) {
                    if (ump.find(t+1) != ump.end()) {
                        ump[t] = max(ump[t], 1+ump[t+1]);
                    } else {
                        ump[t] = max(ump[t], 1);
                    }
                } else {
                    if (ump.find(t+1) != ump.end()) {
                        ump.insert({t, 1+ump[t+1]});
                    } else {
                        ump.insert({t, 1});
                    }
                }
                lcs = max(lcs, ump[t]);
    }
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        make_heap(nums.begin(), nums.end());
        int maxx = INT_MIN;
        int lcs = INT_MIN;
        for (auto i : nums) maxx = i > maxx ? i : maxx;
        unordered_map<int, int> ump(n);
        while (!nums.empty()) {
            int t = nums.front();
            if (t != maxx) {
                add_to_ump(ump, lcs, t);
            } else {
                ump[t] = 1;
                lcs = max(lcs, ump[t]);
            }
            pop_heap(nums.begin(), nums.end());
            nums.pop_back();
        }
        return max(0, lcs);
    }
};
