class Solution {
    private:
        priority_queue<pair<double, vector<int>>, vector<pair<double, vector<int>>>, greater<>> minHeap;
    public:
        vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
            for(vector<int> coords : points){
                double dist;
                int x, y;
                x = coords[0];
                y = coords[1];
                dist = sqrt((x*x) + (y*y));
                minHeap.push({dist, coords});
            }
            vector<vector<int>> vec;
            for(int i = 0; i < k; i++){
                vec.push_back(minHeap.top().second);
                minHeap.pop();
            }
            return vec;
        }
};
