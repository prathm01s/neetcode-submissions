class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        ios_base::sync_with_stdio(false);
        make_heap(stones.begin(), stones.end());
        int s1, s2;
        while (stones.size() > 1) {
            pop_heap(stones.begin(), stones.end());
            s1 = stones.back();
            stones.pop_back();
            pop_heap(stones.begin(), stones.end());
            s2 = stones.back();
            stones.pop_back();
            if (s1 != s2) {
                stones.push_back(s1 - s2);
                push_heap(stones.begin(), stones.end());
            }
        }
        return stones.size()==1 ? stones[0] : 0;
    }
};
