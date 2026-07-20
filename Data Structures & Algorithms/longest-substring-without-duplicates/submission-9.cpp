class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> hash;
        int mx = INT_MIN;
        int curr = 0;
        int l = 0;
        int r = 0;
        int n = s.length();
        cout << n << endl;
        while (r < n && l < n) {
            while (r < n) {
                if (hash[s[r]] == 0 ) {
                    curr++;
                    hash[s[r]] = 1;
                    r++;
                    mx = max(mx, curr);
                    if (r==n) return max(0, mx);
                } else {
                    break;
                }
            }
            mx = max(mx, curr);
            curr--;
            hash[s[l]] = 0;
            l++;
        }
        return max(mx, 0);
    }
};
