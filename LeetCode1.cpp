class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> m;
        for(int i=0; i<nums.size(); i++){
            int n = target-nums[i];
            if(m.find(n)!=m.end()) return{i,m[n]};
            else m[nums[i]]=i;
        }
        return {};
    }
};

#include<iostream>
#include<vector>
using namespace std;
int main(){
    int size;
    cout<<"enter the size of your array here: ";
    cin>>size;
    cout<<"enter your array here: ";
    vector<int> v;
    for(int i=0; i<size; i++){
        int temp;
        cin>>temp;
        v.push_back(temp);
    }
    int target;
    cout<<"enter your target value here: ";
    cin>>target;
    // for(int i=0; i<size-1; i++){
    //     int num1 = v[i];
    //     int num2 = target - num1;
    //     for(int j=i+1; j<size; j++){
    //         if(v[j]==num2) cout<<"["<<i<<","<<j<<"]";
    //     }
    // }
    for(int i=0; i<size-1; i++){
        for(int j=i+1; j<size; j++){
            if(v[i]+v[j]==target) cout<<"["<<i<<","<<j<<"]";
        }
    }
    return 0;
}