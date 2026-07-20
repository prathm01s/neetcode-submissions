class Solution {
public:
    int findFloor(vector<int>& arr, int x, int l, int r, int& mn) {
        if (l > r) return -1; 
        if (l == r) {
            mn = abs(x-arr[mn]) > abs(x-arr[l]) ? l : mn;
            if (arr[l] == x) return l;
            else return -1;
        }
        //
        int i = l + (r-l+1)/2;
        mn = abs(x-arr[mn]) > abs(x-arr[i]) ? i : mn;
        if (x < arr[i]) {
            return findFloor(arr, x, l, i-1, mn);
        } else if (x == arr[i]) {
            return i;
        } else {
            return findFloor(arr, x, i+1, r, mn);
        }
    }   
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        int mn = 0;
        int idx = findFloor(arr, x, 0, n-1, mn);
        idx = mn;
        int ptr2 = idx+1;
        int ptr1 = idx-1;
        int count = 1;
        vector<int> ans;
        ans.push_back(arr[idx]);
        while (count < k && (ptr1 >= 0 || ptr2 < n)) {
            if (ptr1 < 0 && ptr2 < n) {
                ans.push_back(arr[ptr2]);
                count++;
                ptr2++;
            } else if (ptr1 >= 0 && ptr2 >= n) {
                ans.push_back(arr[ptr1]);
                count++;
                ptr1--;
            } else {
                if (abs(arr[ptr1] - x) <= abs(arr[ptr2] - x)) {
                    ans.push_back(arr[ptr1]);
                    count++;
                    ptr1--;
                } else {
                    ans.push_back(arr[ptr2]);
                    count++;
                    ptr2++;
                }
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};