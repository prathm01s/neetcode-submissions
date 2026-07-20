class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> src(numCourses, 0);
        vector<vector<int>> adjlist(numCourses);
        // below loop is O(prerequisites.size())
        for (auto v : prerequisites) {
            adjlist[v[1]].push_back(v[0]);
            src[v[0]]++;
        }
        queue<int> q;
        int count = 0;
        for (int i = 0;i < numCourses;i++) {
            if (src[i] == 0) {
                q.push(i);
                count++;
            }
        }
        vector<int> ans;
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            ans.push_back(x);
            for (auto i : adjlist[x]) {
                src[i]--;
                if (src[i] == 0) {
                    count++;
                    q.push(i);
                }
            }
        }
        if (count == numCourses) return ans;
        else return {};
    }
};
