class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int l = 0;
        int r = 0;
        int curr_min = 0;
        int curr_max = 0;
        int mx = 0;
        while (r < n) {
            while (r+1 < n && prices[r+1] > prices[curr_min]) {
                curr_max = prices[curr_max] > prices[r+1] ? curr_max : r+1;
                mx = max(mx, prices[curr_max] - prices[curr_min]);
                r++;
            }
            while (l <= curr_min) {
                l++;
            }
            if (l < n) {
                curr_min = l;
                curr_max = l;
                r = l;
            } else {
                break;
            }
        }
        return mx;
    }
};
