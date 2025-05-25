#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        // previous greatest element array.
        int prev[n];
        prev[0] = -1;
        int max = height[0];
        for(int i=1; i<n; i++){
            prev[i] = max;
            if(max<height[i]) max = height[i];
        }
        // next greatest element array -> previous as next as well as minimum.
        prev[n-1] = -1;
        max = height[n-1];
        for(int i=n-2; i>=0; i--){
            if(max<prev[i]) prev[i] = max;
            if(max<height[i]) max = height[i];
        }
        // calculating water.
        int water = 0;
        for(int i=1; i<n-1; i++){
            if(height[i]<prev[i]) water += (prev[i]-height[i]);
        }
        return water;
    }
};

int trap(vector<int>& height) {
    int n = height.size();
    // previous greatest element array.
    int prev[n];
    prev[0] = -1;
    int max = height[0];
    for(int i=1; i<n; i++){
        prev[i] = max;
        if(max<height[i]) max = height[i];
    }
    // next greatest element array.
    int next[n];
    next[n-1] = -1;
    max = height[n-1];
    for(int i=n-2; i>=0; i--){
        next[i] = max;
        if(max<height[i]) max = height[i];
    }
    // minimum array.
    int minimum[n];
    for(int i=0; i<n; i++){
        minimum[i] = min(prev[i],next[i]);
    }
    // calculating water.
    int water = 0;
    for(int i=1; i<n-1; i++){
        if(height[i]<minimum[i]) water += (minimum[i]-height[i]);
    }
    return water;
}

int main(){
    return 0;
}