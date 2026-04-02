class LRUCache {

private:
    unordered_map<int, pair<int, list<int>::iterator>> mp;
    list<int> order;
    int n;
public:

    LRUCache(int capacity) {
        this->n = capacity; 
    }

    int get(int key) {
        if(mp.find(key) == mp.end()) return -1;
        order.erase(mp[key].second);
        order.push_back(key);
        mp[key].second = --order.end();
        return mp[key].first;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()) order.erase(mp[key].second);
        else if(mp.size() == n)
        {
            int lru = order.front();
            order.pop_front();
            mp.erase(lru);
        }
        order.push_back(key);
        mp[key] = {value, --order.end()};
    }
};