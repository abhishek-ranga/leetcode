class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> res;
        // binary search to check whether element is present or not
        int lo = 0;
        int hi = arr.size()-1;
        bool flag = false; //element is not present in the array
        int mid;
        while(lo<=hi){
            mid = (lo+hi)/2;
            if(arr[mid]==x){
                flag=true;
                res.push_back(arr[mid]);
                k--;
                break;
            }
            else if(arr[mid]<x) lo = mid+1;
            else hi = mid-1;
        }
        if(flag==true){ // element is present in the array
            lo = mid-1;
            hi = mid+1;
            while(lo>=0 && hi<=arr.size()-1 && k>0){
                if(abs(arr[lo]-x) < arr[hi]-x){
                    res.push_back(arr[lo]);
                    lo--;
                } 
                else if(abs(arr[lo]-x)==arr[hi]-x && (arr[lo] < arr[hi])){
                    res.push_back(arr[lo]);
                    lo--;
                } 
                else{
                    res.push_back(arr[hi]);
                    hi++;
                }
                k--;
            }
            // if(k==0) return res;
            if(lo==-1){
                while(hi<=arr.size()-1 && k>0){
                    res.push_back(arr[hi]);
                    hi++;
                    k--;
                }
            }
            if(hi==arr.size()){
                while(lo>=0 && k>0){
                    res.push_back(arr[lo]);
                    lo--;
                    k--;
                }
            }
            sort(res.begin(),res.end());
            return res;
        }
        if(flag==false){
            if(hi==-1){
                while(lo<arr.size() && k>0){
                    res.push_back(arr[lo]);
                    lo++;
                    k--;
                }
            }
            if(lo==arr.size()){
                while(hi>=0 && k>0){
                    res.push_back(arr[hi]);
                    hi--;
                    k--;
                }
            }
            swap(lo,hi);
            while(lo>=0 && hi<=arr.size()-1 && k>0){
                if(abs(arr[lo]-x) < abs(arr[hi]-x)){
                    res.push_back(arr[lo]);
                    lo--;
                } 
                else if(abs(arr[lo]-x)==abs(arr[hi]-x) && (arr[lo] < arr[hi])){
                    res.push_back(arr[lo]);
                    lo--;
                } 
                else{
                    res.push_back(arr[hi]);
                    hi++;
                }
                k--;
            }
            if(lo==-1){
                while(hi<=arr.size()-1 && k>0){
                    res.push_back(arr[hi]);
                    hi++;
                    k--;
                }
            }
            if(hi==arr.size()){
                while(lo>=0 && k>0){
                    res.push_back(arr[lo]);
                    lo--;
                    k--;
                }
            }
        }
        sort(res.begin(),res.end());
        return res;
    }
};

// time complexity -> 1 logn to search the element / upper bound & lower bound
// T.C.-> O(logn + k), since n>>>>k toh k ignore ho jayega and sirf logn meri cheez hai. 
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        vector<int> ans(k);
        if(x<arr[0]) for(int i=0;i<k;i++) ans[i]=arr[i];
        return ans;
        if(x>arr[n-1]){
            int i = n-1, j = k-1;
            while(j>=0){
                ans[j]=arr[i];
                j--;
                i--;
            }
            return ans;
        }
        // binary search.
        int low = 0;
        int high = n-1;
        bool flag = false; // tells whether the element is present or not.
        int t = 0; // t humara ans array par traverse karega.
        int mid = -1;
        while(low<=high){
            mid = low + (high-low)/2;
            if(arr[mid]==x){
                flag = true; // element present
                ans[t] = arr[mid];
                t++;
                break;
            }
            else if(arr[mid]>x) high = mid-1;
            else low = mid+1;
        }
        int lb = arr[high];
        int ub = arr[low];
        if(flag==true){
            lb = mid-1;
            ub = mid+1;
        }
        while(t<k&&lb>=0&&ub<n){
            int d1 = abs(x-arr[lb]);
            int d2 = abs(x-arr[ub]);
            if(d1<=d2){
                ans[t]=arr[lb];
                lb--;
            }
            else{ // d2<d1
                ans[t]=arr[ub];
                ub++;
            }
            t++;
        }
        if(lb<0){
            while(t<k){
                ans[t]=arr[ub];
                t++;
                ub++;
            }
        }
        if(ub>n-1){
            while(t<k){
                ans[t]=arr[lb];
                t++;
                lb--;
            }
        }
        return ans;
    }
};