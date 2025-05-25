class Solution {
public:
    void merge(vector<int> &a, vector<int> &b, vector<int> &res){
        int i=0; // a
        int j=0; // b
        int k=0; // res
        while(i<a.size()&&j<b.size()){
            if(a[i]<=b[j]) res[k++] = a[i++];
            else res[k++] = b[j++];
        }
        if(i==a.size()) while(j<b.size()) res[k++] = b[j++];
        else if(j==b.size()) while(i<a.size()) res[k++] = a[i++];
    }
    void mergeSort(vector<int> &v){
        int n = v.size();
        if(n==1) return;
        int n1 = n/2, n2 = n - n/2;
        vector<int> a(n1), b(n2);
        // copy paste
        for(int i=0; i<n1; i++) a[i] = v[i];
        for(int i=0; i<n2; i++) b[i] = v[i+n1];
        // magic
        mergeSort(a);
        mergeSort(b);
        // merge
        merge(a,b,v);
        // space optimisation
        a.clear(); b.clear();
    }
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums);
        return nums;
    }
};