class Solution {
  public:
    int findUnique(vector<int> &arr) {
        // code here
        int xorr=0;
        for(int num : arr) xorr^=num;
        
        return xorr;
    }
};