bool cmp(vector<int> &a, vector<int> &b){
    return a[0]<b[0];
}
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),cmp); int count=0;
        int lastInterval = points[0][1];
        for(int i=1; i<points.size(); i++){
            if(points[i][0]<=lastInterval){
                count++;
                lastInterval = min(lastInterval,points[i][1]);
            }
            else lastInterval = points[i][1];
        }
        return points.size()-count;
    }
};