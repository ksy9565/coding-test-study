//https://leetcode.com/problems/lru-cache/description/

class LRUCache {
public:
    //unordered_map과 list<pair<int, int>> 를 사용?

    int cap;
    list<pair<int, int>> cache;

    unordered_map<int, list<pair<int, int>>::iterator> maps;

    LRUCache(int capacity) {
        cap = capacity;
    }
    
    //key가 없으면 -1, 있으면 반환 후 순서를 앞으로 땡겨와야 함
    int get(int key) {
        //key가 없을 때
        if(maps.find(key) == maps.end()){
            return -1;
        }

        //key가 있을 때
        auto it = maps[key];
        cache.splice(cache.end(), cache, it);

        return it -> second;
    }
    
    //새 값을 넣거나 수정, cap을 넘으면 가장 오래된걸 삭제
    void put(int key, int value) {
        //key가 있음 -> 최근 사용으로 이동
        if(maps.find(key) != maps.end()){
            auto it = maps[key];
            cache.splice(cache.end(), cache, it); // (옮길 위치, 어떤 list에서, 옮길 대상)
            it -> second = value;
        }
        //key가 없음 -> 저장, 초과하면 제일 옛날 거 삭제
        else{
            cache.push_back({key, value});
            maps[key] = prev(cache.end());

            //위치를 초과할 시
            if(cache.size() > cap){
                int d = cache.front().first;

                maps.erase(d);
                cache.pop_front();
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */