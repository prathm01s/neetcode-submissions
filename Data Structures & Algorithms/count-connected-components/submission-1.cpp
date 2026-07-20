class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        int id = -1;
        vector<vector<int>> adjlist(n);
        for (auto e : edges) {
            adjlist[e[0]].push_back(e[1]);
            adjlist[e[1]].push_back(e[0]);
        }
        vector<int> vis(n, 0);
        queue<int> q;
        for (int i = 0;i < n;i++) {
            if (vis[i] == 0) {
                q.push(i);
                ++id;
            }
            while (!q.empty()) {
                int x = q.front();
                q.pop();
                for (auto v : adjlist[x]) {
                    if (vis[v] == 0) {
                        vis[v] = 1;
                        q.push(v);
                    }
                }
            }
        }
        return id+1;
    }
};
