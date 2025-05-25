/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */
 class Solution {
    public:
        int minMeetingRooms(vector<Interval>& intervals) {
            if(intervals.size()==0) return true;
            vector<int> start, ending;
            for(auto el : intervals){
                start.push_back(el.start);
                ending.push_back(el.end);
            }
            sort(start.begin(),start.end());
            sort(ending.begin(),ending.end());
            int i=0, j=0, ans=0, rooms=0;
            while(i<start.size() and j<ending.size()){
                if(start[i]<ending[j]){ // a meeting is starting
                    rooms++;
                    ans = max(ans,rooms);
                    i++;
                }
                else if(start[i]>ending[j]){ // a meeting is ending
                    rooms--;
                    j++;
                }
                else{
                    j++;
                    i++;
                }
            }
            return ans==1;
        }
    };