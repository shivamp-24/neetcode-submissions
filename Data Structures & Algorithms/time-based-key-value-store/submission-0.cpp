class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if(mp.find(key) == mp.end()) return "";
        // in mp[key], find upper_bound - 1 of timestamp, and return the value
        string res = "";
        int low = 0, high = mp[key].size() - 1, mid;
        while(low <= high) {
            mid = (low + high) / 2;

            if(mp[key][mid].first <= timestamp) {
                res = mp[key][mid].second;
                low = mid + 1;
            } else high = mid - 1;
        }
        return res;
    }
};
