class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> res(candies.size());
        int maxi = candies[0];
        for(int i=0; i<candies.size(); i++) maxi = max(maxi,candies[i]);
        for(int i=0; i<candies.size(); i++){
            candies[i]+=extraCandies;
            if(candies[i]>=maxi) res[i]=true;
            else res[i]=false;
        }
        return res;
    }
};