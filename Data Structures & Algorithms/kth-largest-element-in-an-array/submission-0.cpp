class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // make heap and pop k times 
        // time - O(n + klogn), memory - O(1)
        ////
        // make a max heap of first k elements, then traverse rest of the
        // array, keep a counter that counts no. of times we pop
        // from this max heap, ensure size of the heap is at max k always
        // when counter reaches 0, return the most recently popped element
        vector<int> heap = vector<int>(nums.begin(), min(nums.end(), nums.begin()+k)); 
        make_heap(heap.begin(), heap.end(), greater<int>());
        for (int i = k;i < nums.size();i++) {
            int top = heap.front();
            if (nums[i] > top) {
                pop_heap(heap.begin(), heap.end(), greater<int>());
                heap.pop_back();
                heap.push_back(nums[i]);
                push_heap(heap.begin(), heap.end(), greater<int>());
            }
        }
        return heap.front();
    }
};
