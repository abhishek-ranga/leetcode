class Solution {
public:
    int partition(vector<int> &v, int start, int end){
        int pivotElement = v[(start+end)/2];
        int count = 0;
        for(int i=start; i<=end; i++){
            if(i==(start+end)/2) continue;
            if(v[i]<=pivotElement) count++;
        }
        int pivotIndex = count + start;
        swap(v[(start+end)/2],v[pivotIndex]);
        int i = start, j = end;
        while(i<pivotIndex && j>pivotIndex){
            if(v[i]<=pivotElement) i++;
            if(v[j]>pivotElement) j--;
            else if(v[i]>pivotElement && v[j]<=pivotElement) swap(v[i++],v[j--]);
        }
        return pivotIndex;
    }
    int KthLargest(vector<int> &v, int start, int end, int k){
        int pivotIdx = partition(v,start,end);
        if(pivotIdx==v.size()-k) return v[pivotIdx];
        else if(pivotIdx>v.size()-k) return KthLargest(v,start,pivotIdx-1,k);
        else return KthLargest(v,pivotIdx+1,end,k);
    }
    int findKthLargest(vector<int>& v, int k) {
        int start = 0;
        int end = v.size()-1;
        return KthLargest(v,start,end,k);
    }
};

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //partition rule: >=pivot   pivot   <=pivot
        int left=0,right=nums.size()-1,idx=0;
        while(1){
            idx = partition(nums,left,right);
            if(idx==k-1) break;
            else if(idx < k-1) left=idx+1;
            else right= idx-1;
        }
        return nums[idx];
    }
    int partition(vector<int>& nums,int left,int right){//hoare partition
        int pivot = nums[left], l=left+1, r = right;
        while(l<=r){
            if(nums[l]<pivot && nums[r]>pivot) swap(nums[l++],nums[r--]);
            if(nums[l]>=pivot) ++l;
            if(nums[r]<=pivot) --r;
        }
        swap(nums[left], nums[r]);
        return r;
    }
};