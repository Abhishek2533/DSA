// User function Template for C++
class Solution {
  public:
    int findDuplicate(vector<int>& arr) {
        // code here
        int num=0,sum=0;
        for(int i=1;i<arr.size();i++)num+=i;
        for(int i:arr)sum+=i;
        return sum-num;
    }
};