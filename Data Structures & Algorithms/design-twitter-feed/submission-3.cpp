class Twitter {
map<int, vector<pair<int, int>>> mp;
map<int, vector<int>> connected;
int cur = 1;
public:

    Twitter() {
    }
    
    void postTweet(int userId, int tweetId) {
        mp[userId].push_back({tweetId, cur});
        ++cur;

    }
    
    vector<int> getNewsFeed(int userId) {
        vector<pair<int, int>> vec;
        vector<int> res;
        for(auto const& [key, value] : mp[userId]){
            vec.push_back({value, key});
        } 
        map<int, bool> exists;
        for(int x : connected[userId])
            for(const auto& [key, value] : mp[x]) 
                vec.push_back({value, key}); 
        sort(vec.rbegin(), vec.rend());
        for(int i = 0; i < 10; i++){
            if(i >= vec.size()) break;
            if(!exists[vec[i].second]) res.push_back(vec[i].second);
            exists[vec[i].second] = true;
        }
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        if(find(connected[followerId].begin(), connected[followerId].end(), followeeId) == connected[followerId].end())connected[followerId].push_back(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        auto it = find(connected[followerId].begin(), 
        connected[followerId].end(), followeeId);
        if(it != connected[followerId].end()) connected[followerId].erase(it);
        for(int x : connected[followerId]) cout << x << ' ';
    }
};
