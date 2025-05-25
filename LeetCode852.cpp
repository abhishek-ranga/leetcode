class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int low = 0, high = arr.size()-1;
        while(low<=high){
            int mid = (low+high)/2;
            if(arr[mid]>arr[mid+1]&&arr[mid]>arr[mid-1]) return mid;
            else if(arr[mid]>arr[mid+1]) high = mid-1;
            else low = mid+1;
        }
        return -1;
    }
};

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int idx = -1;
        for(int i=1;i<=arr.size()-2;i++){
            if(arr[i]>arr[i-1]&&arr[i]>arr[i+1]){
                idx = i;
                break;
            }
        }
        return idx;
    }
};

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        vector<int> a = arr;
        sort(arr.begin(),arr.end());
        int largest = arr[arr.size()-1];
        int low = 0, high = a.size()-1;
        while(low<=high){
            int mid = (low+high)/2;
            if(a[mid]==largest) return mid;
            else if(a[mid]>=a[mid+1]) high = mid-1;
            else low = mid+1;
        }
        return -1;
    }
};