bool compare(const vector<int>& a, const vector<int>& b) {
    int x1 = a[0];
    int y1 = a[1];
    int x2 = b[0];
    int y2 = b[1];
    return ((x1)*(x1) + (y1)*(y1)) > ((x2)*(x2) + (y2)*(y2));
}

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        make_heap(points.begin(), points.end(), compare);
        vector<vector<int>> ans;
        while (k--) {
            ans.push_back(points.front());
            pop_heap(points.begin(), points.end(), compare);
            points.pop_back();
        }
        return ans;
    }
};
