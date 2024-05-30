calss solution {
    public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        // store
        vector<int> ans;

        // no. of rows
        int row = matrix.size();
        // no. col of any row
        int col = matrix[0].size();

        int count =0;

        // total no. of elements
        int total = row*col;

        // index initialize
        int startingRow = 0;
        int startingCol = 0;
        int endingRow = row-1;
        int endingCol = col-1;

        while (count<total) 
        {
            // printing starting row
            for (int index = startingCol; count<total && index <= endingCol; index++)
            {
                ans.push_back(matrix[startingRow][index]);
                count++;
            }
            startingRow++;

            // printing ending col
            for (int index = startingRow; count<total && index <= endingRow; index++)
            {
                ans.push_back(matrix[index][endingCol]);
                count++;
            }
            endingCol--;

            // printing ending row
            for (int index = endingCol; count<total && index >= startingCol; index--)
            {
                ans.push_back(matrix[endingRow][index]);
                count++;
            }
            endingRow--;

            // printing starting col
            for (int index = endingRow; count<total && index >= startingRow; index--)
            {
                ans.push_back(matrix[index][startingCol]);
                count++;
            }
            startingCol++;
        }
        return ans;
    }
}