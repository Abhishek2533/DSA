// User function Template for C++

class Solution {
  public:
    vector<int> minPartition(int N) {
        // code here
        vector<int> currency = { 1, 2, 5, 10, 20, 50, 100, 200, 500, 2000 };
        vector<int> res;
        int i=currency.size()-1;
        while(N){
            if(currency[i]<=N){
                res.push_back(currency[i]);
                N-=currency[i];
            }
            else{
                i--;
            }
        }
        return res;
    }
};