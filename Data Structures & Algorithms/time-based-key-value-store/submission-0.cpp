class TimeMap {
    unordered_map<string, vector<pair<int,string>>> mp;

public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        auto &v = mp[key];

        int l = 0, r = v.size() - 1;
        string ans = "";

        while (l <= r) {
            int m = l + (r - l) / 2;

            if (v[m].first <= timestamp) {
                ans = v[m].second;
                l = m + 1;
            } else {
                r = m - 1;
            }
        }

        return ans;
    }
};