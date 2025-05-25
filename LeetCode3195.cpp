class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int minrow = INT_MAX, maxrow = INT_MIN, mincol = INT_MAX, maxcol=INT_MIN;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j]==1){
                    minrow = min(minrow,i);
                    maxrow = max(maxrow,i);
                    mincol = min(mincol,j);
                    maxcol = max(maxcol,j);
                }
            }
        }
        return (maxrow-minrow+1)*(maxcol-mincol+1);
    }
};