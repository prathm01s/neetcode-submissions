/*class dsu {
public:
    vector<int> parent;
    vector<int> rank;
    dsu(int n) {
        this->parent = vector<int>(n);
        this->parent = vector<int>(n);
    }
    int find(int x) {
        if (x == parent[x]) {
            return x;
        }
        return x = find(parent[x]);
    }
    void merge(int i, int j) {
        int ri = find(i);
        int rj = find(j);
        if (ri != rj) {
            int ranki = rank[i];
            int rankj = rank[j];
            if (ranki > rankj) {
                parent[j] = i;
            } else if (rankj > ranki) {
                parent[i] = j;
            } else {
                parent[j] = i;
                rank[i]++;
            }
        }
    }
};*/
class Solution {
public:
    int getDiff(string& a, string& b) {
        int count = 0;
        for (int i = 0;i < a.length();i++) {
            if (a[i] != b[i]) count++;
        }
        return count;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        wordList.push_back(beginWord);
        int target;
        //wordList.push_back(endWord);
        int n = wordList.size();
        for (int i = 0;i < n-1;i++) {
            if (wordList[i] == endWord) {
                target = i;
            }
        }
        //dsu d = dsu(n);
        vector<vector<int>> adjlist(n);
        /*vector<vector<int>> charHash(n, vector<int>(26, 0));
        for (int i = 0;i < n;i++) {
            for (auto c : wordList[i]) {
                charHash[i][c - 'a'] = 1;
            }
        }*/
        for (int i = 0;i < n;i++) {
            for (int j = 0;j < n;j++) {
                if (j == i) continue;
                if (getDiff(wordList[i], wordList[j]) == 1) {
                    adjlist[i].push_back(j);
                    adjlist[j].push_back(i);
                }
            }
        }
        queue<pair<int,int>> q;
        q.push({n-1,1});
        vector<int> vis(n, 0);
        vis[n-1] = 1;
        while (!q.empty()) {
            auto x = q.front();
            q.pop();
            if (x.first == target) {
                return x.second;
            }
            for (auto v : adjlist[x.first]) {
                if (vis[v] == 0) {
                    vis[v] = 1;
                    q.push({v, x.second+1});
                }
            }
        }
        return 0;
    }
};
