class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int sum = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==j) sum+=mat[i][j];
                if(i+j==m-1) sum+=mat[i][j];
            }
        }
        if(m%2!=0) sum-=mat[(m-1)/2][(n-1)/2];
        return sum;
    }
};

class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int m = mat.size();
        int sum = 0;
        for(int i=0;i<m;i++){
            sum+=mat[i][i];
            sum+=mat[i][m-1-i];
        }
        if(m%2!=0) sum-=mat[m/2][m/2];
        return sum;
    }
};