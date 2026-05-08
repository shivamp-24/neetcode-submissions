class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // int n = matrix.size(), m = matrix[0].size();

        // //each row sorted, apply BS on each row, find the target

        // int row = 0, col = m - 1;
        // while(row < n && col >= 0) {
        //     if(matrix[row][col] == target) return true;

        //     if(matrix[row][col] < target) row++;
        //     else col--;
        // }
        // return false;

        // this is O(m + n)

        //solve in log(m*n)
        // find out the row where target will be present
        // low = 0, high = n - 1
        // if target > last element of curr row -> move down
        // if target < first element of curr row -> move up
        // else curr row has target

        // then apply bs on that row

        // above will be two pass
        // to make it one pass
        // convert 2-d tp 1-d, a sorted array we will get
        // apply bs simpul

        int n = matrix.size(), m = matrix[0].size();
        int low = 0, high = n*m - 1;
        while(low <= high) {
            int mid = low + (high - low) / 2;

            int row = mid / m, col = mid % m;
            if(matrix[row][col] == target) return true;
            if(matrix[row][col] < target) low = mid + 1;
            else high = mid - 1;
        }
        return false;
    }
};
