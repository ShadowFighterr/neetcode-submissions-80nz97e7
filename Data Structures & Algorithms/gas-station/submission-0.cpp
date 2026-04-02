class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        for(int i = 0; i < gas.size(); i++){
            if(check(gas, cost, gas.size(), 0, i, 0)){
                return i;
            }
        }
        return -1;
    }
    
    bool check(vector<int>& gas, vector<int>& cost, int pathnum, int cur, int i, int cnt){
        if(cur == pathnum) return true;
        if(i == gas.size()) i = 0;
        cnt+=gas[i];
        if(cnt < cost[i]) return false;
        if(check(gas, cost, pathnum, cur+1, i+1, cnt-cost[i])) return true;
        return false;
    }
};
