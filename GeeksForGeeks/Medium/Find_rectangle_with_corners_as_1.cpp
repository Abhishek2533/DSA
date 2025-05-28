// METHOD 1: TC -> O(N*M^2) | SC -> O(N)

class Solution {
  public:
    bool ValidCorner(vector<vector<int> >& mat) {
        // code here
        int totalRows = mat.size();
        if (totalRows == 0) return false;
        int totalCols = mat[0].size();
        
        unordered_set<string> seenPairs;
    
        for (int row = 0; row < totalRows; row++) {
            for (int col1 = 0; col1 < totalCols - 1; col1++) {
                if (mat[row][col1] == 0)
                continue;
                for (int col2 = col1 + 1; col2 < totalCols; col2++) {
                    if (mat[row][col2] == 0)
                    continue;
                    string columnPairKey = to_string(col1) + "," + to_string(col2);
                    if (seenPairs.find(columnPairKey) != seenPairs.end())
                        return true;
                        seenPairs.insert(columnPairKey);
                    }
            }
        }
        return false;
    }
};




// METHOD 2: TC -> O(N*M^2) | SC -> O(1)

class Solution {
  public:
    bool ValidCorner(vector<vector<int> >& mat) {
        // code here
        const int n = mat.size(), m = mat[0].size();
        
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                int count = 0;
                for(int k = 0; k < m; k++) {
                    if(mat[i][k] == 1 && mat[j][k] == 1) count++;
                }
                if(count > 1) return true;
            }
        }
        return false;
    }
};