struct state {
    int node;
    int dist;
    int stops;
};
struct cmp {
    bool operator() (const state& a, const state& b) {
        return a.dist > b.dist;
    }
};
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adjlist(n);
        for (auto v : flights) {
            adjlist[v[0]].push_back({v[1], v[2]});
        }
        priority_queue<state, vector<state>, cmp> pq;
        // pq state: {node, dist, stops left}
        pq.push({src, 0, -1});
        int cheapest_price = INT_MAX;
        vector<int> vis(n, 0);
        while (!pq.empty()) {
            auto popped = pq.top();
            pq.pop();
            vis[popped.node] = 1;
            if (popped.node == dst) {
                cheapest_price = min(cheapest_price, popped.dist);
            } else {
                if (popped.stops < k) {
                    for (auto v : adjlist[popped.node]) {
                        if (vis[v.first] == 0) pq.push({v.first, popped.dist + v.second, popped.stops+1});
                    }
                }
            }
        }
        return cheapest_price != INT_MAX ? cheapest_price : -1;
    }
};
