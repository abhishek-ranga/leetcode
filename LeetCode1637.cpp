class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        int ans = 0;
        for(int i=0; i<points.size()-1; i++){
            ans = max(ans,abs(points[i][0]-points[i+1][0]));
        }
        return ans;
    }
};