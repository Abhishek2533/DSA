/*

Company Tags:

        Paytm
        Zoho
        Flipkart
        Morgan Stanley
        Amazon
        Microsoft
        OYO Rooms
        Samsung
        Snapdeal
        Hike
        MakeMyTrip
        Ola Cabs
        Visa
        Walmart
        Goldman Sachs
        Adobe
        Google
        Yahoo


*/


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// design the class in the most optimal way

class LRUCache {
  private:
  public:
    int cap;
    list<pair<int, int>> List;
    
    unordered_map<int, list<pair<int, int>>::iterator> cacheMap;
    
    // Constructor for initializing the cache capacity with the given value.
    LRUCache(int cap) {
        // code here
        this->cap=cap;
    }

    // Function to return value corresponding to the key.
    int get(int key) {
        // your code here
        auto it=cacheMap.find(key);
        if(it==cacheMap.end()) return -1;
        
        int val=it->second->second;
        List.erase(it->second);
        List.push_front({key, val});
        
        cacheMap[key]=List.begin();
        return val;
    }

    // Function for storing key-value pair.
    void put(int key, int value) {
        // your code here
        auto it = cacheMap.find(key);
        if(it!=cacheMap.end()) {
            List.erase(it->second);
            cacheMap.erase(it);
        }
        
        List.push_front({key, value});
        cacheMap[key]=List.begin();
        
        if(cacheMap.size()>cap) {
            auto lastNode=List.back().first;
            List.pop_back();
            cacheMap.erase(lastNode);
        }
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);

        int queries;
        cin >> queries;
        while (queries--) {
            string q;
            cin >> q;
            if (q == "PUT") {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->put(key, value);
            } else {
                int key;
                cin >> key;
                cout << cache->get(key) << " ";
            }
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends