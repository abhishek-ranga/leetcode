class Solution {
public:
    void fliprow(vector<int> &v){
        for(int i=0; i<v.size(); i++){
            if(v[i]==0) v[i] = 1;
            else if(v[i]==1) v[i] = 0;
        }
        return;
    }
    void flipcol(vector<vector<int>> &v, int col){
        for(int i=0; i<v.size(); i++){
            if(v[i][col]==0) v[i][col] = 1;
            else v[i][col] = 0;
        }
        return;
    }
    int matrixScore(vector<vector<int>>& grid) {
        for(int i=0; i<grid.size(); i++){
            if(grid[i][0]==0) fliprow(grid[i]);
        }
        for(int j=0; j<grid[0].size(); j++){
            int i=0;
            int count0 = 0;
            int count1 = 0;
            while(i<grid.size()){
                if(grid[i][j]==0) count0++;
                else if(grid[i][j]==1) count1++;
                i++;
            }
            if(count0>count1) flipcol(grid,j);
        }
        int output = 0;
        for(int i=0; i<grid.size(); i++){
            int decimal = 0;
            int fact = 1;
            for(int j=grid[i].size()-1; j>=0; j--){
                decimal += (grid[i][j]*fact);
                fact*=2;
            }
            output+=decimal;
        }
        return output;
    }
};