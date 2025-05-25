class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> res = digits;
        int i = digits.size()-1;
        res[i]++;
        while(i>0){
            if(res[i]==10){
                res[i]=0;
                i--;
                res[i]++;
            }
            else break;
        }
        if(i==0&&res[i]==10){
            res[i]=1;
            res.push_back(0);
        }
        return res;
    }
};