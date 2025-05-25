class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int maxi = 0;
        for(int i=0; i<gain.size(); i++){
            if(i==0) gain[i]+=0;
            else gain[i]+=gain[i-1];
            maxi = max(maxi,gain[i]);
        } 
        return maxi;
    }
};