class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int,int> m;
        for(int i=0; i<arr.size(); i++){
            arr[i]%=k;
            if(arr[i]<0) arr[i]+=k;
            m[arr[i]]++;
        }
        if(m.find(0)!=m.end()){
            if(m[0]%2!=0) return false;
            m.erase(0);
        }
        for(auto x : m){
            int ele = x.first;
            int rem = k-ele;
            if(m.find(rem)==m.end()) return false;
            else if(m[ele]!=m[rem]) return false;
        }
        return true;
    }
};
// -a%b = -(a%b)
// a%-b = a%b