/*

Company Tags:
        Flipkart


*/


// User function Template for C++
const int bits = 32;
class TrieNode{
    public :
    TrieNode* children[2];
    TrieNode(){
        memset(children,0,sizeof(children));
    }
};

class Trie{
    public:
    TrieNode* root;
    Trie(){
        root = new TrieNode();
    }
    
    void insert(int num){
        TrieNode* node = root;
        for(int i = bits-1;i>=0;i--){
            int bit = (num>>i) & 1;
            if(node->children[bit] == nullptr) node->children[bit] = new TrieNode();
            node = node->children[bit];
        }
    }
    
    int maxXorr(int num){
        int maxiXor = 0;
        TrieNode* node = root;
        for(int i = bits-1;i>=0;i--){
            int bit = (num>>i) & 1;
            int oppositeBit = 1 - bit;
            if(node->children[oppositeBit]) {
                maxiXor|=(1<<i);
                node = node->children[oppositeBit];
            }
            else
            node = node->children[bit];
        }
        
        return maxiXor;
    }
    
};

class Solution {
  public:
    int maxXor(vector<int> &arr) {
        // code here
        Trie trie;
      int res = 0;
       
      for(int num : arr)
        trie.insert(num);
        
        for(int num : arr)
          res = max(res,trie.maxXorr(num));
          
        return res;
    }
};
