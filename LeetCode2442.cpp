class Solution {
public:
    int rev(int n){
        int num=0;
        while(n){
            num*=10;
            num += n%10;
            n/=10;
        }
        return num;
    }
    int countDistinctIntegers(vector<int>& nums) {
        int n = nums.size();
        for(int i=0; i<n; i++){
            nums.push_back(rev(nums[i]));
        }
        sort(nums.begin(),nums.end());
        int count=1;
        for(int i=0; i<nums.size()-1; i++){
            if(nums[i]!=nums[i+1]) count++;
        }
        return count;
    }
};

class Solution {
public:
    int rev(int n){
        int num=0;
        while(n){
            num*=10;
            num += n%10;
            n/=10;
        }
        return num;
    }
    int countDistinctIntegers(vector<int>& nums) {
        int n = nums.size();
        for(int i=0; i<n; i++){
            nums.push_back(rev(nums[i]));
        }
        unordered_set<int> s;
        for(int i=0; i<nums.size(); i++){
            s.insert(nums[i]);
        }
        return s.size();
    }
};

class Solution {
public:
    int rev(int n){
        int num=0;
        while(n){num*=10; num += n%10; n/=10;}
        return num;
    }
    int countDistinctIntegers(vector<int>& nums) {
        unordered_set<int> s;
        for(int i=0; i<nums.size(); i++){
            s.insert(nums[i]);
            s.insert(rev(nums[i]));
        }
        return s.size();
    }
};