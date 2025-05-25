class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        for(int i=1; i<nums.size(); i++) nums[i]+=nums[i-1];
        unordered_map<int,int> m; int count=0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==k) count++;
            if(m.find(nums[i]-k)!=m.end()) count+=m[nums[i]-k];
            m[nums[i]]++;
        }
        return count;
    }
};
// same approach can be executed with binary search for element
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count=0, n=nums.size(); long sum;
        for(int i=0; i<n; i++){
            sum = 0;
            for(int j=i; j<n; j++){
                sum+=nums[j];
                if(sum==k) count++;
            }
        }
        return count;
    }
};

class Solution { // also galat
public:
    int subarraySum(vector<int>& nums, int k) {
        for(int i=1; i<nums.size(); i++){
            nums[i]+=nums[i-1];
        }
        unordered_set<int> s;
        int count=0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==k) count++;
            if(s.find(nums[i]-k)!=s.end()) count++;
            s.insert(nums[i]);
        }
        return count;
    }
};
class Solution { // wrong answer works for positive numbers
public:
    int subarraySum(vector<int>& nums, int k) {
        if(k==0) return 0;
        for(int i=1; i<nums.size(); i++){
            nums[i]+=nums[i-1];
        }
        unordered_set<int> s;
        for(int i=0; i<nums.size(); i++) s.insert(nums[i]);
        int count=0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==k) count++;
            else if(nums[i]>k){
                if(s.find(nums[i]-k)!=s.end()) count++;
            }
        }
        return count;
    }
};
class Solution { // same as above
public:
    int subarraySum(vector<int>& nums, int k) {
        for(int i=1; i<nums.size(); i++){
            nums[i]+=nums[i-1];
        }
        unordered_set<int> s;
        int count=0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==k) count++;
            else if(nums[i]>k){
                if(s.find(nums[i]-k)!=s.end()) count++;
            }
            s.insert(nums[i]);
        }
        return count;
    }
};