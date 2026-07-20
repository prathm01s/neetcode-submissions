class UnionFind {
private:
    vector<int> parent;
    vector<int> rank;
public:
    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0;i < n;i++) {
            parent[i] = i;
        }
    }
    int find(int i) {
        if (parent[i] == i) {
            return i;
        }
        return parent[i] = find(parent[i]);
    }
    int unite(int i, int j) {
        int ri = find(i);
        int rj = find(j);
        if (ri != rj) {
            if (rank[ri] > rank[rj]) {
                parent[ri] = rj;
            } else if (rank[ri] < rank[rj]) {
                parent[rj] = ri;
            } else {
                parent[ri] = rj;
                rank[rj]++;
            }
            return 0;
        }
        return 1;
    }
    int check(int i, int j) {
        return find(i) == find(j);
    }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        UnionFind uf(edges.size());
        vector<int> ans;
        for (auto e : edges) {
            if (uf.check(e[0]-1, e[1]-1)) {
                ans = e;
            } else {
                uf.unite(e[0]-1, e[1]-1);
            }
        }
        return ans;
    }
};
