/*

Problem Statement

You're a developer at Instagram building a new profile picture editor. When users upload square photos, they often need to be rotated to the correct orientation. Implement a feature that rotates a square photo by 90 degrees clockwise.


Input

An integer (n) representing the size of the matrix.
A 2D array (matrix) representing a square photo. Each element of the array contains an integer (for simplicity, think of it as a pixel value).
    The size of the matrix is (n x n) where (1 <= n <= 10^3).
    The matrix contains only integers between 0 and 255, inclusive (simulating RGB pixel values).


Output Format

Return the rotated matrix after rotating it 90 degrees clockwise.
Your task is to just write a function to rotate the image.


Example

Input:
3
1 2 3
4 5 6
7 8 9

    
Output: 
7 4 1
8 5 2
9 6 3


Constraints:
1 <= n <= 10^3
0 ≤ matrix[i][j] ≤ 255


*/


// SOURCE CODE


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// you need to implement this function only
void rotate(vector<vector<int>>& matrix) {
    // your code here
    int n=matrix.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    //reversing each row of the matrix
    for (int i = 0; i < n; i++) {
        reverse(matrix[i].begin(), matrix[i].end());
    }
}
int main() {
    vector<vector<int>> matrix;
    int n;
    cin >> n;
    // please don't modify the main function
    for (int i = 0; i < n; i++) {
        vector<int> row;
        for (int j = 0; j < n; j++) {
            int x;
            cin >> x;
            row.push_back(x);
        }
        matrix.push_back(row);
    }
    rotate(matrix);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j == n - 1) {
                cout << matrix[i][j];
            } else {
                cout << matrix[i][j] << " ";
            }
        }
        if (i != n - 1) { 
            cout << endl;
        }
    }
    return 0;
}
