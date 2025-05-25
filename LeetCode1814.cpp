class Solution {
public:
    int rev(int x) {
        int num = 0;
        while(x){
            num*=10;
            num+=(x%10);
            x/=10;
        }
        return num;
    }
    int countNicePairs(vector<int>& nums) {
        for(int i=0; i<nums.size(); i++){
            nums[i] = nums[i]-rev(nums[i]);
        }
        unordered_map<int,int> m; long long count=0; int mod = 1e9+7;
        for(int i=0; i<nums.size(); i++){
            if(m.find(nums[i])!=m.end()){
                count+=m[nums[i]];
                m[nums[i]]++;
            }
            else m[nums[i]]++;
        }
        return count%=mod;
    }
};

class Solution {
public:
    int rev(int x) {
        int num = 0;
        while(x){
            num*=10;
            num+=(x%10);
            x/=10;
        }
        return num;
    }
    int fact(int num){
        int a = 1;
        for(int i=2; i<=num; i++) a*=i;
        return a;
    }
    int nCr(int n, int r){
        return fact(n)/(fact(r)*fact(n-r));
    }
    int countNicePairs(vector<int>& nums) {
        for(int i=0; i<nums.size(); i++){
            nums[i] = nums[i]-rev(nums[i]);
        }
        unordered_map<int,int> m; int count=0;
        for(int i=0; i<nums.size(); i++) m[nums[i]]++;
        for(auto x : m){
            int f  = x.second;
            count += nCr(f,2);
        }
        return count;
    }
};

class Solution {
public:
    int rev(int x) {
        long long num = 0;
        while(x){
            num*=10;
            num+=(x%10);
            x/=10;
        }
        if(num>INT_MAX || num<INT_MIN) return 0;
        else return (int)num;
    }
    int countNicePairs(vector<int>& nums) {
        int count=0;
        for(int i=0; i<nums.size()-1; i++){
            for(int j=i+1; j<nums.size(); j++){
                if(nums[i]+rev(nums[j])==nums[j]+rev(nums[i])) count++;
            }
        }
        return count;
    }
};