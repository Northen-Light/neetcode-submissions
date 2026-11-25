class TimeMap {
public:
    map<string, vector<pair<string,int>>> mp; 
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back(make_pair(value, timestamp));
    }
    
    string get(string key, int timestamp) {
        vector<pair<string,int>> values = mp[key];
        int low = 0;
        int high = values.size() - 1;
        string value = "";
        while (low <= high) {
            int mid = (low + high) / 2;
            int ansTimestamp = values[mid].second;
            if (ansTimestamp <= timestamp) {
                value = values[mid].first;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return value;
    }
};
