class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (n != edges.size() + 1) return false;
        // lets detect a cycle
        // approach 1 - bfs w/ parent array, 2 - dfs coloring (dfs style)
        vector<vector<int>> adjlist(n);
        for (auto e : edges) {
            adjlist[e[0]].push_back(e[1]);
            adjlist[e[1]].push_back(e[0]);
        }
        vector<int> par(n);
        vector<int> vis(n, 0);
        queue<int> q;
        q.push(0);
        int root = 0;
        int count = 0;
        par[0] = -1;
        vis[0] = 1;
        count++;
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            for (auto i : adjlist[x]) {
                if (vis[i] == 0) {
                    par[i] = x;
                    vis[i] = 1;
                    count++;
                    q.push(i);
                } else {
                    if (par[x] != i) return false;
                }
            }
        }
        if (count != n) return false;
        return true;
    }
};
