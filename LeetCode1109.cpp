// line sweep algorithm
class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& a, int n) {
        vector<int> ans(n);
        for(int i=0; i<a.size(); i++){
            ans[a[i][0]-1] += a[i][2];
            if(a[i][1]<n) ans[a[i][1]]-=a[i][2];
        }
        for(int i=1; i<ans.size(); i++) ans[i]+=ans[i-1];
        return ans;
    }
};

class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> ans(n);
        for(int i=0; i<bookings.size(); i++){
            for(int j=bookings[i][0]; j<=bookings[i][1]; j++){
                ans[j-1]+=bookings[i][2];
            }
        }
        return ans;
    }
};