class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(j>i){
                    int temp = matrix[i][j];
                    matrix[i][j] = matrix[j][i];
                    matrix[j][i] = temp;
                }
            }
        }
        for(int i=0; i<m; i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }
        return;
    }
};

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        // transpose
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                // swapping i,j with j,i.
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
        // reverse each row
        for(int k=0; k<n; k++){ // to traverse each row.
            int i = 0;
            int j = n-1;
            while(i<j){ // swapping k,i with k,j.
                int temp = matrix[k][i];
                matrix[k][i] = matrix[k][j];
                matrix[k][j] = temp;
                i++;
                j--;
            }
        }
        return;
    }
};