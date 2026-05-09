class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        // swap elements across main-diagonal
        // reverse all rows
        // or
        // swap elements across anti-diagonal
        // reverse all columns

        // swap elements across main-diagonal
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // reverse all rows
        for(int i=0; i<n; i++) reverse(matrix[i].begin(), matrix[i].end());
    }
};
