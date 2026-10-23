class LRUCache {
public:
int capacity;
    list<pair<int,int>> dll;
    unordered_map<int, list<pair<int, int>>::iterator> mp;
    LRUCache(int capacity) {
        this->capacity=capacity;
    }
    
    int get(int key) {
        if(mp.find(key)==mp.end()) return -1;
        auto it=mp[key];
        int value=it->second;
        dll.erase(it);
        dll.push_front({key,value});
        mp[key]=dll.begin();
        return value;
    }
    
    void put(int key, int value) {
        if (mp.find(key)!=mp.end()) {
            dll.erase(mp[key]);
            mp.erase(key);
        }
        if (dll.size()==capacity) {
            int lruKey=dll.back().first;
            dll.pop_back();
            mp.erase(lruKey);
        }
        dll.push_front({key,value});
        mp[key]=dll.begin();
    }
};
