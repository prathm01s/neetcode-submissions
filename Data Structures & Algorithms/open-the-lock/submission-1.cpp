struct lockState {
    int a, b, c, d, dist;
    lockState(int a, int b, int c, int d, int dist) {
        this->a = a;
        this->b = b;
        this->c = c;
        this->d = d;
        this->dist = dist;
    }
};
class Solution {
public:
    void update(unordered_map<int, int>& dist, int a, int b, int c, int d, int distt, queue<lockState>& q) {
            if (dist.find(getNum(a, b, c, d)) != dist.end()) {
                if (distt + 1 < dist[getNum(a, b, c, d)]) {
                    dist[getNum(a, b, c, d)] = distt + 1;
                    q.push({a, b, c, d, distt+1});
                }
            } else {
                dist[getNum(a, b, c, d)] = distt + 1;
                q.push({a, b, c, d, distt+1});
            }
    }
    int getNum(lockState ls) {
        return ls.a*1000 + ls.b*100 + ls.c*10 + ls.d;
    }
    int getNum(int a, int b, int c, int d) {
        return a*1000 + b*100 + c*10 + d;
    }
    int mat_mod(int a, int b) {
        int rem = a % b;
        return rem < 0 ? rem + b : rem;
    }
    int openLock(vector<string>& deadends, string target) {
        queue<lockState> q;
        q.push({0, 0, 0, 0, 0});
        unordered_map<int, int> dist;
        dist[0] = 0;
        unordered_map<int, int> deadend;
        for (int i = 0;i < deadends.size();i++) {
            string s = deadends[i];
            deadend[getNum(s[0]-'0', s[1]-'0', s[2]-'0', s[3]-'0')] = 1;
        }
        while (!q.empty()) {
            lockState popped = q.front();
            q.pop();
            if (deadend.find(getNum(popped)) != deadend.end()) {
                continue;
            }
            update(dist, mat_mod(popped.a+1, 10), popped.b, popped.c, popped.d, popped.dist, q);
            update(dist, mat_mod(popped.a-1, 10), popped.b, popped.c, popped.d, popped.dist, q);
            update(dist, popped.a, mat_mod(popped.b+1, 10), popped.c, popped.d, popped.dist, q);
            update(dist, popped.a, mat_mod(popped.b-1, 10), popped.c, popped.d, popped.dist, q);
            update(dist, popped.a, popped.b, mat_mod(popped.c+1, 10), popped.d, popped.dist, q);
            update(dist, popped.a, popped.b, mat_mod(popped.c-1, 10), popped.d, popped.dist, q);
            update(dist, popped.a, popped.b, popped.c, mat_mod(popped.d+1, 10), popped.dist, q);
            update(dist, popped.a, popped.b, popped.c, mat_mod(popped.d-1, 10), popped.dist, q);
        }
        if (dist.find(getNum(target[0]-'0', target[1]-'0', target[2]-'0', target[3]-'0')) == dist.end()) {
            return -1;
        } else {
            return dist[getNum(target[0]-'0', target[1]-'0', target[2]-'0', target[3]-'0')];
        }
    }
};