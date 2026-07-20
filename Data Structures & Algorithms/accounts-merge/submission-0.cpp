class dsu {
public:
    vector<int> parent;
    vector<int> rank;
    dsu(int size) {
        this->parent = vector<int>(size);
        for (int i = 0;i < size;i++) {
            parent[i] = i;
        }
        this->rank = vector<int>(size);
    }
    int find(int x) {
        if (x == parent[x]) {
            return x;
        }
        return parent[x] = find(parent[x]);
    }
    bool check(int i, int j) {
        return find(i) == find(j);
    }
    int merge(int i, int j) {
        int a = find(i);
        int b = find(j);
        if (a == b) {
            int ra = rank[a];
            int rb = rank[b];
            if (ra > rb) {
                return a;
            } else {
                return b;
            }
        } else {
            int ra = rank[a];
            int rb = rank[b];
            if (ra > rb) {
                parent[b] = a;
                rank[a] = max(rank[a], rank[b]+1);
                return a;
            } else if (ra < rb) {
                parent[a] = b;
                rank[b] = max(rank[b], rank[a]+1);
                return b;
            } else {
                parent[a] = b;
                rank[b]++;
                return b;
            }
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        dsu d = dsu(accounts.size());
        unordered_map<string, int> umap;
        for (int i = 0;i < accounts.size();i++) {
            for (int s = 1;s < accounts[i].size();s++) {
                if (umap.find(accounts[i][s]) != umap.end()) {
                    d.merge(umap[accounts[i][s]], i);
                } else {
                    umap[accounts[i][s]] = i;
                }
            }
        }
        vector<vector<string>> ans;
        unordered_map<int, vector<string>> revumap;
        for (auto u : umap) {
            revumap[d.find(u.second)].push_back(u.first);
        }
        for (auto it : revumap) {
            int root = it.first;
            vector<string> emails = it.second;
            sort(emails.begin(), emails.end());
            vector<string> mergedAcc;
            mergedAcc.push_back(accounts[root][0]);
            for (auto i : emails) {
                mergedAcc.push_back(i);
            }
            ans.push_back(mergedAcc);
        }
        return ans;
    }
};