class Solution {
    private:
        priority_queue<int, vector<int>> maxHeap;
    public:
        int findKthLargest(vector<int>& nums, int k) {
            for(int num : nums){
                maxHeap.push(num);
            }
            while(--k) cout << maxHeap.top() << ' ', maxHeap.pop();
            return maxHeap.top();
        }
};
