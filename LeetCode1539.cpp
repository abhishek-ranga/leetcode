class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int lo = 0;
        int hi = arr.size()-1;
        while(lo<=hi){
            int idx = (lo+hi)/2;
            if(arr[idx]-idx>k) hi = idx-1;
            else lo = idx+1;
        }
        return lo+k;
    }
};

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        for (auto a : arr) if (a <= k) k++;
        return k;
    }
};