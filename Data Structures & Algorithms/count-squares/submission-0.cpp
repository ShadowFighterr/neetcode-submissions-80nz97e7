class CountSquares {
public:
    map<pair<int, int>, int> freq;
    CountSquares() {
        
    }
    
    void add(vector<int> point) {
        int x, y;
        x = point[0], y = point[1];
        freq[{x, y}]++;
    }
    
    int count(vector<int> point) {
        int x, y;
        x = point[0], y = point[1];
        int res = 0;
        for(auto &[p, cnt] : freq){
            int x2 = p.first, y2 = p.second;
            if(x == x2 && y != y2){
                int d = y2-y;
                res+=cnt * freq[{x+d, y}] * freq[{x+d, y2}];
                res+=cnt * freq[{x-d, y}] * freq[{x-d, y2}];
            }
        }
        return res;
    }
};
