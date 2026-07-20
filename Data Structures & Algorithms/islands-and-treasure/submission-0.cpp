struct cell {
    int x, y, dist;
};
class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<cell> q;
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0;i < m;i++) {
            for (int j = 0;j < n;j++) {
                if (grid[i][j] == 0) {
                    q.push({i, j, 0});
                }
            }
        }
        while (!q.empty()) {
            auto popped = q.front();
            q.pop();
            if (popped.x >= m || popped.x < 0) continue;
            if (popped.y >= n|| popped.y < 0) continue;
            if (grid[popped.x][popped.y] == -1) continue;
            if (grid[popped.x][popped.y] < popped.dist) continue;
            grid[popped.x][popped.y] = min(grid[popped.x][popped.y], popped.dist);
            q.push({popped.x+1, popped.y, grid[popped.x][popped.y]+1});
            q.push({popped.x-1, popped.y, grid[popped.x][popped.y]+1});
            q.push({popped.x, popped.y+1, grid[popped.x][popped.y]+1});
            q.push({popped.x, popped.y-1, grid[popped.x][popped.y]+1});
        }
    }
};
