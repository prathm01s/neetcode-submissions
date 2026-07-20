class KthLargest {
    vector<int> heap;
    int k;
public:
    KthLargest(int k, vector<int>& nums) {
        heap = nums;
        this->k = k;
        make_heap(heap.begin(), heap.end());
    }
    
    int add(int val) {
        heap.push_back(val);
        push_heap(heap.begin(), heap.end());
        return getKthLargest();
    }

    int getKthLargest() {
        int temp = k;
        vector<int> t = heap;
        int ans;
        while (temp--) {
            pop_heap(t.begin(), t.end());
            ans = t.back();
            t.pop_back();
        }
        return ans;
    }
};
