class Solution {
public:
    void reversePart(vector<int> &nums, int i, int j){
        while(i<=j){
            swap(nums[i],nums[j]);
            i++;
            j--;
        }
    return;
    }
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if(k>n) k = k%n;
        reversePart(nums,0,n-1-k);
        reversePart(nums,n-k,n-1);
        reversePart(nums,0,n-1);
        return;
    }
};

#include<iostream>
#include<vector>
using namespace std;
void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
    return;
}
void reverse(vector<int> &v){
    int i = 0, j = v.size()-1;
    while(i<=j){
        swap(&v[i],&v[j]);
        i++;
        j--;
    }
    return;
}
void reversePart(vector<int> &v, int i, int j){
    while(i<=j){
        swap(&v[i],&v[j]);
        i++;
        j--;
    }
    return;
}
int main(){
    int size;
    cout<<"enter size; ";
    cin>>size;
    vector<int> v;
    cout<<"enter array: ";
    for(int i=0; i<size; i++){
        int q;
        cin>>q;
        v.push_back(q);
    }
    int k;
    cout<<"enter no. of steps: ";
    cin>>k;

    for(int i=1; i<=k; i++){
        reverse(v);
        reversePart(v,1,size-1);
    }

    // if(k>size) k = k%size;
    // reversePart(v,0,size-1-k);
    // reversePart(v,size-k,size-1);
    // reverse(v);

    cout<<"rotated array: ";
    for(int i=0; i<size; i++){
        cout<<v[i]<<" ";
    }
    return 0;
}