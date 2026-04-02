class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<double, double>> v;
        for(int i = 0; i < position.size(); i++)
            v.push_back({(double)position[i], (double)speed[i]});
        sort(v.rbegin(), v.rend());
        // stack<pair<pair<int, int>, int>> st;
        stack<pair<double, double>> st;
        st.push({v[0].first, v[0].second});
        for(int i = 1; i < position.size(); i++)
        {
            double x = ((target-st.top().first)/st.top().second);// + ((target-st.top().first)%st.top().second > 0);
            double y = ((target - v[i].first)/v[i].second);// + ((target - v[i].first)%v[i].second > 0);
            // 3 4 5 6 7 8
            cout << x << ' ' << y << '\n';
            if(x >= y)
            {
                continue;
                // st.top().first = v[i].first, st.top().second = v[i].second;
            }
            else st.push({v[i].first, v[i].second});
            // if((st.top().first.second * st.top().second) >= v[i].first) 
            // st.top().second++;
        }    
        return st.size();
    }
};
