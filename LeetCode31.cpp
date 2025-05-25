#include<iostream>
#include<vector>
using namespace std;
void nextPermutation(vector<int>& nums) {
    int idx = -1;
    // finding pivot index.
    for(int i=nums.size()-2; i>=0; i--){
        if(nums[i]<nums[i+1]){
            idx=i;
            break;
        }
    }
    // reverse if nextPermutation is not possible.
    if(idx==-1){
        reverse(nums.begin(),nums.end());
        // for(int i=0,j=nums.size()-1; i<j; i++,j--){
        //     int temp = nums[i];
        //     nums[i] = nums[j];
        //     nums[j] = temp;
        // }
        return;
    }
    // sorting/reverse indices after pivot.
    reverse(nums.begin()+idx+1, nums.end());
    // for(int m=idx+1,n=nums.size()-1; m<n; m++,n--){
    //     int temp = nums[m];
    //     nums[m] = nums[n];
    //     nums[n] = temp;
    // }
        
    // finding number just bigger than idx.
    int justafteridx;
    for(int i=idx+1; i<nums.size(); i++){
        if(nums[idx]<nums[i]){
            justafteridx = i;
            break;
        }
    }
    // swapping idx with justafteridx
    int temp = nums[idx];
    nums[idx] = nums[justafteridx];
    nums[justafteridx] = temp;
    return;
}

int main(){
    int size;
    cout<<"enter size: ";
    cin>>size;
    vector<int> v;
    cout<<"enter array: ";
    for(int i=0; i<size; i++){
        int q;
        cin>>q;
        v.push_back(q);
    }
    nextPermutation(v);
    cout<<"next permutation: ";
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }
    return 0;
}