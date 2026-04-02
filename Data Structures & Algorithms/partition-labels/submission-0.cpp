class Solution {
public:
    vector<int> partitionLabels(string s) {
        map<char, pair<int, int>> interval;
        for (char letter : s) {
            interval.try_emplace(letter, -1, 0);
        }
        for(int i = 0; i < s.size(); i++){
            if(interval[s[i]].first != -1){
                interval[s[i]].second = i;
            }
            else interval[s[i]].first = i;
        }
        vector<vector<int>> intervals;
        for(int i = 0; i < 26; i++){
            char c = (char)('a'+i);
            if(interval[c].first != -1 && interval[c].second == 0) interval[c].second = interval[c].first;
            intervals.push_back({interval[c].first, interval[c].second});
        }
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        res.push_back(intervals[0]);
        for(auto& interval : intervals){
            int start = interval[0];
            int end = interval[1];
            int lastEnd = res.back()[1];

            if(start <= lastEnd){
                res.back()[1] = max(lastEnd, end);
            }
            else {
                res.push_back({start, end});
            }
        }
        vector<int> ans;
        for(vector<int>& v : res){
            ans.push_back(v[1]-v[0]+1);
        }
        return ans;
    }
};
