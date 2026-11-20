
class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> store;

    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        store[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {

    if (store.find(key) == store.end()) {
        return "";
    }

    auto &v = store[key];

    int low = 0;
    int high = v.size() - 1;
    int ans = -1;

    while (low <= high) {

        int mid = low + (high - low) / 2;

        if (v[mid].first <= timestamp) {
            ans = mid;
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    if (ans == -1) {
        return "";
    }

    return v[ans].second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key, value, timestamp);
 * string param_2 = obj->get(key, timestamp);
 */
