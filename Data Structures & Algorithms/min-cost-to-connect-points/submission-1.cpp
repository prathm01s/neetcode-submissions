struct point {
    int x;
    int y;
};
struct state {
    int p_idx;
   // point p2;
    int dist;
};
int manhattan(point p1, point p2) {
    return abs(p2.x - p1.x) + abs(p2.y - p1.y);
}
int manhattan(vector<int> p1, vector<int> p2) {
    return abs(p2[0] - p1[0]) + abs(p2[1] - p1[1]);
}
struct cmp {
    bool operator() (const state& p1, const state& p2) {
        return p1.dist > p2.dist;
    }
};
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int cost = 0;
        priority_queue<state, vector<state>, cmp> pq; // {p1, p2, dist b/w them}
        /*
        for (int i = 0;i < points.size();i++) {
            for (int j = 0;j < points.size();j++) {
                if (j == i) continue;
                struct p1 = {points[i][0], points[i][1]};
                struct p2 = {points[j][0], points[j][1]};
                pq.push({p1, p2, manhattan(p1, p2)});
            }
        }*/
        //
        vector<int> vis(points.size(), 0);
        pq.push({0, 0});
        while (!pq.empty()) {
            auto p = pq.top();
            pq.pop();
            if (vis[p.p_idx] == 1) continue;
            cost += p.dist;
            vis[p.p_idx] = 1;
            for (int i = 0;i < points.size();i++) {
                if (i == p.p_idx) continue;
                if (vis[i] == 0) {
                    pq.push({i, manhattan(points[i], points[p.p_idx])});
                }
            }
        }
        return cost;
    }
};
