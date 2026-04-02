class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int k = 0; k < n/2; k++){
            for(int i = k; i < n-k-1; i++){
                int a, b, c, d;
                a = matrix[k][i], b = matrix[i][n-k-1], 
                c = matrix[n-k-1][n-i-1], d = matrix[n-i-1][k];
                matrix[i][n-k-1] = a; 
                matrix[n-k-1][n-i-1] = b;
                matrix[n-i-1][k] = c;
                matrix[k][i] = d;
            }
        }
    }
};
