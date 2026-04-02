class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n%groupSize != 0) return false;
        sort(hand.begin(), hand.end());
        vector<bool> visited(n, false);
        while(n > 0){
            if(!backtrack(hand, groupSize, visited, 0, -1)){
                return false;
            }
            n-=groupSize;
        }
        return true;
    }
    // 2 3  4 5
    bool backtrack(vector<int>& hand, int groupSize, vector<bool>& visited, int i, int prev){
        if(groupSize == 0) return true;
        if(prev == -1){
            while(i < hand.size() && visited[i]){
                ++i;
            }
            if(i >= hand.size()) return false;
            prev = hand[i]-1;
        }
        while(i < hand.size()){
            if(!visited[i] && hand[i]-prev == 1) {
                break;
            }
            ++i;
        }
        if(i >= hand.size()) return false;
        visited[i] = true;
        if(backtrack(hand, groupSize-1, visited, i+1, hand[i])){
            return true;
        }
        return false;
    }
};
