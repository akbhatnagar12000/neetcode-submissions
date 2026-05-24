class LRUCache {
    list<pair<int,int>> l; 
    unordered_map<int, list<pair<int,int>>::iterator> mp;
    int cap;

public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end()) {
            return -1;
        }

        // Move accessed node to front
        auto it = mp[key];
        int value = it->second;

        l.erase(it);
        l.push_front({key, value});
        mp[key] = l.begin();

        return value;
    }
    
    void put(int key, int value) {

        // If key already exists
        if(mp.find(key) != mp.end()) {
            l.erase(mp[key]);
        }

        // If capacity full
        else if(l.size() == cap) {
            auto last = l.back();
            mp.erase(last.first);
            l.pop_back();
        }

        // Insert new node at front
        l.push_front({key, value});
        mp[key] = l.begin();
    }
};