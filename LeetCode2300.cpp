class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> ans(spells.size()); sort(potions.begin(),potions.end());
        for(int i=0; i<spells.size(); i++){
            int lo=0, hi=potions.size()-1; int k=0;
            while(lo<=hi){
                int mid = (lo+hi)/2;
                long long nigga = (long long)(potions[mid])*(long long)(spells[i]);
                if(nigga>=success){
                    if(mid!=0 && (long long)(potions[mid-1])*(long long)(spells[i])>=success) hi=mid-1;
                    else{
                        k = potions.size()-mid;
                        break;
                    }
                }
                else if(nigga<success) lo=mid+1;
            }
            ans[i]=k;
        }
        return ans;
    }
};