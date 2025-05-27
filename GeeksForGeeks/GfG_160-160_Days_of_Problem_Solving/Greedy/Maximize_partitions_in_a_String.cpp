// METHOD 1: TC -> O(N) | SC -> O(1)

class Solution {
  public:
    int maxPartitions(string &s) {
        // code here
        vector<int> last(26, -1);
        for(int i=0; i<s.size(); i++) last[s[i]-'a']=i;
        
        int count=0;
        int a=-1;
        
        for(int i=0; i<s.size(); i++) {
            a=max(last[s[i]-'a'], a);
            if(a==i) count++;
        }
        
        return count;
    }
};