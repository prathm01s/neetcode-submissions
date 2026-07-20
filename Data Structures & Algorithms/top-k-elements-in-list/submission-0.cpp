class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> ump;
        for (auto i : nums) {
            if (ump.find(i) != ump.end()) {
                ump[i] += 1;
            } else {
                ump.insert({i, 1});
            }
        }
        vector<pair<int, int>> v(ump.begin(), ump.end());
        sort(v.begin(), v.end(), [](const auto& a, const auto &b) {
            return a.second > b.second;
        });
        vector<int> ans;
        int idx = 0;
        while (idx < v.size() && idx < k) {
            ans.push_back(v[idx].first);
            idx++;
        }
        return ans;
    }
};
