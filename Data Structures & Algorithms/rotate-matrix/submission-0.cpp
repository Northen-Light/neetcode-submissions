class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        for (int i = 0; i < n; i++) {
            reverse(begin(matrix[i]), end(matrix[i]));
        }

        for (int i = 0, j = n - 1; i < n; i++, j--) {
            for (int k = j; k >= 0; k--) {
                swap(matrix[i][k], matrix[n - 1 - k][n - 1 - i]);
            }
        }
    }
};
