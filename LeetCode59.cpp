class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n,vector<int>(n));
        int minrow = 0;
        int maxrow = n-1;
        int mincol = 0;
        int maxcol = n-1;
        int put = 1;
        while(minrow<=maxrow && mincol<=maxcol){
            for(int j=mincol; j<=maxcol; j++){
                matrix[minrow][j] = put;
                put++;
            }
            minrow++;
            if(minrow>maxrow) break;
            for(int i=minrow; i<=maxrow; i++){
                matrix[i][maxcol] = put;
                put++;
            }
            maxcol--;
            if(mincol>maxcol) break;
            for(int j=maxcol; j>=mincol; j--){
                matrix[maxrow][j] = put;
                put++;
            }
            maxrow--;
            if(minrow>maxrow) break;
            for(int i=maxrow; i>=minrow; i--){
                matrix[i][mincol] = put;
                put++;
            }
            mincol++;
            if(mincol>maxcol) break;
        }
        return matrix;
    }
};