class Solution {
  public:
    int countPairs(vector<vector<int>> &mat1, vector<vector<int>> &mat2, int x) {
        // code here
        int n = mat1.size();
        int i = 0, j = n*n -1;
        
        int res = 0;
        
        while(i<(n*n) && j>=0){
            int row1 = i/n, col1 = i%n;
            int row2 = j/n, col2 = j%n;
            
            int val = mat1[row1][col1] + mat2[row2][col2];
            if(val == x){
                res++;
                i++;
                j--;
            }
            else if(x > val)
                i++;
            else
                j--;
        }
        return res;
    }
};