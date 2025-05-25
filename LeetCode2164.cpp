class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        vector<int> res(nums.size());
        vector<int> oddindices;
        vector<int> evenindices;
        for(int i=0;i<nums.size();i++){
            if(i%2==0) evenindices.push_back(nums[i]);
            else oddindices.push_back(nums[i]);
        }
        sort(oddindices.begin(),oddindices.end());
        sort(evenindices.begin(),evenindices.end());
        int idx = 0;
        int odd = oddindices.size()-1;
        int even = 0;
        while(idx<nums.size()){
            if(idx%2==0){
                res[idx] = evenindices[even];
                even++;
            }
            else{
                res[idx] = oddindices[odd];
                odd--;
            }
            idx++;
        }
        return res;
    }
};