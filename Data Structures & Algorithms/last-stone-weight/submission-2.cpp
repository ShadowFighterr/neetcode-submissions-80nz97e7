class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        if(stones.size() == 1) return stones[0];
        sort(stones.begin(), stones.end());
        int i, j;
        i = stones.size()-2;
        j = i+1;
        while(i >= 0){
            if(stones[i] == stones[j]) {
                stones.erase(stones.begin()+i), stones.erase(stones.begin()+i);
                if(stones.size() == 0) stones.push_back(0);
                i = stones.size()-2, j = i+1;
            }
            else {
                stones.push_back(stones[j] - stones[i]);
                stones.erase(stones.begin()+i), stones.erase(stones.begin()+i);
                // cout << stones.size() << ' ';
                sort(stones.begin(), stones.end());
                i = stones.size()-2, j = i+1;
            }
        }
        return stones[0];
    }
};
// 2 2 2 3 
