class Solution {
  public:
    int minValue(string &s, int k) {
        // code here
        int n=s.size();
        unordered_map<char,int>mp;
        for(char ch:s){
            mp[ch]++;
        }
        vector<int>v;
        for(auto it:mp){
            v.push_back(it.second);
        }
        int n1=v.size();
        while(k--){
            sort(v.begin(),v.end());
            v[n1-1]--;
        }
        int ans=0;
        for(int val:v){
            ans+=val*val;
        }
        return ans;
    }
};