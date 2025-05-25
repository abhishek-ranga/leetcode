bool cmp(vector<int> &a, vector<int> &b){
    return a[0]<b[0];
}
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),cmp); int count=0;
        int lastEndTime=intervals[0][1];
        for(int i=1; i<intervals.size(); i++){
            if(intervals[i][0]<lastEndTime){
                count++;
                lastEndTime = min(lastEndTime,intervals[i][1]);
            }
            else{
                lastEndTime=intervals[i][1];
            }
        }
        return count;
    }
};

bool cmp(vector<int> &a, vector<int> &b){
    return a[1]<b[1];
}
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),cmp); int count=0;
        int lastEndTime=intervals[0][1];
        for(int i=1; i<intervals.size(); i++){
            if(intervals[i][0]<lastEndTime){
                count++;
            }
            else{
                lastEndTime=intervals[i][1];
            }
        }
        return count;
    }
};


bool cmp(vector<int> &a, vector<int> &b){
    return a[0]<b[0];
}
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),cmp); int count=0;
        vector<vector<int>> result; int n = intervals.size();
        result.push_back(intervals[0]);
        for(int i=1; i<n; i++){
            vector<int> &lastInterval = result[result.size()-1];
            vector<int> curr = intervals[i];
            if(curr[0]<lastInterval[1]){
                count++;
                lastInterval[0] = min(lastInterval[0],curr[0]);
                lastInterval[1] = min(lastInterval[1],curr[1]);
            }
            else{
                result.push_back(intervals[i]);
            }
        }
        return count;
    }
};