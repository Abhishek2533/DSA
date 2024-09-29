/*

432. All O`one Data Structure


Design a data structure to store the strings' count with the ability to return the strings with minimum and maximum counts.
Implement the AllOne class:
AllOne() Initializes the object of the data structure.
inc(String key) Increments the count of the string key by 1. If key does not exist in the data structure, insert it with count 1.
dec(String key) Decrements the count of the string key by 1. If the count of key is 0 after the decrement, remove it from the data structure. It is guaranteed that key exists in the data structure before the decrement.
getMaxKey() Returns one of the keys with the maximal count. If no element exists, return an empty string "".
getMinKey() Returns one of the keys with the minimum count. If no element exists, return an empty string "".
Note that each function must run in O(1) average time complexity.


Example 1:
Input
["AllOne", "inc", "inc", "getMaxKey", "getMinKey", "inc", "getMaxKey", "getMinKey"]
[[], ["hello"], ["hello"], [], [], ["leet"], [], []]
Output
[null, null, null, "hello", "hello", null, "hello", "leet"]
Explanation
AllOne allOne = new AllOne();
allOne.inc("hello");
allOne.inc("hello");
allOne.getMaxKey(); // return "hello"
allOne.getMinKey(); // return "hello"
allOne.inc("leet");
allOne.getMaxKey(); // return "hello"
allOne.getMinKey(); // return "leet"


Constraints:
1 <= key.length <= 10
key consists of lowercase English letters.
It is guaranteed that for each call to dec, key is existing in the data structure.
At most 5 * 104 calls will be made to inc, dec, getMaxKey, and getMinKey.


*/


// SOURCE CODE




// USING UNORDERED MAP

class AllOne {
public:
    unordered_map<string, int> mpp;
    AllOne() {
        int count;
    }
    
    // O(1)
    void inc(string key) {
        mpp[key]++;
    }
    
    // O(1)
    void dec(string key) {
        mpp[key]--;
        
    }
    
    // O(n)
    string getMaxKey() {
        int maxi=0;
        string ans="";
        for(auto& key : mpp) {
            if(key.second > maxi) {
                maxi=key.second;
                ans=key.first;
            }
        }
        return ans;
    }
    
    // O(n)
    string getMinKey() {
        int mini=INT_MAX;
        string ans="";
        for(auto& key : mpp) {
            if(key.second!=0 && key.second < mini) {
                mini=key.second;
                ans=key.first;
            }
        }
        return ans;
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */









// USING SET AND UNORDERED MAP

class AllOne {
public:
    unordered_map<string, int> mpp;
    set<pair<int, string>> st;
    AllOne() {
        // int count;
    }
    
    // O(logn)
    void inc(string key) {
        st.erase({mpp[key], key});  // remove because frequency is not updated
        mpp[key]++;
        st.insert({mpp[key], key}); // after frequency updated add again
    }
    
    // O(logn)
    void dec(string key) {
        st.erase({mpp[key], key});  // remove because frequency is not updated
        mpp[key]--;
        if(mpp[key] > 0) st.insert({mpp[key], key}); // after frequency updated add again only if it still remains
        
    }
    
    // O(1)
    string getMaxKey() {
        if(st.size() == 0) return "";
        string ans = prev(st.end()) -> second;    // prev = inbuilt function which moves pointer backward
        return ans;
    }
    
    // O(1)
    string getMinKey() {
        if(st.size() == 0) return "";
        string ans = st.begin() -> second;    // prev = inbuilt function which moves pointer backward
        return ans;
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */











// OPTIMIZE - DLL

// DLL
struct Node {
    string word;
    int count;
    Node* prev;
    Node* next;

    Node(string k) : word(k), count(1), prev(nullptr), next(nullptr) {}
};

class AllOne {
public:
    Node *head, *tail;
    unordered_map<string, Node*> mpp;

    AllOne() {
        head = new Node("");
        tail = new Node("");
        head->next = tail;
        tail->prev = head;
    }

    // moving character to new node if its count increase
    void moveToCorrectNextPosition(Node* node) {
        Node* ptr = node->next;
        // checkig if any node exist with current frequency
        while (ptr != tail && node->count > ptr->count) {
            ptr = ptr->next;
        }

        if (ptr != node->next) {
            // remove node from current place
            node->prev->next = node->next;
            node->next->prev = node->prev;

            // add it to new place before ptr
            ptr->prev->next = node;
            node->prev = ptr->prev;
            node->next = ptr;
            ptr->prev = node;
        }
    }

    // moving character to new node as its frequency decreased
    void moveToCorrectPrevPosition(Node* node) {
        Node* ptr = node->prev;
        // checkig if any node exist with current frequency
        while (ptr != head && node->count < ptr->count) {
            ptr = ptr->prev;
        }

        if (ptr != node->prev) {
            // remove node from current place
            node->prev->next = node->next;
            node->next->prev = node->prev;

            // add it to new place before ptr
            ptr->next->prev = node;
            node->next = ptr->next;
            node->prev = ptr;
            ptr->next = node;
        }
    }

    void inc(string key) {
        if (mpp.find(key) != mpp.end()) {
            // already present -> update its count
            Node* node = mpp[key];
            node->count++;

            // fix node position after upgrade
            moveToCorrectNextPosition(node);
        } else {
            // create a new node
            Node* node = new Node(key);
            node->next = head->next;
            node->prev = head;

            head->next->prev = node;
            head->next = node;

            // store it in map
            mpp[key] = node;

            // insert it into the list
            moveToCorrectNextPosition(node);
        }
    }

    void dec(string key) {
        Node* node = mpp[key];
        node->count--;

        moveToCorrectPrevPosition(node);

        // Here node will be at first position just next to head
        // if freq of node is zero then we follow same logic and
        if (node->count == 0) {
            node->next->prev = node->prev;
            node->prev->next = node->next;
            mpp.erase(key);
            delete node;
        }
    }

    string getMaxKey() {
        string ans = "";
        if (tail->prev != head) ans = tail->prev->word;
        return ans;
    }

    string getMinKey() {
        string ans = "";
        if (head->next != tail) ans = head->next->word;
        return ans;
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */