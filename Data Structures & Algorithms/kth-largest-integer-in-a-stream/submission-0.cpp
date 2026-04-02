class KthLargest {
public:
    set<int> s;
    map<int, int> mp;
    int cur;
    KthLargest(int k, vector<int>& nums) {
        for(int x : nums) s.insert(x), mp[x]++;
        cur = k;
    }
    
    int add(int val) {
        mp[val]++;
        s.insert(val);
        int tmp = cur;
        stack<int> st;
        for(int x : s){
            st.push(x);
        }
        while(tmp > 0){
            if(tmp - mp[st.top()] <= 0) return st.top();
            tmp-=mp[st.top()];
            st.pop();
        }
    }
};
