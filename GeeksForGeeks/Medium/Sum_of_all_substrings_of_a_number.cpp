class Solution {
  public:
    int sumSubstrings(string &s) {
        // code here
        int prev = 0;
        int sum = 0;
        
        for(int i = 0; i < s.length(); i++){
            int num = s[i] - '0';
            int currSum = prev*10 + num*(i+1);
            
            sum += currSum;
            prev = currSum;
        }
        
        return sum;
    }
};