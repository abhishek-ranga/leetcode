// 2D Array 2 - Spiral Print.

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int minrow = 0;
        int maxrow = m-1;
        int mincol = 0;
        int maxcol = n-1;
        vector<int> res;
        while(minrow<=maxrow && mincol<=maxcol){
            for(int j=mincol; j<=maxcol; j++){
                res.push_back(matrix[minrow][j]);
            }
            minrow++;
            if(minrow>maxrow || mincol>maxcol) break;
            for(int i=minrow; i<=maxrow; i++){
                res.push_back(matrix[i][maxcol]);
            }
            maxcol--;
            if(minrow>maxrow || mincol>maxcol) break;
            for(int j=maxcol; j>=mincol; j--){
                res.push_back(matrix[maxrow][j]);
            }
            maxrow--;
            if(minrow>maxrow || mincol>maxcol) break;
            for(int i=maxrow; i>=minrow; i--){
                res.push_back(matrix[i][mincol]);
            }
            mincol++;
            if(minrow>maxrow || mincol>maxcol) break;
        }
        return res;
    }
};