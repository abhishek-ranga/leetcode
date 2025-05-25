class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int m = matrix.size(); // no. of rows.
        int n = matrix[0].size(); // no. of columns.
        // int transpose[n][m];
        vector<vector<int>> transpose(n,vector<int>(m));
        for(int j=0; j<n; j++){
            for(int i=0; i<m; i++){
                transpose[j][i] = matrix[i][j];
            }
        }
        return transpose;
    }
};