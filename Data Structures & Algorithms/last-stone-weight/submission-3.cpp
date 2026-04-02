class Solution {
    private:
        priority_queue<int, vector<int>> maxHeap;
        
    public:
        int lastStoneWeight(vector<int>& stones) {
            int i = stones.size()-1;
            while(i >= 0){
                maxHeap.push(stones[i]);
                --i;
            }
            while(maxHeap.size() > 1){
                int y = maxHeap.top();
                maxHeap.pop();
                int x = maxHeap.top();
                maxHeap.pop();
                if(x < y) maxHeap.push(y-x);
            }
            return ((maxHeap.empty()) ? 0 : maxHeap.top());
        }
};
